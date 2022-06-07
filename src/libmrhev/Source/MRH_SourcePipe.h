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

#ifndef MRH_SourcePipe_h
#define MRH_SourcePipe_h

// C
#include <poll.h>
#include <sys/types.h> // ssize_t

// External
#include <MRH_Typedefs.h>

// Project


#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Types
    //*************************************************************************************

    typedef struct MRH_SourcePipe_t
    {
        int i_FD;
        
        struct pollfd s_PollFD;
        
    }MRH_SourcePipe;

    //*************************************************************************************
    // Open
    //*************************************************************************************

    /**
     *  Open a pipe.
     *
     *  \param i_FD The pipe file descriptor.
     *
     *  \return The pipe on success, NULL on failure.
     */

    extern MRH_SourcePipe* MRH_OpenPipe(int i_FD);

    //*************************************************************************************
    // Poll
    //*************************************************************************************

    /**
     *  Poll a pipe for a event.
     *
     *  \param p_Pipe The pipe to poll.
     *  \param i_Event The poll event.
     *  \param i_TimeoutMS The timeout for the poll request.
     *
     *  \return 0 on event found, -1 on failure.
     */

    extern int MRH_PollPipe(MRH_SourcePipe* p_Pipe, int i_Event, int i_TimeoutMS);

    //*************************************************************************************
    // Read
    //*************************************************************************************

    /**
     *  Read events from a pipe.
     *
     *  \param p_Pipe The pipe to read from.
     *  \param p_Data The allocated buffer to read to.
     *  \param u32_Length The length of the allocated buffer.
     *
     *  \return The amount of bytes read, -1 on failure.
     */

    extern ssize_t MRH_ReadPipe(MRH_SourcePipe* p_Pipe, MRH_Uint8* p_Data, MRH_Uint32 u32_Length);

    //*************************************************************************************
    // Write
    //*************************************************************************************

    /**
     *  Write events to a pipe.
     *
     *  \param p_Pipe The pipe to write to.
     *  \param p_Data The data to write.
     *  \param u32_Length The length of the data to write in bytes.
     *
     *  \return The amount of bytes written, -1 on failure.
     */

    extern ssize_t MRH_WritePipe(MRH_SourcePipe* p_Pipe, const MRH_Uint8* p_Data, MRH_Uint32 u32_Length);

    //*************************************************************************************
    // Close
    //*************************************************************************************

    /**
     *  Close a pipe.
     *
     *  \param p_Pipe The pipe to close.
     *
     *  \return Always NULL.
     */

    extern MRH_SourcePipe* MRH_ClosePipe(MRH_SourcePipe* p_Pipe);

#ifdef __cplusplus
}
#endif

#endif /* MRH_SourcePipe_h */
