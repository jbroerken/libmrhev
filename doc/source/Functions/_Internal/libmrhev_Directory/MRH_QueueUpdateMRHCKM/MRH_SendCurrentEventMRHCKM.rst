MRH_SendCurrentEventMRHCKM
==========================
The MRH_SendCurrentEventMRHCKM function is used write a single event to the 
MRHCKM event source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/MRH_QueueUpdateMRHCKM.h"


Syntax
------
.. code-block:: c

    int MRH_SendCurrentEventMRHCKM(struct MRH_EventQueue_t* p_EventQueue);


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
* The current transmission state is saved so that the call can be repeated on 
  failure.

Code Examples
-------------
None.