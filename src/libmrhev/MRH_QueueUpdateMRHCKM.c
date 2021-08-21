/**
 *  MRH_QueueUpdateMRHCKM.c
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

// C

// External

// Project
#include "MRH_QueueUpdateMRHCKM.h"
#include "./Source/MRH_SourceMRHCKM.h"
#include "./Error/MRH_EventQueueErrorInternal.h"


//*************************************************************************************
// Open
//*************************************************************************************

int MRH_OpenQueueSourceMRHCKM(struct MRH_EventQueue_t* p_EventQueue, const char* p_Path, int i_Key)
{
    // @TODO: Open!
    return -1;
}

//*************************************************************************************
// Recieve
//*************************************************************************************

int MRH_RecieveCurrentEventMRHCKM(struct MRH_EventQueue_t* p_EventQueue, int i_TimeoutMS)
{
    // @TODO: Recive!
    return -1;
}

//*************************************************************************************
// Send
//*************************************************************************************

int MRH_SendCurrentEventMRHCKM(struct MRH_EventQueue_t* p_EventQueue)
{
    // @TODO: Write
    return -1;
}

//*************************************************************************************
// Close
//*************************************************************************************

void MRH_CloseQueueSourceMRHCKM(struct MRH_EventQueue_t* p_EventQueue)
{
    // @TODO: Close!
}
