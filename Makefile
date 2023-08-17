all: linkedList queue tree

linkedList: linkedList.o SingleNode.o
	g++ -o ./executables/linkedList linkedList.o SingleNode.o -I ./includes 

queue: queue.o SingleNode.o
	g++ -o ./executables/queue queue.o SingleNode.o -I ./includes 

tree: tree.o TreeNode.o
	g++ -o ./executables/tree tree.o TreeNode.o -I ./includes 



linkedList.o: linkedList.cpp 
	g++ -c linkedList.cpp  linkedList.o -I ./includes 
queue.o: queue.cpp 
	g++ -c queue.cpp  queue.o -I ./includes 
tree.o: tree.cpp 
	g++ -c tree.cpp  tree.o -I ./includes 



SingleNode.o: SingleNode.cpp 
	g++ -c SingleNode.cpp -I SingleNode.o -I ./includes 
TreeNode.o: TreeNode.cpp 
	g++ -c TreeNode.cpp  TreeNode.o -I ./includes 


clean:
	rm *.o ./executables/*
