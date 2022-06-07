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

#ifndef libmrhev_h
#define libmrhev_h

// C

// External
#include <MRH_Event.h>

// Project
#include "./libmrhev/MRH_EvRevision.h"
#include "./libmrhev/Error/MRH_EventQueueError.h"


#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Types
    //*************************************************************************************

    // Opaque pointer
    struct MRH_EventQueue_t;
    typedef struct MRH_EventQueue_t MRH_EventQueue;
    typedef MRH_EventQueue MRH_InputEventQueue;
    typedef MRH_EventQueue MRH_OutputEventQueue;

    //*************************************************************************************
    // Open
    //*************************************************************************************

#ifdef __MRH_MRHCKM_SUPPORTED__
    /**
     *  Open a MRHCKM based input event queue.
     *
     *  \param p_Path The full path to the device file.
     *  \param i_Key The key for the given device file.
     *  \param u32_RecieveLimit The maximum amount of events to be recieved per update.
     *
     *  \return The input event queue on success, NULL on failure.
     */

     extern MRH_InputEventQueue* MRH_OpenInputQueueMRHCKM(const char* p_Path, int i_Key, MRH_Uint32 u32_RecieveLimit);

    /**
     *  Open a MRHCKM based output event queue.
     *
     *  \param p_Path The full path to the device file.
     *  \param i_Key The key for the given device file.
     *  \param u32_SendLimit The maximum amount of events to be sent per update.
     *
     *  \return The output event queue on success, NULL on failure.
     */

    extern MRH_OutputEventQueue* MRH_OpenOutputQueueMRHCKM(const char* p_Path, int i_Key, MRH_Uint32 u32_SendLimit);
#endif

    /**
     *  Open a pipe based input event queue.
     *
     *  \param i_FD The event queue file descriptor.
     *  \param u32_RecieveLimit The maximum amount of events to be recieved per update.
     *
     *  \return The input event queue on success, NULL on failure.
     */

    extern MRH_InputEventQueue* MRH_OpenInputQueuePipe(int i_FD, MRH_Uint32 u32_RecieveLimit);

    /**
     *  Open a pipe based output event queue.
     *
     *  \param i_FD The event queue file descriptor.
     *  \param u32_SendLimit The maximum amount of events to be sent per update.
     *
     *  \return The output event queue on success, NULL on failure.
     */

    extern MRH_OutputEventQueue* MRH_OpenOutputQueuePipe(int i_FD, MRH_Uint32 u32_SendLimit);

    //*************************************************************************************
    // Recieve
    //*************************************************************************************

    /**
     *  Read the input event queue for events to be recieved.
     *
     *  \param p_EventQueue The input event queue to read.
     *  \param i_TimeoutMS The timeout for the read attempt in milliseconds.
     *
     *  \return The amount of events recieved.
     */

    extern MRH_Uint32 MRH_RecieveEvents(MRH_InputEventQueue* p_EventQueue, int i_TimeoutMS);

    /**
     *  Get a recieved event.
     *
     *  \param p_EventQueue The input event queue to check.
     *
     *  \return A recieved event on success, NULL on no events.
     */

    extern MRH_Event* MRH_GetEvent(MRH_InputEventQueue* p_EventQueue);

    //*************************************************************************************
    // Send
    //*************************************************************************************

    /**
     *  Write the output event queue with events to send.
     *
     *  \param p_EventQueue The output event queue to send from.
     *
     *  \return The amount of events sent.
     */

    extern MRH_Uint32 MRH_SendEvents(MRH_OutputEventQueue* p_EventQueue);

    /**
     *  Add an event to the output queue.
     *
     *  \param p_EventQueue The output event queue to add to.
     *  \param p_Event The event to add. The event is consumed.
     *
     *  \return NULL on success, the given p_Event on failure.
     */

    extern MRH_Event* MRH_AddEvent(MRH_OutputEventQueue* p_EventQueue, MRH_Event** p_Event);

    /**
     *  Check if data can be sent.
     *
     *  \param p_EventQueue The output event queue to check.
     *
     *  \return 0 if possible, -1 if not.
     */

    extern int MRH_CanSendEvents(MRH_OutputEventQueue* p_EventQueue);

    //*************************************************************************************
    // Close
    //*************************************************************************************

    /**
     *  Close a event queue.
     *
     *  \param p_EventQueue The event queue to close.
     *
     *  \return Always NULL.
     */

    extern MRH_EventQueue* MRH_CloseEventQueue(MRH_EventQueue* p_EventQueue);

    //*************************************************************************************
    // Getters
    //*************************************************************************************

    /**
     *  Check the event queue event count.
     *
     *  \param p_EventQueue The event queue to check.
     *
     *  \return The amount of events to either send or get.
     */

    extern MRH_Uint32 MRH_GetEventQueueEventCount(MRH_EventQueue* p_EventQueue);

#ifdef __cplusplus
}
#endif

#endif /* libmrhev_h */
