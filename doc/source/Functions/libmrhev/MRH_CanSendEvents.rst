MRH_CanSendEvents
=================
The MRH_CanSendEvents function is used to check if an output queue still 
contains events to be sent.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev.h>


Syntax
------
.. code-block:: c

    int MRH_CanSendEvents(MRH_OutputEventQueue* p_EventQueue);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The output queue to check.


Return Value
------------
0 if events remain to be sent, -1 if not.

Remarks
-------
None.

Code Examples
-------------
None.