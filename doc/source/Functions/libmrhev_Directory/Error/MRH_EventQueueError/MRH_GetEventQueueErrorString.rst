MRH_GetEventQueueErrorString
============================
The MRH_GetEventQueueErrorString function is used to retrieve the description 
string for the current library error value.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev/Error/MRH_EventQueueError.h>


Syntax
------
.. code-block:: c

    const char* MRH_GetEventQueueErrorString(void);


Parameters
----------
None.

Return Value
------------
The current library error string.

Remarks
-------
* The string returned depends on the currently set 
  :doc:`../../../../Enumerations/libmrhev_Directory/Error/MRH_EventQueueError/MRH_EV_Error_Type`.

Code Examples
-------------
None.