/**
 *  MRH_SourcePipe.h
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
