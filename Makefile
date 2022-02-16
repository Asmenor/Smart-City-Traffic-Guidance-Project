test:
	apt-get install libboost-all-dev
	g++ Source.cpp
	./a.out

clean:
	rm -f a.out