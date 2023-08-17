#include<SingleNode.h>
using namespace std;

class Linked
{
	SingleNode *node;
	public:
		Linked()
		{
			node=NULL;
		};
		~Linked()
		{
		};
	void insert();
	void deleted();
	void display();
};
void Linked::insert()
{
	int data;
	std::cout<<"enter element";
	std::cin>>data;
	
	SingleNode *element= new SingleNode(data);
	
	if(this->node==NULL)
		this->node=element;
	else
	{
		SingleNode *iterator=this->node;;
		while(iterator->getNext() !=NULL)
			iterator= iterator->getNext();
		iterator->setNext(element);
	};

}

void Linked::deleted()
{
	int data=0;
	SingleNode *iterator=this->node;
	SingleNode *previous=this->node;
	std::cout<<"enter node you want to delete";
	std::cin>>data;

	if(this->node==NULL)
		std::cout<<"empty list\n";

	if(iterator->getData()==data)
	{
		this->node=iterator->getNext();
	}
	else
	{
		while(iterator->getNext() !=NULL && iterator->getData() !=data)
		{
			previous=iterator;
			iterator= iterator->getNext();
		}
		if(iterator->getData() ==data)
		{
			//if last element matches
			if(iterator->getNext() ==NULL)
			{
				delete previous->getNext();
				previous->setNext(NULL);
			}
			//for intermediate
			else if(iterator->getNext() !=NULL)
			{
				previous->setNext(iterator->getNext());
				delete iterator;
			}
		}
		else
		{
			std::cout<<"element not present in list\n";
		}

		
	}
}

void Linked::display()
{
	SingleNode *iterator =this->node;
	while(iterator!=NULL)
	{
		std::cout<<"==>"<<iterator->getData();
		if(iterator->getNext()!=NULL)
			iterator =iterator ->getNext();
		else
			break;
	}
}

int main()
{
	Linked *head=new Linked();;
	int choise =0;
	while(1)
	{
		printf("1) insert \t 2) delete \t 3) display \t 4) exit");	
		scanf("%d",&choise);
		switch (choise)
		{
			case 1:
				head->insert();
				break;
			case 2:
				head->deleted();
				break;
			case 3:
				head->display();
				break;
			case 4:
				exit(0);
				break;
			default:
			printf("invalid input\n");
		}
	}

	return 0;
}
