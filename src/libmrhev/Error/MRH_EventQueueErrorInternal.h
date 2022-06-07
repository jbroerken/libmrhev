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

#ifndef MRH_EventQueueErrorInternal_h
#define MRH_EventQueueErrorInternal_h

// C

// External

// Project
#include "../../../include/libmrhev/libmrhev/Error/MRH_EventQueueError.h"


#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Types
    //*************************************************************************************

    typedef enum
    {
        // Default
        MRH_EV_ERROR_FILE_NONE = 0,
        
        // libmrhev/Error dir
        MRH_EV_ERROR_FILE_ERROR = 1,
        
        // libmrhev/Source dir
        MRH_EV_ERROR_FILE_SOURCE_MRHCKM = 2,
        MRH_EV_ERROR_FILE_SOURCE_PIPE = 3,
        
        // libmrhev dir
        MRH_EV_ERROR_FILE_QUEUE_UPDATE_MRHCKM = 4,
        MRH_EV_ERROR_FILE_QUEUE_UPDATE_PIPE = 5,
        
        // Root dir
        MRH_EV_ERROR_FILE_LIBMRHEV,
        
        // Bounds
        MRH_EV_ERROR_FILE_MAX = MRH_EV_ERROR_FILE_LIBMRHEV,

        MRH_EV_ERROR_FILE_COUNT = MRH_EV_ERROR_TYPE_MAX + 1

    }MRH_EV_Error_File;

    //*************************************************************************************
    // Setters
    //*************************************************************************************

   /**
    *  Set library error.
    *
    *  \param e_Error The current library error.
    *  \param e_File The file where the current error occured.
    *  \param us_Line The file line where the current error occured.
    */

    extern void MRH_SetEventQueueError(MRH_EV_Error_Type e_Error, MRH_EV_Error_File e_File, size_t us_Line);

#ifdef __cplusplus
}
#endif

#endif /* MRH_EventQueueErrorInternal_h */
