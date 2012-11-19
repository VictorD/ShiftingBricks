:: Sifteo Cleanup Script

:: Move to correct drive and dir
%~d1  
cd %1


del *.o
del *.d
del *.gen.*
del *.elf