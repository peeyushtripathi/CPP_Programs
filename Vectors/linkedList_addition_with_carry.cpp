#include<iostream>
#include<vector>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	    int carry=0;
        ListNode *l3 =new ListNode(l1->val +l2->val +carry,nullptr);
	if(l3->val >9)
	{
		l3->val=l3->val-10;
		carry=1;
	}
        ListNode *parent= l3;
        ListNode *tmp =nullptr;

        while(1)
        {
            if(l1->next!=nullptr || l2->next !=nullptr)
	    {
                if(l1->next !=nullptr)
                {
                    l1=l1->next;
                    if(l2->next !=nullptr)
                    {
                        l2=l2->next;
                        tmp =new ListNode(l1->val +l2->val +carry,nullptr);
			if(tmp->val >9)
			{
				tmp->val=tmp->val-10;
				carry=1;
			}
			else 
				carry=0;
                        parent->next=tmp;
			parent=parent->next;
                        

                    }
                    else
                    {
                        while(l1->next !=nullptr)
                        {
                            tmp =new ListNode(l1->val +carry,nullptr);
			if(tmp->val >9)
			{
				tmp->val=tmp->val-10;
				carry=1;
			}
			else 
				carry=0;
                             parent->next=tmp;
				parent=parent->next;

                        }
                        break;
                    }
                }
                else if(l2->next !=nullptr)
                {
                    l2=l2->next;
                    if(l1->next !=nullptr)
                    {
                        l1=l1->next;
                        tmp =new ListNode(l1->val +l2->val +carry,nullptr);
			if(tmp->val >9)
			{
				tmp->val=tmp->val-10;
				carry=1;
			}
			else 
				carry=0;
                        parent->next=tmp;
			parent=parent->next;
                        

                    }
                    else
                    {
                        while(l2->next !=nullptr)
                        {
                            tmp =new ListNode(l2->val +carry,nullptr);
			if(tmp->val >9)
			{
				tmp->val=tmp->val-10;
				carry=1;
			}
			else 
				carry=0;
                             parent->next=tmp;
			parent=parent->next;

                        }
                        break;
                    }
                }
	    }

            else
                {
                    break;
                }
        }
	if (carry == 1)
	{
		tmp =new ListNode(carry,nullptr);
		parent->next=tmp;
	}

        return l3;

    }
};

int main()
{
	Solution s;
    ListNode* l1= new ListNode(2);
    ListNode * parent=l1;
    ListNode * tmp=nullptr;
    vector<int> vec1 {4,3};
	for( auto &i : vec1)
	{
		tmp=new ListNode(i,nullptr);
		parent->next=tmp;
		parent=parent->next;
	}

    ListNode* l2= new ListNode(1);
    ListNode * parent2=l2;
    ListNode * tmp2=nullptr;
    vector<int> vec2 {6,7};
	for( auto &i : vec2)
	{
		tmp2=new ListNode(i,nullptr);
		parent2->next=tmp2;
		parent2=parent2->next;
	}

    ListNode* res =s.addTwoNumbers(l1, l2);
	    while(res !=NULL)
	    {
		    std::cout<<"--"<<res->val<<std::endl;
		    res=res->next;
	    }
	    return 0;
}
