MRH_GetEvent
============
The MRH_GetEvent function is used to retrieve an recieved event from the given 
event queue.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_GetEvent(MRH_InputEventQueue* p_EventQueue);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The input queue to read from.


Return Value
------------
A recieved event on success, NULL if no events remain or on failure.

Remarks
-------
* The events will be returned in the order of which they were recieved.

Code Examples
-------------
None.