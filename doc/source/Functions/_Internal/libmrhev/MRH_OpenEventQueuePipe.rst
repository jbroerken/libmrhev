MRH_OpenEventQueuePipe
======================
The MRH_OpenEventQueuePipe function is used create a generic event queue and 
add the pipe source info to it.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    libmrhev.c


Syntax
------
.. code-block:: c

    static MRH_EventQueue* MRH_OpenEventQueuePipe(int i_FD, 
                                                  MRH_QueueType e_Type, 
                                                  MRH_Uint32 u32_EventLimit)


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - i_FD
      - The pipe end file descriptor of the pipe source.
    * - e_Type
      - The :doc:`../../../Enumerations/_Internal/libmrhev_Directory/MRH_EventQueue/MRH_QueueType`.
    * - u32_EventLimit
      - The maximum amount of events to sent and recieved in one queue update.


Return Value
------------
The pipe based event queue on success, NULL on failure.

Remarks
-------
* :doc:`MRH_OpenEventQueueGeneric` is used to create the generic list.

Code Examples
-------------
None.