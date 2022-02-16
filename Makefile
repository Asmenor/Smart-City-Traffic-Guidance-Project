test:
	./check_dep.sh libboost-all-dev
	g++ _src/Source.cpp
	./a.out
clean:
	rm -f a.out