#include<iostream>
using namespace std;

class Node
{
	int data;
	struct Node *next;

	public:
	Node()
	{
		data=0;
		next=NULL;
	};
	Node(int data)
	{
		this->data=data;
		this->next=NULL;
	};

	Node *getnext()
	{
		return this->next;
	};
	void setnext(Node *node)
	{
		this->next=node;
	};
	int getdata()
	{
		return this->data;
	};
	void setdata(int data)
	{
		this->data=data;
	};
	~Node()
	{
	};
};
class Linked
{
	Node *node;
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
	
	Node *element= new Node(data);
	
	if(this->node==NULL)
		this->node=element;
	else
	{
		Node *iterator=this->node;;
		while(iterator->getnext() !=NULL)
			iterator= iterator->getnext();
		iterator->setnext(element);
	};

}

void Linked::deleted()
{
	int data=0;
	Node *iterator=this->node;
	Node *previous=this->node;
	std::cout<<"enter node you want to delete";
	std::cin>>data;

	if(this->node==NULL)
		std::cout<<"empty list\n";

	if(iterator->getdata()==data)
	{
		this->node=iterator->getnext();
	}
	else
	{
		while(iterator->getnext() !=NULL && iterator->getdata() !=data)
		{
			previous=iterator;
			iterator= iterator->getnext();
		}
		if(iterator->getdata() ==data)
		{
			//if last element matches
			if(iterator->getnext() ==NULL)
			{
				delete previous->getnext();
				previous->setnext(NULL);
			}
			//for intermediate
			else if(iterator->getnext() !=NULL)
			{
				previous->setnext(iterator->getnext());
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
	Node *iterator =this->node;
	while(iterator!=NULL)
	{
		std::cout<<"==>"<<iterator->getdata();
		if(iterator->getnext()!=NULL)
			iterator =iterator ->getnext();
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
