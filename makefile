CCC = g++

CCFLAGS = -ansi

main: main.o userclass.o convert.o usercase.o admincase.o
	$(CCC) -o main main.o userclass.o convert.o usercase.o admincase.o

main.o:

userclass.o: userclass.h

convert.o: convert.h

usercase.o: usercase.h

admincase.o: AdminCase.h

clean:
	rm -f *.o

