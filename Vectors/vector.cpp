#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> backup = nums;
        vector<int> myvector;
	std::sort(nums.begin(), nums.end());
        vector<int>::iterator it = nums.begin();
        vector<int>::iterator rev = nums.end() -1;
        while( *it + *rev != target)
        {
            if(*it + *rev >target)
                rev--;
            else if (*it + *rev < target)
                it++;
            
        }
        int first = *it;
        int second = *rev;

        int count1=0;
        int count2=0;
        for (auto &i :backup)
        {
            if(i == first)
                break;
            count1++;
        }

        for (auto &i :backup)
        {
	   
            if(i == second)
	    {	if(count1==count2)
		    {
			count2++;
		    	continue;
		    }
                break;
	    }
            count2++;
        }

        if(count1>count2)
        {
            myvector.push_back(count2);
            myvector.push_back(count1);
        }
        else
        {
            myvector.push_back(count1);
            myvector.push_back(count2);
        }

    return myvector;
    }
};
int main()
{
	Solution sol;
	//vector<int> nums {2,7,11,15};
	vector<int> nums {3,3};
	int target =6;
	//int target =9;
    	vector<int> vres = sol.twoSum(nums,target);
	std::cout<<"["<<*(vres.begin())<<std::endl;
	std::cout<<","<<*(vres.end() -1)<<"]"<<std::endl;
}
