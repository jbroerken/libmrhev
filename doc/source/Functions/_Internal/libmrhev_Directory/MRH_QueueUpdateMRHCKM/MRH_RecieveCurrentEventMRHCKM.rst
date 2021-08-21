MRH_RecieveCurrentEventMRHCKM
=============================
The MRH_RecieveCurrentEventMRHCKM function is used to read and construct a 
single event by reading the MRHCKM module source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/MRH_QueueUpdateMRHCKM.h"


Syntax
------
.. code-block:: c

    int MRH_RecieveCurrentEventMRHCKM(struct MRH_EventQueue_t* p_EventQueue, 
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
* The current transmission state is saved so that the call can be repeated on 
  failure.

Code Examples
-------------
None.