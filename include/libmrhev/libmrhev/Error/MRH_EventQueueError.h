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
