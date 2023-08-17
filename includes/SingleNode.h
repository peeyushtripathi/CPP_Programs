#include<iostream>

using namespace std;

class SingleNode
{
	private:
	int data;
	SingleNode *next;

	public:
	SingleNode();
	~SingleNode();
	SingleNode(int);
	int getData();
	void setData(int);
	SingleNode* getNext();
	void setNext(SingleNode *);
};
