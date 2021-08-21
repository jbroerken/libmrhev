/**
 *  MRH_QueueUpdateMRHCKM.h
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

#ifndef MRH_QueueUpdateMRHCKM_h
#define MRH_QueueUpdateMRHCKM_h

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
     *  Open a kernel module connection for the event queue.
     *
     *  \param p_EventQueue The event queue to use.
     *  \param p_Path The full path to the device file.
     *  \param i_Key The key for the given device file.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_OpenQueueSourceMRHCKM(struct MRH_EventQueue_t* p_EventQueue, const char* p_Path, int i_Key);

    //*************************************************************************************
    // Recieve
    //*************************************************************************************

    /**
     *  Recieve the current event from a kernel module connection.
     *
     *  \param p_EventQueue The event queue to use.
     *  \param i_TimeoutMS The timeout in milliseconds.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_RecieveCurrentEventMRHCKM(struct MRH_EventQueue_t* p_EventQueue, int i_TimeoutMS);

    //*************************************************************************************
    // Send
    //*************************************************************************************

    /**
     *  Send the current event to a kernel module connection.
     *
     *  \param p_EventQueue The event queue to use.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_SendCurrentEventMRHCKM(struct MRH_EventQueue_t* p_EventQueue);

    //*************************************************************************************
    // Close
    //*************************************************************************************

    /**
     *  Close a kernel module connection used by the event queue.
     *
     *  \param p_EventQueue The event queue to use.
     */

    extern void MRH_CloseQueueSourceMRHCKM(struct MRH_EventQueue_t* p_EventQueue);

#ifdef __cplusplus
}
#endif

#endif /* MRH_QueueUpdateMRHCKM_h */
