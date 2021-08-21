MRH_SetEventQueueError
======================
The MRH_SetEventQueueError function is used to set the current library error 
value.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/Error/MRH_EventQueueErrorInternal.h"


Syntax
------
.. code-block:: c

    void MRH_SetEventQueueError(MRH_EV_Error_Type e_Error, 
                                MRH_EV_Error_File e_File, 
                                size_t us_Line);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - e_Error
      - The new :doc:`../../../../../Enumerations/libmrhev_Directory/Error/MRH_EventQueueError/MRH_EV_Error_Type`.
    * - e_File
      - The :doc:`../../../../../Enumerations/_Internal/libmrhev_Directory/Error/MRH_EventQueueErrorInternal/MRH_EV_Error_File` 
        file where the error occured.
    * - us_Line
      - The source file line where the error occured.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.