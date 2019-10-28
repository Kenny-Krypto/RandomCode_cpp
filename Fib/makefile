func = fib
Mak = source
all: $(func)L.o $(func)R.o $(Mak).o
	g++ $(func)L.o $(func)R.o $(Mak).o -o MSource

$(Mak).o: $(Mak).cpp
	g++ -c $(Mak).cpp

$(func).o: $(func)L.cpp $(func)R.cpp $(func).h
	g++ -c $(func)L.cpp
	g++ -c $(func)R.cpp

clean:
	rm -f *.o MSource