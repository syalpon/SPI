#コマンド宣言
GCC   = g++
CFLAG = -pthread
LINK  = -Xlinker -Map
SRCE  = object.cpp device.cpp master.cpp slave.cpp main.cpp
OBJS  = $(SRCE:%.cpp=%.o) 
EXE   = SPI


#コマンド実施
all:$(EXE)

$(EXE):$(OBJS)
	$(GCC) $(CFLAG) $(OBJS) $(LINK)=a.map -o a.exe

main.o:main.cpp
	$(GCC) -DDEBUG=$(DEBUG) -c $(CFLAG) main.cpp -o main.o

master.o:  master.cpp
	$(GCC) -c master.cpp -o master.o

slave.o:  slave.cpp
	$(GCC) -c slave.cpp -o slave.o

object.o:  object.cpp
	$(GCC) -c object.cpp -o object.o

device.o:   device.cpp
	$(GCC) -c device.cpp -o device.o

clean: 
	@rm -rf *.exe *.o *~ *.bak *.deps *.tgz .map

c:clean
	clean
