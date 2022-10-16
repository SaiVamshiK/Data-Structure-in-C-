
Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the 
array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, 
next greater of the last element is always -1.

Example 1:

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.
 
typedef long long ll;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> a, int n){
        stack<ll> st;
        vector<ll> ans;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                ans.push_back(-1);
                st.push(a[i]);
            }else{
                ll cur=a[i];
                while((!st.empty())&&(st.top()<=cur))
                {
                    st.pop();
                }
                if(st.empty())
                {
                    ans.push_back(-1);
                    st.push(a[i]);
                }else{
                    ans.push_back(st.top());
                    st.push(a[i]);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
