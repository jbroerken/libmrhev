/**
 *  MRH_EventQueueError.c
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

// External

// Project
#include "./MRH_EventQueueErrorInternal.h"


//*************************************************************************************
// Error Data
//*************************************************************************************

// Last error
static MRH_EV_Error_Type e_LastEventQueueError = MRH_EV_ERROR_NONE;
static MRH_EV_Error_File e_LastEventQueueFile = MRH_EV_ERROR_FILE_NONE;
static size_t us_LastEventQueueFileLine = 0;

//*************************************************************************************
// Reset
//*************************************************************************************

void MRH_ResetEventQueueError(void)
{
    e_LastEventQueueError = MRH_EV_ERROR_NONE;
}

//*************************************************************************************
// Getters
//*************************************************************************************

MRH_EV_Error_Type MRH_GetEventQueueError(void)
{
    return e_LastEventQueueError;
}

const char* MRH_GetEventQueueErrorString(void)
{
    switch (e_LastEventQueueError)
    {
        // None
        case MRH_EV_ERROR_NONE:
            return "No error";
            
        // General
        case MRH_EV_ERROR_GENERAL_INVALID_PARAM:
            return "Invalid parameters";
        case MRH_EV_ERROR_GENERAL_MALLOC:
            return "Memory allocation failed";
        case MRH_EV_ERROR_GENERAL_FREE:
            return "Memory deallocation failed";
        case MRH_EV_ERROR_GENERAL_SOURCE_OPEN:
            return "Queue source is already open";
        case MRH_EV_ERROR_GENERAL_SOURCE_CLOSED:
            return "Queue source is already closed";
            
        // MRHCKM
        // TODO: Errors!
            
        // Pipe
        case MRH_EV_ERROR_PIPE_CLOSE_FD:
            return "Failed to close pipe file descriptor";
        case MRH_EV_ERROR_PIPE_POLL:
            return "Failed to poll pipe, check errno";
        case MRH_EV_ERROR_PIPE_READ:
            return "Failed to read pipe, check errno";
        case MRH_EV_ERROR_PIPE_WRITE:
            return "Failed to write pipe, check errno";
            
        default:
            return NULL;
    }
}

const char* MRH_GetEventQueueErrorFile(void)
{
    switch (e_LastEventQueueFile)
    {
        // Default
        case MRH_EV_ERROR_FILE_NONE:
            return "<No File>";
            
        // libmrhev/Error dir
        case MRH_EV_ERROR_FILE_ERROR:
            return "libmrhev/Error/MRH_EventQueueError.c";
            
        // libmrhev/Source dir
        case MRH_EV_ERROR_FILE_SOURCE_MRHCKM:
            return "libmrhev/Source/MRH_SourceMRHCKM.c";
        case MRH_EV_ERROR_FILE_SOURCE_PIPE:
            return "libmrhev/Source/MRH_SourcePipe.c";
            
        // libmrhev dir
        case MRH_EV_ERROR_FILE_QUEUE_UPDATE_MRHCKM:
            return "libmrhev/MRH_QueueUpdateMRHCKM.c";
        case MRH_EV_ERROR_FILE_QUEUE_UPDATE_PIPE:
            return "libmrhev/MRH_QueueUpdatePipe.c";
            
        // Root dir
        case MRH_EV_ERROR_FILE_LIBMRHEV:
            return "libmrhev.c";
            
        default:
            return NULL;
    }
}

size_t MRH_GetEventQueueErrorFileLine(void)
{
    return us_LastEventQueueFileLine;
}

//*************************************************************************************
// Setters
//*************************************************************************************

void MRH_SetEventQueueError(MRH_EV_Error_Type e_Error, MRH_EV_Error_File e_File, size_t us_Line)
{
    e_LastEventQueueError = e_Error;
    e_LastEventQueueFile = e_File;
    us_LastEventQueueFileLine = us_Line;
}
