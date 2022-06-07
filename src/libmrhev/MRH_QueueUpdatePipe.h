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

#ifndef MRH_QueueUpdatePipe_h
#define MRH_QueueUpdatePipe_h

// C

// External

// Project
#include "./MRH_EventQueue.h"


#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Open
    //*************************************************************************************

    /**
     *  Open a pipe for the event queue.
     *
     *  \param p_EventQueue The event queue to use.
     *  \param i_FD The pipe file descriptor to use.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_OpenQueueSourcePipe(struct MRH_EventQueue_t* p_EventQueue, int i_FD);

    //*************************************************************************************
    // Recieve
    //*************************************************************************************

    /**
     *  Recieve the current event from a pipe.
     *
     *  \param p_EventQueue The event queue to use.
     *  \param i_TimeoutMS The timeout in milliseconds.
     *
     *  \return The event update state on success, -1 on failure.
     */

    extern MRH_TransmissionState MRH_RecieveCurrentEventPipe(struct MRH_EventQueue_t* p_EventQueue, int i_TimeoutMS);

    //*************************************************************************************
    // Send
    //*************************************************************************************

    /**
     *  Send the current event to a pipe.
     *
     *  \param p_EventQueue The event queue to use.
     *
     *  \return The event update state on success, -1 on failure.
     */

    extern MRH_TransmissionState MRH_SendCurrentEventPipe(struct MRH_EventQueue_t* p_EventQueue);

    //*************************************************************************************
    // Close
    //*************************************************************************************

    /**
     *  Close a pipe used by the event queue.
     *
     *  \param p_EventQueue The event queue to use.
     */

    extern void MRH_CloseQueueSourcePipe(struct MRH_EventQueue_t* p_EventQueue);

#ifdef __cplusplus
}
#endif

#endif /* MRH_QueueUpdatePipe_h */
