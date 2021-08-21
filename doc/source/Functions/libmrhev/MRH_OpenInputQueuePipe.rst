MRH_OpenInputQueuePipe
======================
The MRH_OpenInputQueuePipe function is used to create an event input queue 
using a pipe.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev.h>


Syntax
------
.. code-block:: c

    MRH_InputEventQueue* MRH_OpenInputQueuePipe(int i_FD, 
                                                MRH_Uint32 u32_RecieveLimit);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - i_FD
      - The read end file descriptor of the pipe.
    * - u32_RecieveLimit
      - The maximum amount of events which can be recieved in one queue update.


Return Value
------------
The input queue on success, NULL on failure.

Remarks
-------
* :doc:`../_Internal/libmrhev/MRH_OpenEventQueuePipe` is used to create the 
  event queue.

Code Examples
-------------
None.