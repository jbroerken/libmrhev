/**
 *  MRH_SourcePipe.c
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
