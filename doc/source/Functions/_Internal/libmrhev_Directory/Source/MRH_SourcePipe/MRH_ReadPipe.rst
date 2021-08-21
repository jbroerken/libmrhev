MRH_ReadPipe
============
The MRH_ReadPipe function is used to read from a pipe event source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/Source/MRH_SourcePipe.h"


Syntax
------
.. code-block:: c

    ssize_t MRH_ReadPipe(MRH_SourcePipe* p_Pipe, 
                         MRH_Uint8* p_Data, 
                         MRH_Uint32 u32_Length);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Pipe
      - The pipe to read from.
    * - p_Data
      - The allocated buffer to read to.
    * - u32_Length
      - The length of the given allocated buffer.


Return Value
------------
The amount of bytes read on success, -1 on failure.

Remarks
-------
None.

Code Examples
-------------
None.