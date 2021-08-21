MRH_EventQueue_t
================
The MRH_EventQueue_t struct contains all event queue information like queue 
type, stored events, event limit and more.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/MRH_EventQueue.h"


Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
    * - e_QueueType
      - MRH_QueueType
      - The :doc:`../../../../Enumerations/_Internal/libmrhev_Directory/MRH_EventQueue/MRH_QueueType`.
    * - e_TransmissionState
      - MRH_TransmissionState
      - The current :doc:`../../../../Enumerations/_Internal/libmrhev_Directory/MRH_EventQueue/MRH_TransmissionState` 
        for the current event data to be transmitted.
    * - e_TransmissionData
      - MRH_TransmissionData
      - The current :doc:`../../../../Enumerations/_Internal/libmrhev_Directory/MRH_EventQueue/MRH_TransmissionData` 
        for the current event.
    * - p_Current
      - MRH_Event*
      - The current event to be read or written.
    * - u32_Bytes
      - MRH_Uint32
      - The amount of bytes already read or written.
    * - p_First
      - MRH_EventList*
      - The first entry (start) of the queue event list.
    * - p_End
      - MRH_EventList*
      - The last entry (end) of the queue event list.
    * - e_TransmissionMethod
      - MRH_TransmissionMethod
      - The type of :doc:`../../../../Enumerations/_Internal/libmrhev_Directory/MRH_EventQueue/MRH_TransmissionMethod` 
        used.
    * - p_Source
      - void*
      - The data source for the chosen transmition method.
    * - u32_SendLimit
      - MRH_Uint32
      - The maximum amount of events which can be send in one send action.
    * - u32_RecieveLimit
      - MRH_Uint32
      - The maximum amount of events which can be recieved in one recieve 
        action.


Remarks
-------
* This struct is given to the library user as an opague struct.