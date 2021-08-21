MRH_CloseEventQueue
===================
The MRH_CloseEventQueue function is used to clean up and close a given event 
queue.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev.h>


Syntax
------
.. code-block:: c

    MRH_EventQueue* MRH_CloseEventQueue(MRH_EventQueue* p_EventQueue);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The queue to close.


Return Value
------------
Always NULL.

Remarks
-------
None.

Code Examples
-------------
None.