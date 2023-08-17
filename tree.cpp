#include<iostream>

using namespace std;

class Node{
	int data;
	Node *left;
	Node *right;
	public:
	Node()
	{
		data=0;
		left=NULL;
		right=NULL;
	};
	Node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	};

	~Node()
	{};

	int getData()
	{
		return data;
	};
	void setData(int data)
	{
		this->data=data;
	};

	Node* getLeftPtr()
	{
		return this->left;
	};

	Node* getRightPtr()
	{
		return this->right;
	};

	void setLeftPtr(Node *element)
	{
		this->left = element;
	};

	void setRightPtr(Node *element)
	{
		this->right = element;
	};
};

class Tree
{
	Node *root;

	public:
	Node* getRoot()
	{
		return root;
	};

	Tree()
	{
		root=NULL;
	};

	~Tree()
	{};
	
	void insert()
	{
		int data;
		std::cout<<"enter number";
		std::cin>>data;
		Node *element =new Node(data);
		if(root==NULL)
		{
			root=element;
		}
		else
		{
			find_location_and_insert(element);
		}
	};
	void  find_location_and_insert(Node *element)
	{
		Node *tmp_root=getRoot();
		if(tmp_root->getData() == element->getData())
		{
			std::cout<<"element already exist";
			return;
		}
		else if(tmp_root->getData() > element->getData())
		{
			if(tmp_root->getLeftPtr() != NULL)
				move_left(tmp_root->getLeftPtr(), element);
			else
				tmp_root->setLeftPtr(element);
		}
		else if(tmp_root->getData() < element->getData())
		{
			if(tmp_root->getRightPtr() != NULL)
				move_right(tmp_root->getRightPtr(), element);
			else
				tmp_root->setRightPtr(element);
		}
		else
			std::cout<<"shit \n";
	};
	
	void move_left(Node *tmp_root, Node *element)
	{

		if(tmp_root->getData() == element->getData())
		{
			std::cout<<"element already exist";
			return;
		}
		else if(tmp_root->getData() > element->getData())
		{
			if(tmp_root->getLeftPtr() != NULL)
				move_left(tmp_root->getLeftPtr(), element);
			else
				tmp_root->setLeftPtr(element);
		}
		else if(tmp_root->getData() < element->getData())
		{
			if(tmp_root->getRightPtr() != NULL)
				move_right(tmp_root->getRightPtr(), element);
			else
				tmp_root->setRightPtr(element);
		}
		else
			std::cout<<"shit inside move left \n";
	};

	void move_right(Node *tmp_root, Node *element)
	{

		if(tmp_root->getData() == element->getData())
		{
			std::cout<<"element already exist";
			return;
		}
		else if(tmp_root->getData() > element->getData())
		{
			if(tmp_root->getLeftPtr() != NULL)
				move_left(tmp_root->getLeftPtr(), element);
			else
				tmp_root->setLeftPtr(element);
		}
		else if(tmp_root->getData() < element->getData())
		{
			if(tmp_root->getRightPtr() != NULL)
				move_right(tmp_root->getRightPtr(), element);
			else
				tmp_root->setRightPtr(element);
		}
		else
			std::cout<<"shit inside right\n";
	};

	void display()
	{
		Node *tmp_root=getRoot();
		std::cout<<"1) inorder 2) preorder 3) postorder\n";
	        int choise=0;
		std::cin>>choise;

		switch(choise)
		{
			case 1:
				traversal_inorder(tmp_root);
				break;
			case 2:
				traversal_preorder(tmp_root);
				break;
			case 3:
				traversal_postorder(tmp_root);
				break;
		}
	};

	void traversal_inorder(Node *tmp_root)
	{
		if(tmp_root==NULL)
			return ;
		else
		{
			traversal_inorder(tmp_root->getLeftPtr());
			std::cout<<"==>"<<tmp_root->getData();
			traversal_inorder(tmp_root->getRightPtr());
		}
	};
	void traversal_preorder(Node *tmp_root)
	{
		if(tmp_root==NULL)
			return ;
		else
		{
			std::cout<<"==>"<<tmp_root->getData();
			traversal_preorder(tmp_root->getLeftPtr());
			traversal_preorder(tmp_root->getRightPtr());
		}
	};

	void traversal_postorder(Node *tmp_root)
	{
		if(tmp_root==NULL)
			return ;
		else
		{
			traversal_postorder(tmp_root->getLeftPtr());
			traversal_postorder(tmp_root->getRightPtr());
			std::cout<<"==>"<<tmp_root->getData();
		}
	};


};


int main()
{
	Tree *root =new Tree();
	int select=0;
	while(1)
	{
	std::cout<<"1) insert 2)display 3)exit";
	std::cin>>select;
	switch(select)
	{
		case 1:
			root->insert();
			break;
		case 2:
			root->display();
			break;
		case 3:
			exit(0);
	}
	}
}
