MRH_RecieveEvents
=================
The MRH_RecieveEvents function is used to recieve events by reading the given 
input queue.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev.h>


Syntax
------
.. code-block:: c

    MRH_Uint32 MRH_RecieveEvents(MRH_InputEventQueue* p_EventQueue, 
                                 int i_TimeoutMS);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_EventQueue
      - The input queue to read from.
    * - i_TimeoutMS
      - The timeout for the read attempt in milliseconds.


Return Value
------------
The number of events fully recieved.

Remarks
-------
* This function call will block the calling thread for the specified timout or 
  until all possible events have been read.
* Previously recieved events will not be overwritten.

Code Examples
-------------
None.