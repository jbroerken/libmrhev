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
