MRH_OpenEventQueueGeneric
=========================
The MRH_OpenEventQueueGeneric function is used create and setup a generic event 
queue which can then be fitted with the requested communication method 
(MRHCKM, etc).

Header
------
The function definition can be found in the following file:

.. code-block:: c

    libmrhev.c


Syntax
------
.. code-block:: c

    static MRH_EventQueue* MRH_OpenEventQueueGeneric(MRH_QueueType e_Type, 
                                                     MRH_Uint32 u32_EventLimit)


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - e_Type
      - The :doc:`../../../Enumerations/_Internal/libmrhev_Directory/MRH_EventQueue/MRH_QueueType`.
    * - u32_EventLimit
      - The maximum amount of events to sent and recieved in one update.


Return Value
------------
The generic event queue on success, NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.