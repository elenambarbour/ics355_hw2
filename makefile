CCC = g++

CCFLAGS = -ansi

main: main.o userclass.o convert.o usercase.o admincase.o md5.o
	$(CCC) -o main main.o userclass.o convert.o usercase.o admincase.o md5.o

md5: md5main.o md5.o
	$(CCC) -o md5 md5main.o md5.o

main.o:

userclass.o: userclass.h

convert.o: convert.h

usercase.o: usercase.h

admincase.o: admincase.h

md5.o: md5.h

clean:
	rm -f *.o

