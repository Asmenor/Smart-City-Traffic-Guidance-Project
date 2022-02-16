test:
	./run.sh libboost-all-dev
	g++ Source.cpp
	./a.out
clean:
	rm -f a.out