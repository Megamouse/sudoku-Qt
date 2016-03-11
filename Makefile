objects = rdarray.o matrix.o exmat.o

main : $(objects)
	g++ -o main $(objects)

rdarray.o : rdarray.h
	g++ -c rdarray.cc

matrix.o : matrix.h rdarray.h
	g++ -c matrix.cc

exmat.o : include.h matrix.h rdarray.h
	g++ -c exmat.cc

.PHONY : clean
clean :
	-rm $(objects)
