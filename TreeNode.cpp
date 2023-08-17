#include<TreeNode.h>

TreeNode::TreeNode()
{
        data=0;
        left=NULL;
        right=NULL;
};

TreeNode::TreeNode(int data)
{
        this->data=data;
        left=NULL;
        right=NULL;
};

TreeNode::~TreeNode(){};

int TreeNode::getData()
{
        return data;
};

void TreeNode::setData(int data)
{
        this->data=data;
};
TreeNode* TreeNode::getLeftPtr()
{
	return this->left;
};

TreeNode* TreeNode::getRightPtr()
{
        return this->right;
};

void TreeNode::setLeftPtr(TreeNode *element)
{
        this->left = element;
};

void TreeNode::setRightPtr(TreeNode *element)
{
        this->right = element;
};

