MRH_WritePipe
=============
The MRH_WritePipe function is used to write to a pipe event source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/Source/MRH_SourcePipe.h"


Syntax
------
.. code-block:: c

    ssize_t MRH_WritePipe(MRH_SourcePipe* p_Pipe, 
                          const MRH_Uint8* p_Data, 
                          MRH_Uint32 u32_Length);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Pipe
      - The pipe to write to.
    * - p_Data
      - The data buffer to write.
    * - u32_Length
      - The length of the given data buffer.


Return Value
------------
The amount of bytes written on success, -1 on failure.

Remarks
-------
None.

Code Examples
-------------
None.