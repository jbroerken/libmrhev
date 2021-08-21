*********
Functions
*********
The list of functions shown here includes information about their use case as 
well as the required parameters and return values. Code examples are given if 
deemed neccessary.

Internal functions are used by the library itself. These functions are not 
meant to be used directly for application development.

Function errors can be retrieved by using the get error functions after the 
called function failed.

Library Functions
-----------------
.. toctree::
  :maxdepth: 1

  libmrhev/MRH_OpenInputQueueMRHCKM
  libmrhev/MRH_OpenOutputQueueMRHCKM
  libmrhev/MRH_OpenInputQueuePipe
  libmrhev/MRH_OpenOutputQueuePipe
  libmrhev/MRH_RecieveEvents
  libmrhev/MRH_GetEvent
  libmrhev/MRH_SendEvents
  libmrhev/MRH_AddEvent
  libmrhev/MRH_CanSendEvents
  libmrhev/MRH_CloseEventQueue
  libmrhev/MRH_GetEventQueueEventCount
  libmrhev_Directory/Error/MRH_EventQueueError/MRH_ResetEventQueueError
  libmrhev_Directory/Error/MRH_EventQueueError/MRH_GetEventQueueError
  libmrhev_Directory/Error/MRH_EventQueueError/MRH_GetEventQueueErrorString
  libmrhev_Directory/Error/MRH_EventQueueError/MRH_GetEventQueueErrorFile
  libmrhev_Directory/Error/MRH_EventQueueError/MRH_GetEventQueueErrorFileLine

Internal Functions
------------------
.. toctree::
  :maxdepth: 1
  
  _Internal/libmrhev/MRH_OpenEventQueueGeneric
  _Internal/libmrhev/MRH_OpenEventQueueMRHCKM
  _Internal/libmrhev/MRH_OpenEventQueuePipe
  _Internal/libmrhev/MRH_ListPopFront
  _Internal/libmrhev/MRH_ListPushBack
  _Internal/libmrhev_Directory/Error/MRH_EventQueueErrorInternal/MRH_SetEventQueueError
  _Internal/libmrhev_Directory/Source/MRH_SourcePipe/MRH_OpenPipe
  _Internal/libmrhev_Directory/Source/MRH_SourcePipe/MRH_PollPipe
  _Internal/libmrhev_Directory/Source/MRH_SourcePipe/MRH_ReadPipe
  _Internal/libmrhev_Directory/Source/MRH_SourcePipe/MRH_WritePipe
  _Internal/libmrhev_Directory/Source/MRH_SourcePipe/MRH_ClosePipe
  _Internal/libmrhev_Directory/MRH_QueueUpdateMRHCKM/MRH_OpenQueueSourceMRHCKM
  _Internal/libmrhev_Directory/MRH_QueueUpdateMRHCKM/MRH_RecieveCurrentEventMRHCKM
  _Internal/libmrhev_Directory/MRH_QueueUpdateMRHCKM/MRH_SendCurrentEventMRHCKM
  _Internal/libmrhev_Directory/MRH_QueueUpdateMRHCKM/MRH_CloseQueueSourceMRHCKM
  _Internal/libmrhev_Directory/MRH_QueueUpdatePipe/MRH_OpenQueueSourcePipe
  _Internal/libmrhev_Directory/MRH_QueueUpdatePipe/UpdateTransmissionData
  _Internal/libmrhev_Directory/MRH_QueueUpdatePipe/MRH_RecieveCurrentEventPipe
  _Internal/libmrhev_Directory/MRH_QueueUpdatePipe/MRH_SendCurrentEventPipe
  _Internal/libmrhev_Directory/MRH_QueueUpdatePipe/MRH_CloseQueueSourcePipe