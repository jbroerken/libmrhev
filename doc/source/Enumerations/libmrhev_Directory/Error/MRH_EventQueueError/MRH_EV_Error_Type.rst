MRH_EV_Error_Type
=================
The MRH_EV_Error_Type enumeration lists the errors which can occur during 
library usage.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrhev/Error/MRH_EV_Error.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        // None
        MRH_EV_ERROR_NONE = -1,
        
        // General
        MRH_EV_ERROR_GENERAL_INVALID_PARAM = 1,
        MRH_EV_ERROR_GENERAL_MALLOC = 2,
        MRH_EV_ERROR_GENERAL_FREE = 3,
        MRH_EV_ERROR_GENERAL_SOURCE_OPEN = 3,
        MRH_EV_ERROR_GENERAL_SOURCE_CLOSED = 4,

        // MRHCKM
        // @TODO: Errors!

        // Pipe
        MRH_EV_ERROR_PIPE_CLOSE_FD,
        MRH_EV_ERROR_PIPE_POLL,
        MRH_EV_ERROR_PIPE_READ,
        MRH_EV_ERROR_PIPE_WRITE,
        
        // Bounds
        MRH_EV_ERROR_TYPE_MAX = MRH_EV_ERROR_PIPE_WRITE,

        MRH_EV_ERROR_TYPE_COUNT = MRH_EV_ERROR_TYPE_MAX + 1

    }MRH_EV_Error_Type;


Values
------
The meaning behind the error enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_EV_ERROR_NONE
      - No error occured.
    * - MRH_EV_ERROR_GENERAL_INVALID_PARAM
      - A parameter passed to a function is not usable.
    * - MRH_EV_ERROR_GENERAL_MALLOC
      - Memory allocation failed.
    * - MRH_EV_ERROR_GENERAL_FREE
      - Releasing of memory expected to exist failed.
    * - MRH_EV_ERROR_GENERAL_SOURCE_OPEN
      - Failed to open a new event source.
    * - MRH_EV_ERROR_GENERAL_SOURCE_CLOSED
      - Failed to close an already closed event source.
    * - MRH_EV_ERROR_PIPE_CLOSE_FD
      - Failed to close a pipe file descriptor.
    * - MRH_EV_ERROR_PIPE_POLL
      - Failed to poll a pipe file descriptor.
    * - MRH_EV_ERROR_PIPE_READ
      - Failed to read from a pipe file descriptor.
    * - MRH_EV_ERROR_PIPE_WRITE
      - Failed to write to a pipe file descriptor.
    * - MRH_EV_ERROR_TYPE_MAX
      - The highest error value in this enumeration.
    * - MRH_EV_ERROR_TYPE_COUNT
      - The amount of error values in this enumeration.