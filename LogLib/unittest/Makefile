
all: gasnode gymnode

gasnode:
	cp ../source/Node.h .
	cp ../source/Node.cpp .
	cp ../source/GasNode.h .
	cp ../source/GasNode.cpp .
	g++ gasnodetest.cpp Node.cpp GasNode.cpp -o gasnodetest
	rm Node.h
	rm Node.cpp
	rm GasNode.h
	rm GasNode.cpp

gymnode:
	cp ../source/Node.h .
	cp ../source/Node.cpp .
	cp ../source/GymNode.h .
	cp ../source/GymNode.cpp .
	g++ gymnodetest.cpp Node.cpp GymNode.cpp -o gymnodetest
	rm Node.h
	rm Node.cpp
	rm GymNode.h
	rm GymNode.cpp

clean:
	rm gasnodetest
	rm gymnodetest
