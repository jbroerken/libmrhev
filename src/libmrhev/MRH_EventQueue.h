/**
 *  MRH_EventQueue.h
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

#ifndef MRH_EventQueue_h
#define MRH_EventQueue_h

// C

// External
#include <MRH_Event.h>

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
        MRH_QUEUE_TYPE_INPUT = 0,
        MRH_QUEUE_TYPE_OUTPUT = 1,
        
        MRH_QUEUE_TYPE_MAX = MRH_QUEUE_TYPE_OUTPUT,
        
        MRH_QUEUE_TYPE_COUNT = MRH_QUEUE_TYPE_MAX + 1
        
    }MRH_QueueType;

    typedef enum
    {
        MRH_TRANSMISSION_STATE_FAILED = 0,
        MRH_TRANSMISSION_STATE_COMPLETED = 1,
        MRH_TRANSMISSION_STATE_CONTINUE = 2,
    
        MRH_TRANSMISSION_STATE_MAX = MRH_TRANSMISSION_STATE_CONTINUE,
    
        MRH_TRANSMISSION_STATE_COUNT = MRH_TRANSMISSION_STATE_MAX + 1
    
    }MRH_TransmissionState;

    typedef enum
    {
        MRH_TRANSMISSION_DATA_GROUP = 0,
        MRH_TRANSMISSION_DATA_TYPE = 1,
        MRH_TRANSMISSION_DATA_DATA_SIZE = 2,
        MRH_TRANSMISSION_DATA_DATA = 3,
        MRH_TRANSMISSION_DATA_FINISHED = 4,
        
        MRH_TRANSMISSION_DATA_MAX = MRH_TRANSMISSION_DATA_FINISHED,
        
        MRH_TRANSMISSION_DATA_COUNT = MRH_TRANSMISSION_DATA_MAX + 1
    
    }MRH_TransmissionData;

    typedef enum
    {
        MRH_TRANSMISSION_METHOD_UNK = -1,
        
        MRH_TRANSMISSION_METHOD_MRHCKM = 0,
        MRH_TRANSMISSION_METHOD_PIPE = 1,
        
        MRH_TRANSMISSION_METHOD_MAX = MRH_TRANSMISSION_METHOD_PIPE,
        
        MRH_TRANSMISSION_METHOD_CONT = MRH_TRANSMISSION_METHOD_MAX + 1
    
    }MRH_TransmissionMethod;

    //*************************************************************************************
    // Container
    //*************************************************************************************

    typedef struct MRH_EventList_t
    {
        MRH_Event* p_Event;
        struct MRH_EventList_t* p_Next;
        
    }MRH_EventList;

    struct MRH_EventQueue_t
    {
        // The queue type, defines other data
        MRH_QueueType e_QueueType;
        
        // Current event to either read or write
        MRH_TransmissionState e_TransmissionState;
        MRH_TransmissionData e_TransmissionData;
        MRH_Event* p_Current;
        MRH_Uint32 u32_BytesProcessed; // R/W byte count
        
        // Events to write or all completely read events, NULL means nothing to write or nothing read
        MRH_EventList* p_First;
        MRH_EventList* p_End;
    
        // Transmission method
        MRH_TransmissionMethod e_TransmissionMethod;
        void* p_Source;
        
        // Event exchange limitation (spam protection)
        MRH_Uint32 u32_SendLimit;
        MRH_Uint32 u32_RecieveLimit;
    };

#ifdef __cplusplus
}
#endif

#endif /* MRH_EventQueue_h */
