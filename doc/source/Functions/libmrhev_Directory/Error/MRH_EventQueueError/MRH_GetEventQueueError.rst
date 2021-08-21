MRH_GetEventQueueError
======================
The MRH_GetEventQueueError function is used to retrieve the current library 
error value.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev/Error/MRH_EventQueueError.h>


Syntax
------
.. code-block:: c

    MRH_EV_Error_Type MRH_GetEventQueueError(void);


Parameters
----------
None.

Return Value
------------
The current :doc:`../../../../Enumerations/libmrhev_Directory/Error/MRH_EventQueueError/MRH_EV_Error_Type`.

Remarks
-------
* The error value will not be reset after retrieving.

Code Examples
-------------
None.