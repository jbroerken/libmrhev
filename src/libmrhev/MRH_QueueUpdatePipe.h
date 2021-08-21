/**
 *  MRH_QueueUpdatePipe.h
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
