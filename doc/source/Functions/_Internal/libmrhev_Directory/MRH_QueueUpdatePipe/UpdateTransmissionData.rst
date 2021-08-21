UpdateTransmissionData (Pipe)
=============================
The UpdateTransmissionData function is used to set the current event 
transmission data for a pipe based on the bytes read or written.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    libmrhev/MRH_QueueUpdatePipe.c


Syntax
------
.. code-block:: c

    static int UpdateTransmissionData(struct MRH_EventQueue_t* p_EventQueue, 
                                      ssize_t ss_Processed, 
                                      MRH_Uint32 u32_Required, 
                                      MRH_TransmissionData e_NextData)


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The event queue to update the transmissions state for.
    * - ss_Processed
      - The amount of bytes processed (read / write) for the current state.
    * - u32_Required
      - The required amount of bytes processed (read / write) for the state to 
        change.
    * - e_NextData
      - The next :doc:`../../../../Enumerations/_Internal/libmrhev_Directory/MRH_EventQueue/MRH_TransmissionData` 
        if the the process (read / write) requirement has been met.


Return Value
------------
The :doc:`../../../../Enumerations/_Internal/libmrhev_Directory/MRH_EventQueue/MRH_TransmissionState` 
result describing the transmission result for the current :doc:`../../../../Enumerations/_Internal/libmrhev_Directory/MRH_EventQueue/MRH_TransmissionData`.

Remarks
-------
* The result only informs about wether the transmission state was changed or 
  not. The acutal new state is set by the function itself.

Code Examples
-------------
None.