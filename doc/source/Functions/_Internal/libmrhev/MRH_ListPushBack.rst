MRH_ListPushBack
================
The MRH_ListPushBack function is used to add a event to the end of the event 
queue linked event list.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    libmrhev.c


Syntax
------
.. code-block:: c

    static void MRH_ListPushBack(MRH_EventQueue* p_EventQueue, 
                                 MRH_Event** p_Event)


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The event queue containing the event list to modify.
    * - p_Event
      - The event to push back to the event list end.


Return Value
------------
None.

Remarks
-------
* The event is consumed if added.

Code Examples
-------------
None.