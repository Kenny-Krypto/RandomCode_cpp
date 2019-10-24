Mak = MatCal
func = Mat_
all: $(Mak).o $(func)Addition.o $(func)Control.o $(func)Determ.o $(func)Inverse.o $(func)Muti.o $(func)ScarMuti.o $(func)Trans.o
	g++ $(Mak).o $(func)Addition.o $(func)Control.o $(func)Determ.o $(func)Inverse.o $(func)Muti.o $(func)ScarMuti.o $(func)Trans.o -g -o MSource

$(Mak).o: $(Mak).cpp
	g++ -g -c $(Mak).cpp

$(func)Addition.o: $(func)Addition.cpp $(Mak).h
	g++ -g -c $(func)Addition.cpp

$(func)Control.o: $(func)Control.cpp $(Mak).h
	g++ -g -c $(func)Control.cpp

$(func)Determ.o: $(func)Determ.cpp $(Mak).h
	g++ -g -c $(func)Determ.cpp

$(func)Inverse.o: $(func)Inverse.cpp $(Mak).h
	g++ -g -c $(func)Inverse.cpp

$(func)Muti.o: $(func)Muti.cpp $(Mak).h
	g++ -g -c $(func)Muti.cpp

$(func)ScarMuti.o: $(func)ScarMuti.cpp $(Mak).h
	g++ -g -c $(func)ScarMuti.cpp

$(func)Trans.o: $(func)Trans.cpp $(Mak).h
	g++ -g -c $(func)Trans.cpp

clean:
	rm -f *.o MSource