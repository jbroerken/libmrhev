MRH_SendEvents
==============
The MRH_SendEvents function is used to send events by writing to the given 
output queue.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev.h>


Syntax
------
.. code-block:: c

    MRH_Uint32 MRH_SendEvents(MRH_OutputEventQueue* p_EventQueue);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The output queue to write to.


Return Value
------------
The number of events fully sent.

Remarks
-------
* Events which could not be sent will stay in the queue and be sent first on 
  the next send attempt.

Code Examples
-------------
None.