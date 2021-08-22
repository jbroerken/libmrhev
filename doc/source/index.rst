libmrhev
========
.. image:: banner.png
   :align: center
   
The libmrhev library implements the means by which events are sent to and from 
the application and application service parent. It is also used to implement 
the event sending for the platform services. 

This library manages the given queue information from the MRH core and the reading 
and writing of the specified queue mechanisms. libmrhev also manages event queue 
limitations like, for example, the event send limit.

This documentation includes listings for the internal functions, enumerations, 
etc. used by the library itself. These are not meant to be used directly for 
service development but as information for library development.

As such, this documentation is both aimed at developers wanting to write their 
own user application service as well as library developers wishing to improve 
on the libmrhev source.

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   Building/Building
   Structs/Structs
   Enumerations/Enumerations
   Macros/Macros
   Functions/Functions
