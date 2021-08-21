/**
 *  libmrhev.c
 *
 *  This file is part of the MRH project.
 *  See the AUTHORS file for Copyright information.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

// C
#include <stdlib.h>

// External

// Project
#include "../include/libmrhev/libmrhev.h"
#ifdef __MRH_MRHCKM_SUPPORTED__
#include "./libmrhev/MRH_QueueUpdateMRHCKM.h"
#endif
#include "./libmrhev/MRH_QueueUpdatePipe.h"
#include "./libmrhev/Error/MRH_EventQueueErrorInternal.h"


//*************************************************************************************
// Open
//*************************************************************************************

static MRH_EventQueue* MRH_OpenEventQueueGeneric(MRH_QueueType e_Type, MRH_Uint32 u32_EventLimit)
{
    MRH_EventQueue* p_EventQueue = (MRH_EventQueue*)malloc(sizeof(MRH_EventQueue));
        
    if (p_EventQueue == NULL)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_MALLOC, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
        return NULL;
    }
        
    p_EventQueue->e_QueueType = e_Type;
    
    p_EventQueue->e_TransmissionState = MRH_TRANSMISSION_STATE_COMPLETED;
    p_EventQueue->e_TransmissionData = MRH_TRANSMISSION_DATA_GROUP;
    p_EventQueue->p_Current = NULL;
    p_EventQueue->u32_BytesProcessed = 0;
        
    p_EventQueue->p_First = NULL;
    p_EventQueue->p_End = NULL;
    
    p_EventQueue->e_TransmissionMethod = MRH_TRANSMISSION_METHOD_UNK;
    p_EventQueue->p_Source = NULL;
    
    switch (e_Type)
    {
        case MRH_QUEUE_TYPE_INPUT:
            p_EventQueue->u32_SendLimit = ((MRH_Uint32) - 1);
            p_EventQueue->u32_RecieveLimit = u32_EventLimit;
            break;
        case MRH_QUEUE_TYPE_OUTPUT:
            p_EventQueue->u32_SendLimit = u32_EventLimit;
            p_EventQueue->u32_RecieveLimit = ((MRH_Uint32) - 1);
            break;
            
        default:
            p_EventQueue->u32_SendLimit = ((MRH_Uint32) - 1);
            p_EventQueue->u32_RecieveLimit = ((MRH_Uint32) - 1);
            break;
    }
        
    return p_EventQueue;
}

#ifdef __MRH_MRHCKM_SUPPORTED__
static MRH_EventQueue* MRH_OpenEventQueueMRHCKM(const char* p_Path, int i_Key, MRH_QueueType e_Type, MRH_Uint32 u32_EventLimit)
{
    MRH_EventQueue* p_EventQueue = MRH_OpenEventQueueGeneric(e_Type, u32_EventLimit);
    
    if (p_EventQueue != NULL && MRH_OpenQueueSourceMRHCKM(p_EventQueue, p_Path, i_Key) < 0)
    {
        return MRH_CloseEventQueue(p_EventQueue);
    }
    
    return p_EventQueue;
}

MRH_InputEventQueue* MRH_OpenInputQueueMRHCKM(const char* p_Path, int i_Key, MRH_Uint32 u32_RecieveLimit)
{
    return MRH_OpenEventQueueMRHCKM(p_Path, i_Key, MRH_QUEUE_TYPE_INPUT, u32_RecieveLimit);
}

MRH_OutputEventQueue* MRH_OpenOutputQueueMRHCKM(const char* p_Path, int i_Key, MRH_Uint32 u32_SendLimit)
{
    return MRH_OpenEventQueueMRHCKM(p_Path, i_Key, MRH_QUEUE_TYPE_OUTPUT, u32_SendLimit);
}
#endif

static MRH_EventQueue* MRH_OpenEventQueuePipe(int i_FD, MRH_QueueType e_Type, MRH_Uint32 u32_EventLimit)
{
    MRH_EventQueue* p_EventQueue = MRH_OpenEventQueueGeneric(e_Type, u32_EventLimit);
    
    if (p_EventQueue != NULL && MRH_OpenQueueSourcePipe(p_EventQueue, i_FD) < 0)
    {
        return MRH_CloseEventQueue(p_EventQueue);
    }
    
    return p_EventQueue;
}

MRH_InputEventQueue* MRH_OpenInputQueuePipe(int i_FD, MRH_Uint32 u32_RecieveLimit)
{
    return MRH_OpenEventQueuePipe(i_FD, MRH_QUEUE_TYPE_INPUT, u32_RecieveLimit);
}

MRH_OutputEventQueue* MRH_OpenOutputQueuePipe(int i_FD, MRH_Uint32 u32_SendLimit)
{
    return MRH_OpenEventQueuePipe(i_FD, MRH_QUEUE_TYPE_OUTPUT, u32_SendLimit);
}

//*************************************************************************************
// List
//*************************************************************************************

static MRH_Event* MRH_ListPopFront(MRH_EventQueue* p_EventQueue)
{
    if (p_EventQueue->p_First == NULL)
    {
        return NULL;
    }
    
    MRH_EventList* p_Current = p_EventQueue->p_First;
    MRH_Event* p_Event = p_Current->p_Event;
    
    // Empty list
    if ((p_EventQueue->p_First = p_Current->p_Next) == NULL)
    {
        p_EventQueue->p_End = NULL;
    }
    
    free(p_Current);
    
    return p_Event;
}

static void MRH_ListPushBack(MRH_EventQueue* p_EventQueue, MRH_Event** p_Event)
{
    MRH_EventList* p_End = (MRH_EventList*)malloc(sizeof(MRH_EventList));
    
    if (p_End == NULL)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_MALLOC, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
        return;
    }
    
    p_End->p_Event = *p_Event;
    p_End->p_Next = NULL;
    
    // Add to required positions
    if (p_EventQueue->p_End == NULL)
    {
        p_EventQueue->p_First = p_End;
    }
    else
    {
        p_EventQueue->p_End->p_Next = p_End;
    }
    
    p_EventQueue->p_End = p_End;
    *p_Event = NULL;
}

//*************************************************************************************
// Recieve
//*************************************************************************************

MRH_Uint32 MRH_RecieveEvents(MRH_InputEventQueue* p_EventQueue, int i_TimeoutMS)
{
    if (p_EventQueue == NULL || p_EventQueue->e_QueueType != MRH_QUEUE_TYPE_INPUT)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
        return 0;
    }
    
    MRH_Uint32 u32_Recieved = 0;
    
    while (u32_Recieved < p_EventQueue->u32_RecieveLimit)
    {
        // Create new
        if (p_EventQueue->p_Current == NULL)
        {
            if ((p_EventQueue->p_Current = (MRH_Event*)malloc(sizeof(MRH_Event))) == NULL)
            {
                MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_MALLOC, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
                return u32_Recieved;
            }
            
            // In case queue destruction happens before read updates this
            p_EventQueue->p_Current->u32_DataSize = 0;
            p_EventQueue->p_Current->p_Data = NULL;
        }
        
        // Read current event
        do
        {
            switch (p_EventQueue->e_TransmissionMethod)
            {
#ifdef __MRH_MRHCKM_SUPPORTED__
                case MRH_TRANSMISSION_METHOD_MRHCKM:
                    if (MRH_RecieveCurrentEventMRHCKM(p_EventQueue, i_TimeoutMS) == MRH_TRANSMISSION_STATE_FAILED)
                    {
                        return u32_Recieved;
                    }
                    break;
#endif
                case MRH_TRANSMISSION_METHOD_PIPE:
                    if (MRH_RecieveCurrentEventPipe(p_EventQueue, i_TimeoutMS) == MRH_TRANSMISSION_STATE_FAILED)
                    {
                        return u32_Recieved;
                    }
                    break;
                                        
                default:
                    return u32_Recieved;
            }
        }
        while (p_EventQueue->e_TransmissionData != MRH_TRANSMISSION_DATA_FINISHED);
        
        // Add to list
        MRH_ListPushBack(p_EventQueue, &(p_EventQueue->p_Current));
        p_EventQueue->p_Current = NULL;
        
        ++u32_Recieved;
    }
    
    return u32_Recieved;
}

MRH_Event* MRH_GetEvent(MRH_InputEventQueue* p_EventQueue)
{
    if (p_EventQueue == NULL || p_EventQueue->e_QueueType != MRH_QUEUE_TYPE_INPUT)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
        return NULL;
    }
    
    return MRH_ListPopFront(p_EventQueue);
}

//*************************************************************************************
// Send
//*************************************************************************************

MRH_Uint32 MRH_SendEvents(MRH_OutputEventQueue* p_EventQueue)
{
    if (p_EventQueue == NULL || p_EventQueue->e_QueueType != MRH_QUEUE_TYPE_OUTPUT)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
        return 0;
    }
    
    MRH_Uint32 u32_Sent = 0;
    
    while (p_EventQueue->p_Current != NULL || (p_EventQueue->p_Current = MRH_ListPopFront(p_EventQueue)) != NULL)
    {
        // Write current event
        do
        {
            switch (p_EventQueue->e_TransmissionMethod)
            {
#ifdef __MRH_MRHCKM_SUPPORTED__
                case MRH_TRANSMISSION_METHOD_MRHCKM:
                    if (MRH_SendCurrentEventMRHCKM(p_EventQueue) == MRH_TRANSMISSION_STATE_FAILED)
                    {
                        return u32_Sent;
                    }
                    break;
#endif
                case MRH_TRANSMISSION_METHOD_PIPE:
                    if (MRH_SendCurrentEventPipe(p_EventQueue) == MRH_TRANSMISSION_STATE_FAILED)
                    {
                        return u32_Sent;
                    }
                    break;
                                
                default:
                    return u32_Sent;
            }
        }
        while (p_EventQueue->e_TransmissionData != MRH_TRANSMISSION_DATA_FINISHED);
        
        // Remove the now sent event
        if (p_EventQueue->p_Current->p_Data != NULL)
        {
            free(p_EventQueue->p_Current->p_Data);
        }
        
        free(p_EventQueue->p_Current);
        p_EventQueue->p_Current = NULL;
        
        ++u32_Sent;
    }
    
    return u32_Sent;
}

MRH_Event* MRH_AddEvent(MRH_OutputEventQueue* p_EventQueue, MRH_Event** p_Event)
{
    if (p_Event == NULL || *p_Event == NULL)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
        return NULL;
    }
    else if (p_EventQueue == NULL || p_EventQueue->e_QueueType != MRH_QUEUE_TYPE_OUTPUT)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
        return *p_Event;
    }
    
    MRH_ListPushBack(p_EventQueue, p_Event);
    
    return *p_Event;
}

int MRH_CanSendEvents(MRH_OutputEventQueue* p_EventQueue)
{
    if (p_EventQueue == NULL || p_EventQueue->e_QueueType != MRH_QUEUE_TYPE_OUTPUT)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
        return -1;
    }
    
    // List exists or last event not fully written
    if (p_EventQueue->p_First != NULL || p_EventQueue->p_Current != NULL)
    {
        return 0;
    }
    
    return -1;
}

//*************************************************************************************
// Close
//*************************************************************************************

MRH_EventQueue* MRH_CloseEventQueue(MRH_EventQueue* p_EventQueue)
{
    if (p_EventQueue == NULL)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
        return NULL;
    }
    
    // Remove current event
    if (p_EventQueue->p_Current != NULL)
    {
        if (p_EventQueue->p_Current->p_Data != NULL)
        {
            free(p_EventQueue->p_Current->p_Data);
        }
        
        free(p_EventQueue->p_Current);
    }
    
    // Remove event list
    MRH_EventList* p_Current;
    MRH_EventList* p_Next = p_EventQueue->p_First;
    
    while ((p_Current = p_Next) != NULL)
    {
        p_Next = p_Next->p_Next;
        
        if (p_Current->p_Event != NULL)
        {
            if (p_Current->p_Event->p_Data != NULL)
            {
                free(p_Current->p_Event->p_Data);
            }
            
            free(p_Current->p_Event);
        }
        
        free(p_Current);
    }
    
    // Remove source
    if (p_EventQueue->p_Source != NULL)
    {
        switch (p_EventQueue->e_TransmissionMethod)
        {
#ifdef __MRH_MRHCKM_SUPPORTED__
            case MRH_TRANSMISSION_METHOD_MRHCKM:
                MRH_CloseQueueSourceMRHCKM(p_EventQueue);
                break;
#endif
            case MRH_TRANSMISSION_METHOD_PIPE:
                MRH_CloseQueueSourcePipe(p_EventQueue);
                break;
                
            default:
                MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_FREE, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
                break;
        }
    }
    
    return NULL;
}

//*************************************************************************************
// Getters
//*************************************************************************************

MRH_Uint32 MRH_GetEventQueueEventCount(MRH_EventQueue* p_EventQueue)
{
    if (p_EventQueue == NULL)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_LIBMRHEV, __LINE__);
        return 0;
    }
    
    MRH_EventList* p_Current = p_EventQueue->p_First;
    MRH_Uint32 u32_Count = 0;
    
    while (p_Current != NULL)
    {
        ++u32_Count;
        p_Current = p_Current->p_Next;
    }
    
    return u32_Count;
}
