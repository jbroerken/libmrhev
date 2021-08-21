MRH_ListPopFront
================
The MRH_ListPopFront function is used remove the first entry in a event queue 
event list.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    libmrhev.c


Syntax
------
.. code-block:: c

    static MRH_Event* MRH_ListPopFront(MRH_EventQueue* p_EventQueue)


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The event queue containing the event list.


Return Value
------------
The event of the first entry on success, NULL on no event / empty list or 
failure.

Remarks
-------
* This list will be corrected by this event (both in the list and in the event 
  queue given).

Code Examples
-------------
None.