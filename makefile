CC=gcc
OBJ=obj
BIN=bin

obj/heap.o: src/heap.c src/heap.h 
	@[ -d $(OBJ) ] || mkdir -p $(OBJ)
	@${CC} -c -o obj/heap.o src/heap.c

obj/graph.o: src/graph.c src/graph.h 
	@[ -d $(OBJ) ] || mkdir -p $(OBJ)
	@${CC} -c -o obj/graph.o src/graph.c

bin/dijkstra: obj/heap.o obj/graph.o src/dijkstra.c
	@[ -d $(BIN) ] || mkdir -p $(BIN) 
	@${CC} -o bin/dijkstra obj/heap.o obj/graph.o src/dijkstra.c


test01: bin/dijkstra
	bin/dijkstra 0 d_files/d_input_01.txt
test02: bin/dijkstra
	bin/dijkstra 4 d_files/d_input_01.txt
test03: bin/dijkstra
	bin/dijkstra 0 d_files/d_input_02.txt
test04: bin/dijkstra
	bin/dijkstra 4 d_files/d_input_02.txt
test05: bin/dijkstra
	bin/dijkstra 0 d_files/d_input_03.txt
test06: bin/dijkstra
	bin/dijkstra 3 d_files/d_input_03.txt


clean:
	rm -f bin/dijkstra
	rm -f obj/heap.o
	rm -f obj/graph.o
	rm -f -d bin
	rm -f -d obj