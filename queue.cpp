#include<SingleNode.h>

using namespace std;


class Queue
{
	SingleNode *front;
	SingleNode *rear;

	public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	};

	~Queue()
	{
	};

	void enqueue();
	void dequeue();
	void display();


};

void Queue::enqueue()
	{
		SingleNode *element =new SingleNode();
		std::cout<<"enter element";
		int data;
		std::cin>>data;
		element->setData(data);

		if(front == NULL && rear ==NULL)
		{
			rear=element;
			front=element;
		}
		else
		{
			rear->setNext(element);
			rear=element;
		}

	};


void Queue::dequeue()
	{
		if(front == NULL)
		{
			std::cout<<"empty\n";
			return;
		}
		else if(front == rear)
		{
			std::cout<<"deleted element is"<<front->getData();
			delete front;
			front = NULL;
			rear =NULL;
		}
		else 
		{
			SingleNode *tmp_front=front;
			std::cout<<"deleted element is"<<tmp_front->getData();
			front=front->getNext();
			delete tmp_front;	
		}
	};


void Queue::display()
	{
		std::cout<<"elements in queue are";
		SingleNode *tmp_front=front;
		while(tmp_front!=rear)
		{
			std::cout<<tmp_front->getData()<<" ";
			tmp_front=tmp_front->getNext();

		}
		if(tmp_front == NULL && rear == NULL)
		{
			return ;
		}
		else if (tmp_front ==rear)
		{

			std::cout<<tmp_front->getData()<<" ";
		}
	};



int main()
{
	Queue *head= new Queue();;
	int choise =0;
	while(1)
	{
		printf("1) inqueue \t 2) dequeue \t 3) display \t 4) exit");	
		scanf("%d",&choise);
		switch (choise)
		{
			case 1:
				head->enqueue();
				break;
			case 2:
				head->dequeue();
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
