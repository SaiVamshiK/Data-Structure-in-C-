
Given a long vector of strings, print the strings that contain the strings generated by numeric string str.

string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
For example, if the input is 26 and the string is coding, then output should be coding since 26 can produce co which is contained in coding.

Input Format
A numeric string str

Constraints
len(str) < 10
No of strings in the vector < 10

Output Format
Each matched string from the given vector.

Sample Input
34
Sample Output
vidhi
divyam
sneha
Explanation
34 will result into combinations :

*dg         *eg         *fg
*dh            *eh         *fh
*di            *ei         *fi
Corresponding strings are output.

vidhi contains dh
divyam contains di
sneha contains eh

#include<bits/stdc++.h>
using namespace std;
string searchIn[11] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
};
string arr[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
// 0 and 1 ""
void func(string &str,int idx,int n,string &op,vector<string> &ans)
{
	if(idx==n)
	{
		ans.push_back(op);
		return ;
	}
	char cur=str[idx];
	int val=cur-'0'-2;
	string cur_str=arr[val];
	for(int i=0;i<(cur_str.size());i++)
	{
		char cur_ch=cur_str[i];
		op.push_back(cur_ch);
		func(str,idx+1,n,op,ans);
		op.pop_back();
	}
}
bool check(string s,string t)
{
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			string cur=s.substr(i,j-i+1);
			if(cur==t)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	string str;
	cin>>str;
	int n=str.size();
	string op="";
	vector<string> ans;
	func(str,0,n,op,ans);
	int k=11;
	bool *visited=new bool[k];
	for(int i=0;i<k;i++)
	{
		visited[i]=false;
	}
    vector<string> vec;
	for(int i=0;i<11;i++)
	{
		string cur=searchIn[i];
		for(int j=0;j<(ans.size());j++)
		{
			if(!visited[i])
			{
				if(check(cur,ans[j]))
				{
					visited[i]=true;
					vec.push_back(cur);
				}
			}
		}
	}
    reverse(vec.begin(),vec.end());
    for(int i=0;i<(vec.size());i++)
    {
        cout<<vec[i]<<endl;
    }
}

















