MRH_TransmissionData
====================
The MRH_TransmissionData enumeration lists all steps occuring during the read 
or write transmission of an event.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/MRH_EventQueue.h"


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        MRH_TRANSMISSION_DATA_GROUP = 0,
        MRH_TRANSMISSION_DATA_TYPE = 1,
        MRH_TRANSMISSION_DATA_DATA_SIZE = 2,
        MRH_TRANSMISSION_DATA_DATA = 3,
        MRH_TRANSMISSION_DATA_FINISHED = 4,
        
        MRH_TRANSMISSION_DATA_MAX = MRH_TRANSMISSION_DATA_FINISHED,

        MRH_TRANSMISSION_DATA_COUNT = MRH_TRANSMISSION_DATA_MAX + 1

    }MRH_TransmissionData;


Values
------
The meaning behind the transmission data enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_TRANSMISSION_DATA_GROUP
      - The current transmission is the event group id.
    * - MRH_TRANSMISSION_DATA_TYPE
      - The current transmission is the event type.
    * - MRH_TRANSMISSION_DATA_DATA_SIZE
      - The current transmission is the event data size.
    * - MRH_TRANSMISSION_DATA_DATA
      - The current transmission is the event data buffer.
    * - MRH_TRANSMISSION_DATA_FINISHED
      - All event data has been transmitted.
    * - MRH_TRANSMISSION_DATA_MAX
      - The highest transmission state in this enumeration.
    * - MRH_TRANSMISSION_DATA_COUNT
      - The amount of transmission states in this enumeration.