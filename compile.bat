path = C:\MinGW\bin
gcc -c  main.c
gcc -c  spi.c
gcc -c  master.c
gcc -c  slave1.c
gcc -c  slave2.c
gcc -c  slave3.c
gcc -c  clock.c
gcc -c  data_io.c
gcc -o SPI main.o spi.o master.o slave1.o slave2.o slave3.o clock.o data_io.o -lpthread 
SPI.exe