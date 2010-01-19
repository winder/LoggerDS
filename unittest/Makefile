
all: gasnode

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

clean:
	rm gasnodetest
