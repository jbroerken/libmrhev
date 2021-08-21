/**
 *  MRH_EventQueueError.h
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

#ifndef MRH_EventQueueError_h
#define MRH_EventQueueError_h

// C
#include <stddef.h>

// External

// Project


#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Types
    //*************************************************************************************

    typedef enum
    {
        // None
        MRH_EV_ERROR_NONE = -1,
        
        // General
        MRH_EV_ERROR_GENERAL_INVALID_PARAM = 0,
        MRH_EV_ERROR_GENERAL_MALLOC = 1,
        MRH_EV_ERROR_GENERAL_FREE = 2,
        MRH_EV_ERROR_GENERAL_SOURCE_OPEN = 3,
        MRH_EV_ERROR_GENERAL_SOURCE_CLOSED = 4,
        
        // MRHCKM
        // @TODO: Errors!
        
        // Pipe
        MRH_EV_ERROR_PIPE_CLOSE_FD,
        MRH_EV_ERROR_PIPE_POLL,
        MRH_EV_ERROR_PIPE_READ,
        MRH_EV_ERROR_PIPE_WRITE,
        
        // Bounds
        MRH_EV_ERROR_TYPE_MAX = MRH_EV_ERROR_PIPE_WRITE,

        MRH_EV_ERROR_TYPE_COUNT = MRH_EV_ERROR_TYPE_MAX + 1

    }MRH_EV_Error_Type;

    //*************************************************************************************
    // Reset
    //*************************************************************************************

    /**
     *  Reset the last error.
     */

    extern void MRH_ResetEventQueueError(void);

    //*************************************************************************************
    // Getters
    //*************************************************************************************

    /**
     *  Get the current library error.
     *
     *  \return The current library error.
     */

    extern MRH_EV_Error_Type MRH_GetEventQueueError(void);

    /**
     *  Get the current library error string.
     *
     *  \return The current library error string.
     */

    extern const char* MRH_GetEventQueueErrorString(void);

    /**
     *  Get the current library error source file.
     *
     *  \return The current library error source file.
     */

    extern const char* MRH_GetEventQueueErrorFile(void);

    /**
     *  Get the current library error source file line.
     *
     *  \return The current library error source file line.
     */

    extern size_t MRH_GetEventQueueErrorFileLine(void);

#ifdef __cplusplus
}
#endif

#endif /* MRH_EventQueueError_h */
