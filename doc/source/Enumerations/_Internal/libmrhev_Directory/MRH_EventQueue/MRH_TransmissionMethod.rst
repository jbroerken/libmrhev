MRH_TransmissionMethod
======================
The MRH_TransmissionMethod enumeration lists the possible communcation methods 
used to transmit an event.

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
        MRH_TRANSMISSION_METHOD_UNK = -1,

        MRH_TRANSMISSION_METHOD_MRHCKM = 0,
        MRH_TRANSMISSION_METHOD_PIPE = 1,
        
        MRH_TRANSMISSION_METHOD_MAX = MRH_TRANSMISSION_METHOD_PIPE,

        MRH_TRANSMISSION_METHOD_CONT = MRH_TRANSMISSION_METHOD_MAX + 1

    }MRH_TransmissionMethod;


Values
------
The meaning behind the transmission method enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_TRANSMISSION_METHOD_UNK
      - The current transmission method is not known.
    * - MRH_TRANSMISSION_METHOD_MRHCKM
      - The current transmission method used is MRHCKM based.
    * - MRH_TRANSMISSION_METHOD_PIPE
      - The current transmission method used is pipe based.
    * - MRH_TRANSMISSION_METHOD_MAX
      - The highest transmission method in this enumeration.
    * - MRH_TRANSMISSION_METHOD_CONT
      - The amount of transmission methods in this enumeration.