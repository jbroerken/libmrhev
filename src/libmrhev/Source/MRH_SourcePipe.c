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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

// External

// Project
#include "./MRH_SourcePipe.h"
#include "../Error/MRH_EventQueueErrorInternal.h"


//*************************************************************************************
// Open
//*************************************************************************************

MRH_SourcePipe* MRH_OpenPipe(int i_FD)
{
    if (i_FD < 0)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_SOURCE_PIPE, __LINE__);
        return NULL;
    }
    
    MRH_SourcePipe* p_Pipe = (MRH_SourcePipe*)malloc(sizeof(MRH_SourcePipe));
    
    if (p_Pipe == NULL)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_MALLOC, MRH_EV_ERROR_FILE_SOURCE_PIPE, __LINE__);
        return NULL;
    }
    
    p_Pipe->i_FD = i_FD;
    p_Pipe->s_PollFD.fd = i_FD;
    
    return p_Pipe;
}

//*************************************************************************************
// Poll
//*************************************************************************************

int MRH_PollPipe(MRH_SourcePipe* p_Pipe, int i_Event, int i_TimeoutMS)
{
    if (i_TimeoutMS < 0)
    {
        i_TimeoutMS = 0;
    }
    
    p_Pipe->s_PollFD.events = i_Event;
    
    switch (poll(&(p_Pipe->s_PollFD), 1, i_TimeoutMS))
    {
        case -1:
            MRH_SetEventQueueError(MRH_EV_ERROR_PIPE_POLL, MRH_EV_ERROR_FILE_SOURCE_PIPE, __LINE__);
        case 0:
            return -1;
            
        default:
            return (p_Pipe->s_PollFD.revents & i_Event) ? 0 : -1;
    }
}

//*************************************************************************************
// Read
//*************************************************************************************

ssize_t MRH_ReadPipe(MRH_SourcePipe* p_Pipe, MRH_Uint8* p_Data, MRH_Uint32 u32_Length)
{
    if (p_Pipe == NULL || p_Pipe->i_FD < 0 || p_Data == NULL || u32_Length == 0)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_SOURCE_PIPE, __LINE__);
        return -1;
    }
    
    ssize_t ss_Read;
    
    if ((ss_Read = read(p_Pipe->i_FD, p_Data, u32_Length)) < 0)
    {
        switch (errno)
        {
            case EAGAIN:
                ss_Read = 0;
                break;
                
            default:
                MRH_SetEventQueueError(MRH_EV_ERROR_PIPE_READ, MRH_EV_ERROR_FILE_SOURCE_PIPE, __LINE__);
                break;
        }
    }
    
    return ss_Read;
}

//*************************************************************************************
// Write
//*************************************************************************************

ssize_t MRH_WritePipe(MRH_SourcePipe* p_Pipe, const MRH_Uint8* p_Data, MRH_Uint32 u32_Length)
{
    if (p_Pipe == NULL || p_Pipe->i_FD < 0 || p_Data == NULL || u32_Length == 0)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_SOURCE_PIPE, __LINE__);
        return -1;
    }
    
    ssize_t ss_Write;
    
    if ((ss_Write = write(p_Pipe->i_FD, p_Data, u32_Length)) < 0)
    {
        switch (errno)
        {
            case EAGAIN:
                ss_Write = 0;
                break;
                
            default:
                MRH_SetEventQueueError(MRH_EV_ERROR_PIPE_WRITE, MRH_EV_ERROR_FILE_SOURCE_PIPE, __LINE__);
                break;
        }
    }
    
    return ss_Write;
}

//*************************************************************************************
// Close
//*************************************************************************************

MRH_SourcePipe* MRH_ClosePipe(MRH_SourcePipe* p_Pipe)
{
    if (p_Pipe == NULL)
    {
        MRH_SetEventQueueError(MRH_EV_ERROR_GENERAL_INVALID_PARAM, MRH_EV_ERROR_FILE_SOURCE_PIPE, __LINE__);
        return NULL;
    }
    
    if (p_Pipe->i_FD < 0)
    {
        if (close(p_Pipe->i_FD) < 0)
        {
            MRH_SetEventQueueError(MRH_EV_ERROR_PIPE_CLOSE_FD, MRH_EV_ERROR_FILE_SOURCE_PIPE, __LINE__);
        }
    }
    
    free(p_Pipe);
    
    return NULL;
}
