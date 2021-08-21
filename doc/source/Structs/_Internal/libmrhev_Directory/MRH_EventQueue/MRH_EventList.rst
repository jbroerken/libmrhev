MRH_EventList
=============
The MRH_EventList struct implements a linked list used to store platform events.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/MRH_EventQueue.h"


Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
    * - p_Event
      - MRH_Event*
      - The event stored by this list entry.
    * - p_Next
      - struct MRH_EventList_t
      - The next entry in the linked list.


Remarks
-------
* New events are added to the back of the list.
* The last entry will have its p_Next pointer set to NULL.