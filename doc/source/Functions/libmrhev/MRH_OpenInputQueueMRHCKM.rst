MRH_OpenInputQueueMRHCKM
========================
The MRH_OpenInputQueueMRHCKM function is used to create an event input queue 
using the MRHCKM module.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev.h>


Syntax
------
.. code-block:: c

    MRH_InputEventQueue* MRH_OpenInputQueueMRHCKM(const char* p_Path, 
                                                  int i_Key, 
                                                  MRH_Uint32 u32_RecieveLimit);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Path
      - The full path to the MRHCKM queue file.
    * - i_Key
      - The key to open the MRHCKM queue with.
    * - u32_RecieveLimit
      - The maximum amount of events which can be recieved in one queue update.


Return Value
------------
The input queue on success, NULL on failure.

Remarks
-------
* :doc:`../_Internal/libmrhev/MRH_OpenEventQueueMRHCKM` is used to create the 
  event queue.

Code Examples
-------------
None.