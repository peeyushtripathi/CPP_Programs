all: linkedList queue

linkedList: linkedList.o SingleNode.o
	g++ -o ./executables/linkedList linkedList.o SingleNode.o -I ./includes 
queue: queue.o SingleNode.o
	g++ -o ./executables/queue queue.o SingleNode.o -I ./includes 
linkedList.o: linkedList.cpp 
	g++ -c linkedList.cpp  linkedList.o -I ./includes 
queue.o: queue.cpp 
	g++ -c queue.cpp  queue.o -I ./includes 
SingleNode.o: SingleNode.cpp 
	g++ -c SingleNode.cpp -I SingleNode.o -I ./includes 

clean:
	rm *.o ./executables/*
