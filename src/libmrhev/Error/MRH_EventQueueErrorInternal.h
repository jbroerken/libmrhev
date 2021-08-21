/**
 *  MRH_EventQueueErrorInternal.h
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
