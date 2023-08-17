#include<SingleNode.h>

SingleNode::SingleNode()
{
	data=0;
	next=NULL;
};

SingleNode::~SingleNode()
{
};

SingleNode::SingleNode(int data)
{
	this->data=data;
	this->next=NULL;
};

int SingleNode::getData()
{
	return this->data;
};

void SingleNode::setData(int data)
{
	this->data=data;
};

SingleNode* SingleNode::getNext()
{
	return this->next;
};

void SingleNode::setNext(SingleNode *nextval)
{
	this->next= nextval;
};
