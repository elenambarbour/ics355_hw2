CCC = g++
CCFLAGS = -ansi

main: main.o userclass.o
	$(CCC) -o main main.o userclass.o

main.o:

userclass.o: userclass.h

clean:
	rm -f *.o

