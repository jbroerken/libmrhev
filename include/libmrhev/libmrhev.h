/**
 *  libmrhev.h
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
