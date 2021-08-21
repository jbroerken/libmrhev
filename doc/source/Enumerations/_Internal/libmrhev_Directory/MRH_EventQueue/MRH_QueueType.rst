MRH_QueueType
=============
The MRH_QueueType enumeration lists all event queue types available.

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
        MRH_QUEUE_TYPE_INPUT = 0,
        MRH_QUEUE_TYPE_OUTPUT = 1,
        
        MRH_QUEUE_TYPE_MAX = MRH_QUEUE_TYPE_OUTPUT,

        MRH_QUEUE_TYPE_COUNT = MRH_QUEUE_TYPE_MAX + 1

    }MRH_QueueType;


Values
------
The meaning behind the queue type enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_QUEUE_TYPE_INPUT
      - The queue is an input (read) queue.
    * - MRH_QUEUE_TYPE_OUTPUT
      - The queue is an output (write) queue.
    * - MRH_QUEUE_TYPE_MAX
      - The highest queue type in this enumeration.
    * - MRH_QUEUE_TYPE_COUNT
      - The amount of queue types in this enumeration.