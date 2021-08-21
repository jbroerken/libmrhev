MRH_SourcePipe
==============
The MRH_SourcePipe struct contains required information to work with a pipe 
based event queue.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/Source/MRH_SourcePipe.h"


Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
    * - i_FD
      - int
      - The pipe end file descriptor.
    * - s_PollFD
      - struct pollfd
      - The polling descriptor for the pipe.


Remarks
-------
None.