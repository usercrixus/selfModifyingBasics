# Compile and link :  
gcc cSelfModifying.c -o cSelfModifying -T linker.ld

# encrypt :  
python3 encryptSection.py 00000459 00000478 ./C/cSelfModifying  
arg 1 and 2 are found with :  
readelf -S cSelfModifying  
then check offset column of .encrypted :  
[ 7] .encrypted        PROGBITS         0000000000000459  00000459  
     000000000000001a  0000000000000000  AX       0     0     1  
[ 8] .rodata           PROGBITS         0000000000000478  00000478  
     0000000000000074  0000000000000000   A       0     0     8  


# launch :  
./cSelfModifyingEncrypted 
