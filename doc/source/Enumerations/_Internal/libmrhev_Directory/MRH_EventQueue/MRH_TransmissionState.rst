MRH_TransmissionState
=====================
The MRH_TransmissionState enumeration lists all possible results of a event 
data transmission attempt.

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
        MRH_TRANSMISSION_STATE_FAILED = 0,
        MRH_TRANSMISSION_STATE_COMPLETED = 1,
        MRH_TRANSMISSION_STATE_CONTINUE = 2,
        
        MRH_TRANSMISSION_STATE_MAX = MRH_TRANSMISSION_STATE_CONTINUE,

        MRH_TRANSMISSION_STATE_COUNT = MRH_TRANSMISSION_STATE_MAX + 1

    }MRH_TransmissionState;


Values
------
The meaning behind the transmission state enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_TRANSMISSION_STATE_FAILED
      - Transmission of event data failed.
    * - MRH_TRANSMISSION_STATE_COMPLETED
      - Transmission of event data has been completed fully.
    * - MRH_TRANSMISSION_STATE_CONTINUE
      - The current event data to transmit has not been fully transmitted.
    * - MRH_TRANSMISSION_STATE_MAX
      - The highest transmission state in this enumeration.
    * - MRH_TRANSMISSION_STATE_COUNT
      - The amount of transmission states in this enumeration.