CCC = g++
CCFLAGS = -ansi

main: main.o userclass.o convert.o usercase.o
	$(CCC) -o main main.o userclass.o convert.o usercase.o

main.o:

userclass.o: userclass.h

convert.o: convert.h

usercase.o: usercase.h

clean:
	rm -f *.o

