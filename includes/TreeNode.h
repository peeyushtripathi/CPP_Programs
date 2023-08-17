#include<iostream>
using namespace std;

class TreeNode{
        int data;
        TreeNode *left;
        TreeNode *right;
        public:
        TreeNode();
        TreeNode(int data);
        ~TreeNode();
        int getData();
        void setData(int data);
        TreeNode* getLeftPtr();
        TreeNode* getRightPtr();
        void setLeftPtr(TreeNode *element);
        void setRightPtr(TreeNode *element);
};

