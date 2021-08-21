MRH_GetEventQueueEventCount
===========================
The MRH_GetEventQueueEventCount function is used to get the amount of fully 
completed events inside of an event queue.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev.h>


Syntax
------
.. code-block:: c

    MRH_Uint32 MRH_GetEventQueueEventCount(MRH_EventQueue* p_EventQueue);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The queue to check.


Return Value
------------
The amount of events to either send or get.

Remarks
-------
None.

Code Examples
-------------
None.