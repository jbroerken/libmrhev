/**
 *  Copyright (C) 2021 - 2022 The MRH Project Authors.
 * 
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

// C
#include <stdlib.h>

// External

// Project
#include "MRH_QueueUpdatePipe.h"
#include "./Source/MRH_SourcePipe.h"
#include "./Error/MRH_EventQueueErrorInternal.h"


//*************************************************************************************
// Open
//*************************************************************************************

int MRH_OpenQueueSourcePipe(struct MRH_EventQueue_t* p_EventQueue, int i_FD)
{
    if (p_EventQueue->p_Source != NULL)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_SOURCE_OPEN, MRH_EV_ERROR_FILE_QUEUE_UPDATE_PIPE, __LINE__);
        return -1;
    }
    else if ((p_EventQueue->p_Source = MRH_OpenPipe(i_FD)) == NULL)
    {
        // Keep pipe error
        return -1;
    }
    
    p_EventQueue->e_TransmissionMethod = MRH_TRANSMISSION_METHOD_PIPE;
    
    return 0;
}

//*************************************************************************************
// Update
//*************************************************************************************

static int UpdateTransmissionData(struct MRH_EventQueue_t* p_EventQueue, ssize_t ss_Processed, MRH_Uint32 u32_Required, MRH_TransmissionData e_NextData)
{
    // Process error
    if (ss_Processed < 0)
    {
        return -1;
    }
    
    if ((p_EventQueue->u32_BytesProcessed += ss_Processed) >= u32_Required)
    {
        p_EventQueue->e_TransmissionData = e_NextData;
        p_EventQueue->u32_BytesProcessed = 0;
        
        return 0;
    }
    
    return -1;
}

//*************************************************************************************
// Recieve
//*************************************************************************************

MRH_TransmissionState MRH_RecieveCurrentEventPipe(struct MRH_EventQueue_t* p_EventQueue, int i_TimeoutMS)
{
    // Poll pipe for data
    if (MRH_PollPipe(p_EventQueue->p_Source, POLLIN, i_TimeoutMS) < 0)
    {
        return MRH_TRANSMISSION_STATE_FAILED;
    }
    
    ssize_t ss_Read;
    MRH_Uint32 u32_TotalSize;
    MRH_TransmissionData e_NextData;
    
    // Send data matching to the transmission state
    switch (p_EventQueue->e_TransmissionData)
    {
        case MRH_TRANSMISSION_DATA_GROUP:
            e_NextData = MRH_TRANSMISSION_DATA_TYPE;
            u32_TotalSize = sizeof(p_EventQueue->p_Current->u32_Type);
            ss_Read = MRH_ReadPipe(p_EventQueue->p_Source,
                                   (MRH_Uint8*)(&(p_EventQueue->p_Current->u32_GroupID) + p_EventQueue->u32_BytesProcessed),
                                   u32_TotalSize - p_EventQueue->u32_BytesProcessed);
            break;
        case MRH_TRANSMISSION_DATA_TYPE:
            e_NextData = MRH_TRANSMISSION_DATA_DATA_SIZE;
            u32_TotalSize = sizeof(p_EventQueue->p_Current->u32_Type);
            ss_Read = MRH_ReadPipe(p_EventQueue->p_Source,
                                   (MRH_Uint8*)(&(p_EventQueue->p_Current->u32_Type) + p_EventQueue->u32_BytesProcessed),
                                   u32_TotalSize - p_EventQueue->u32_BytesProcessed);
            break;
        case MRH_TRANSMISSION_DATA_DATA_SIZE:
            u32_TotalSize = sizeof(p_EventQueue->p_Current->u32_DataSize);
            ss_Read = MRH_ReadPipe(p_EventQueue->p_Source,
                                   (MRH_Uint8*)(&(p_EventQueue->p_Current->u32_DataSize) + p_EventQueue->u32_BytesProcessed),
                                   u32_TotalSize - p_EventQueue->u32_BytesProcessed);
            
            // Skip data read on no data
            if (p_EventQueue->p_Current->u32_DataSize == 0)
            {
                p_EventQueue->p_Current->p_Data = NULL;
                e_NextData = MRH_TRANSMISSION_DATA_FINISHED;
            }
            else
            {
                e_NextData = MRH_TRANSMISSION_DATA_DATA;
            }
            break;
        case MRH_TRANSMISSION_DATA_DATA:
            // Allocate
            if ((p_EventQueue->p_Current->p_Data = (MRH_Uint8*)malloc(p_EventQueue->p_Current->u32_DataSize)) == NULL)
            {
                MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_MALLOC, MRH_EV_ERROR_FILE_QUEUE_UPDATE_PIPE, __LINE__);
                return -1;
            }
            
            e_NextData = MRH_TRANSMISSION_DATA_FINISHED;
            u32_TotalSize = p_EventQueue->p_Current->u32_DataSize;
            ss_Read = MRH_ReadPipe(p_EventQueue->p_Source,
                                   &(p_EventQueue->p_Current->p_Data[p_EventQueue->u32_BytesProcessed]),
                                   u32_TotalSize - p_EventQueue->u32_BytesProcessed);
            break;
        case MRH_TRANSMISSION_DATA_FINISHED:
            // We run this once, always causes continue
            // It is required for the user to see that the event finished transmitting
            e_NextData = MRH_TRANSMISSION_DATA_GROUP;
            u32_TotalSize = 0;
            ss_Read = 0; // Always correct with total size set
            break;
            
        default:
            return -1;
    }
    
    // Update transmission state
    if (UpdateTransmissionData(p_EventQueue, ss_Read, u32_TotalSize, e_NextData) < 0)
    {
        return MRH_TRANSMISSION_STATE_FAILED;
    }
    
    return (p_EventQueue->e_TransmissionData == MRH_TRANSMISSION_DATA_FINISHED ? MRH_TRANSMISSION_STATE_COMPLETED : MRH_TRANSMISSION_STATE_CONTINUE);
}

//*************************************************************************************
// Send
//*************************************************************************************

MRH_TransmissionState MRH_SendCurrentEventPipe(struct MRH_EventQueue_t* p_EventQueue)
{
    ssize_t ss_Written;
    MRH_Uint32 u32_TotalSize;
    MRH_TransmissionData e_NextData;
    
    // Send data matching to the transmission state
    switch (p_EventQueue->e_TransmissionData)
    {
        case MRH_TRANSMISSION_DATA_GROUP:
            e_NextData = MRH_TRANSMISSION_DATA_TYPE;
            u32_TotalSize = sizeof(p_EventQueue->p_Current->u32_Type);
            ss_Written = MRH_WritePipe(p_EventQueue->p_Source,
                                       (const MRH_Uint8*)(&(p_EventQueue->p_Current->u32_GroupID) + p_EventQueue->u32_BytesProcessed),
                                       u32_TotalSize - p_EventQueue->u32_BytesProcessed);
            break;
        case MRH_TRANSMISSION_DATA_TYPE:
            e_NextData = MRH_TRANSMISSION_DATA_DATA_SIZE;
            u32_TotalSize = sizeof(p_EventQueue->p_Current->u32_Type);
            ss_Written = MRH_WritePipe(p_EventQueue->p_Source,
                                       (const MRH_Uint8*)(&(p_EventQueue->p_Current->u32_Type) + p_EventQueue->u32_BytesProcessed),
                                       u32_TotalSize - p_EventQueue->u32_BytesProcessed);
            break;
        case MRH_TRANSMISSION_DATA_DATA_SIZE:
            // Skip data write on no data
            if (p_EventQueue->p_Current->u32_DataSize == 0)
            {
                e_NextData = MRH_TRANSMISSION_DATA_FINISHED;
            }
            else
            {
                e_NextData = MRH_TRANSMISSION_DATA_DATA;
            }
            
            u32_TotalSize = sizeof(p_EventQueue->p_Current->u32_DataSize);
            ss_Written = MRH_WritePipe(p_EventQueue->p_Source,
                                       (const MRH_Uint8*)(&(p_EventQueue->p_Current->u32_DataSize) + p_EventQueue->u32_BytesProcessed),
                                       u32_TotalSize - p_EventQueue->u32_BytesProcessed);
            break;
        case MRH_TRANSMISSION_DATA_DATA:
            e_NextData = MRH_TRANSMISSION_DATA_FINISHED;
            u32_TotalSize = p_EventQueue->p_Current->u32_DataSize;
            ss_Written = MRH_WritePipe(p_EventQueue->p_Source,
                                       &(p_EventQueue->p_Current->p_Data[p_EventQueue->u32_BytesProcessed]),
                                       u32_TotalSize - p_EventQueue->u32_BytesProcessed);
            break;
        case MRH_TRANSMISSION_DATA_FINISHED:
            // We run this once, always causes continue
            // It is required for the user to see that the event finished transmitting
            e_NextData = MRH_TRANSMISSION_DATA_GROUP;
            u32_TotalSize = 0;
            ss_Written = 0; // Always correct with total size set
            break;
            
        default:
            return -1;
    }
    
    // Update transmission state
    if (UpdateTransmissionData(p_EventQueue, ss_Written, u32_TotalSize, e_NextData) < 0)
    {
        return MRH_TRANSMISSION_STATE_FAILED;
    }
    
    return (p_EventQueue->e_TransmissionData == MRH_TRANSMISSION_DATA_FINISHED ? MRH_TRANSMISSION_STATE_COMPLETED : MRH_TRANSMISSION_STATE_CONTINUE);
}

//*************************************************************************************
// Close
//*************************************************************************************

void MRH_CloseQueueSourcePipe(struct MRH_EventQueue_t* p_EventQueue)
{
    if (p_EventQueue->p_Source == NULL)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_SOURCE_CLOSED, MRH_EV_ERROR_FILE_QUEUE_UPDATE_PIPE, __LINE__);
    }
    
    p_EventQueue->e_TransmissionMethod = MRH_TRANSMISSION_METHOD_UNK;
    p_EventQueue->p_Source = MRH_ClosePipe(p_EventQueue->p_Source);
}
