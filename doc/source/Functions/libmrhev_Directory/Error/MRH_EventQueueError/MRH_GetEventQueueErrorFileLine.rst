MRH_GetEventQueueErrorFileLine
==============================
The MRH_GetEventQueueErrorFileLine function is used to retrieve the line where 
the current error value occured.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhev/Error/MRH_EventQueueError.h>


Syntax
------
.. code-block:: c

    size_t MRH_GetEventQueueErrorFileLine(void);


Parameters
----------
None.

Return Value
------------
The source line of the library error.

Remarks
-------
* The string returned depends on the currently set 
  :doc:`../../../../Enumerations/libmrhev_Directory/Error/MRH_EventQueueError/MRH_EV_Error_Type`.

Code Examples
-------------
None.