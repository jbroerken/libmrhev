MRH_OpenQueueSourcePipe
=======================
The MRH_OpenQueueSourcePipe function is used to add a pipe event source to a 
event queue.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/MRH_QueueUpdatePipe.h"


Syntax
------
.. code-block:: c

    int MRH_OpenQueueSourcePipe(struct MRH_EventQueue_t* p_EventQueue, 
                                const char* p_Path, 
                                int i_Key);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The event queue to add the source to.
    * - p_Path
      - The full path to the MRHCKM source file.
    * - i_Key
      - The key used to open the MRHCKM source.


Return Value
------------
0 on success, -1 on failure.

Remarks
-------
None.

Code Examples
-------------
None.