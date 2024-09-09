all: a1

a1: Date.o Reservation.o Room.o Hotel.o main.cc
	g++ -o a1 Date.o Reservation.o Room.o Hotel.o main.cc


Date.o: Date.h Date.cc
	g++ -c Date.cc

Reservation.o: Reservation.h Reservation.cc
	g++ -c Reservation.cc

Room.o: Room.cc Room.h
	g++ -c Room.cc

Hotel.o: Hotel.h Hotel.cc
	g++ -c Hotel.cc

clean:
	rm -f *.o a1
