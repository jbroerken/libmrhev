MRH_PollPipe
============
The MRH_PollPipe function is used to check a pipe source for event data by 
polling.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhev/Source/MRH_SourcePipe.h"


Syntax
------
.. code-block:: c

    int MRH_PollPipe(MRH_SourcePipe* p_Pipe, 
                     int i_Event, 
                     int i_TimeoutMS);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Pipe
      - The pipe to poll.
    * - i_Event
      - The polling event to use (POLLIN, etc).
    * - i_TimeoutMS
      - The poll timeout in milliseconds.


Return Value
------------
0 if event data is available to read, -1 on no event data or failure.

Remarks
-------
* All timeout timers lower than 0 will be corrected to 0.
* The polling call is blocking.

Code Examples
-------------
None.