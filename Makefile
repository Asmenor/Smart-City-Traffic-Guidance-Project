test:
	g++ Source.cpp packages
	./a.out
packages:
	sudo apt-get install libboost-all-dev
clean:
	rm -f a.out