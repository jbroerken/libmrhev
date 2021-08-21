MRH_AddEvent
============
The MRH_AddEvent function is used to add events to be sent to the given output 
queue.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_AddEvent(MRH_OutputEventQueue* p_EventQueue, 
                            MRH_Event** p_Event);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The output queue to add the event to.
    * - p_Event
      - The location of the event to send.


Return Value
------------
NULL on success, the given event on failure.

Remarks
-------
* The given event will be consumed.

Code Examples
-------------
None.