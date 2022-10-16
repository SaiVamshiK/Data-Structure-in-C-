
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. 
The same number may be chosen from the array any number of times to make B.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, �, ak) must be in non-descending order. (ie, a1 = a2 = � = ak).
        3. The combinations themselves must be sorted in ascending order.


Example 1:

Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)
Example 2:

Input:
N = 11
arr[] = {6,5,7,1,8,2,9,9,7,7,9}
B = 6
Output:
(1 1 1 1 1 1)
(1 1 1 1 2)
(1 1 2 2)
(1 5)
(2 2 2)
(6)

class Solution {
  public:
    
    void func(vector<int> &inp,int idx,int n,int sum,vector<int> &op,vector<vector<int>> &ans)
    {
        if(sum==0)
        {
            ans.push_back(op);
            return ;
        }
        if(idx==n)
        {
            return ;
        }
        int cur=inp[idx];
        if(cur<=sum)
        {
            op.push_back(cur);
            func(inp,idx,n,sum-cur,op,ans);
            op.pop_back();
            func(inp,idx+1,n,sum,op,ans);
        }
    }
    vector<vector<int> > combinationSum(vector<int> &ini, int sum) {
        set<int> st;
        for(int i=0;i<(ini.size());i++)
        {
            st.insert(ini[i]);
        }
        vector<int> inp;
        for(auto it=st.begin();it!=st.end();it++)
        {
            inp.push_back((*it));
        }
        int n=inp.size();
        vector<int> op;
        vector<vector<int>> ans;
        func(inp,0,n,sum,op,ans);
        return ans;
    }
};
