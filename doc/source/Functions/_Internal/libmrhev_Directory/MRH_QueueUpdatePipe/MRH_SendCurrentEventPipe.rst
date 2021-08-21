MRH_SendCurrentEventPipe
========================
The MRH_SendCurrentEventPipe function is used write a single event to the pipe 
event source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/MRH_QueueUpdatePipe.h"


Syntax
------
.. code-block:: c

    int MRH_SendCurrentEventPipe(struct MRH_EventQueue_t* p_EventQueue);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The event queue containing the event to write.


Return Value
------------
0 on success, -1 on failure.

Remarks
-------
* A blocked up destination (no free bytes) is also considered a failure.
* :doc:`UpdateTransmissionData` is used to update the transmission data.
* The current transmission data is always updated so that the call can be 
  repeated on failure.

Code Examples
-------------
None.