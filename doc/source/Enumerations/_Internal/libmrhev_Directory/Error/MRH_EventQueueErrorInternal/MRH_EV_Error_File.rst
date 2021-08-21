MRH_EV_Error_File
=================
The MRH_EV_Error_File enumeration lists the file in which errors occured.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/Error/MRH_EventQueueErrorInternal.h"


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        // Default
        MRH_EV_ERROR_FILE_NONE = 0,
        
        // libmrhev/Error dir
        MRH_EV_ERROR_FILE_ERROR = 1,

        // libmrhev/Source dir
        MRH_EV_ERROR_FILE_SOURCE_MRHCKM = 2,
        MRH_EV_ERROR_FILE_SOURCE_PIPE = 3,

        // libmrhev dir
        MRH_EV_ERROR_FILE_QUEUE_UPDATE_MRHCKM = 4,
        MRH_EV_ERROR_FILE_QUEUE_UPDATE_PIPE = 5,

        // Root dir
        MRH_EV_ERROR_FILE_LIBMRHEV,
        
        // Bounds
        MRH_EV_ERROR_FILE_MAX = MRH_EV_ERROR_FILE_LIBMRHEV,

        MRH_EV_ERROR_FILE_COUNT = MRH_EV_ERROR_FILE_MAX + 1

    }MRH_EV_Error_File;


Values
------
The meaning behind the error enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_EV_ERROR_FILE_NONE
      - No error file to show.
    * - MRH_EV_ERROR_FILE_ERROR
      - An error occured in the error source file.
    * - MRH_EV_ERROR_FILE_SOURCE_MRHCKM
      - An error occured in the MRHCKM transmission source file.
    * - MRH_EV_ERROR_FILE_SOURCE_PIPE
      - An error occured in the pipe transmission source file.
    * - MRH_EV_ERROR_FILE_QUEUE_UPDATE_MRHCKM
      - An error occured in the MRHCKM update source file.
    * - MRH_EV_ERROR_FILE_QUEUE_UPDATE_PIPE
      - An error occured in the pipe update source file.
    * - MRH_EV_ERROR_FILE_LIBMRHEV
      - An error occured in the libmrhev source file.
    * - MRH_EV_ERROR_FILE_MAX
      - The highest error value in this enumeration.
    * - MRH_EV_ERROR_FILE_COUNT
      - The amount of error values in this enumeration.