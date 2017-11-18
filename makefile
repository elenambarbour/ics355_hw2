CCC = g++

CCFLAGS = -ansi

main: main.o userclass.o convert.o usercase.o AdminCase.o
	$(CCC) -o main main.o userclass.o convert.o usercase.o AdminCase.o

main.o:

userclass.o: userclass.h

convert.o: convert.h

usercase.o: usercase.h

AdminCase.o: AdminCase.h

clean:
	rm -f *.o

