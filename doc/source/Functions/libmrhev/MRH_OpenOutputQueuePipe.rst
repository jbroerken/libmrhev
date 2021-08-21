MRH_OpenOutputQueuePipe
=======================
The MRH_OpenOutputQueuePipe function is used to create an event output queue 
using a pipe.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev.h>


Syntax
------
.. code-block:: c

    MRH_InputEventQueue* MRH_OpenOutputQueuePipe(int i_FD, 
                                                 MRH_Uint32 u32_SendLimit);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - i_FD
      - The write end file descriptor of the pipe.
    * - u32_SendLimit
      - The maximum amount of events which can be sent in one queue update.


Return Value
------------
The output queue on success, NULL on failure.

Remarks
-------
* :doc:`../_Internal/libmrhev/MRH_OpenEventQueuePipe` is used to create the 
  event queue.

Code Examples
-------------
None.