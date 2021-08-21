MRH_OpenPipe
============
The MRH_OpenPipe function is used to create a pipe based event source.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/Source/MRH_SourcePipe.h"


Syntax
------
.. code-block:: c

    MRH_SourcePipe* MRH_OpenPipe(int i_FD);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - i_FD
      - The pipe end file descriptor.


Return Value
------------
The pipe source on success, NULL on failure.

Remarks
-------
None.

Code Examples
-------------
None.