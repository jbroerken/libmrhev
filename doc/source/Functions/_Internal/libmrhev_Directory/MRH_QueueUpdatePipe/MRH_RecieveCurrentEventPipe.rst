MRH_RecieveCurrentEventPipe
===========================
The MRH_RecieveCurrentEventPipe function is used to read and construct a single 
event by reading the queue pipe source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/MRH_QueueUpdatePipe.h"


Syntax
------
.. code-block:: c

    int MRH_RecieveCurrentEventPipe(struct MRH_EventQueue_t* p_EventQueue, 
                                    int i_TimeoutMS);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The event queue to add the recieved event to.
    * - i_TimeoutMS
      - The recieve timeout in milliseconds.


Return Value
------------
0 on success, -1 on not enough bytes available or failure.

Remarks
-------
* A empty source (no bytes) is also considered a failure.
* :doc:`UpdateTransmissionData` is used to update the transmission data.
* The current transmission data is always updated so that the call can be 
  repeated on failure.

Code Examples
-------------
None.