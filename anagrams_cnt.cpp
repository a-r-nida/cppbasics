#include<iostream>
#include<conio.h>
#include<unordered_map>
using namespace std;
int solve(string s,string ana)
{
    unordered_map <char,int> m;
    for(auto it:ana) m[it]++;
    int k=ana.length();
    int count=m.size();
    int i=0,j=0;
    int ans=0;
    while(j<s.length())
    {
        if(m.find(s[j])!=m.end())
        {
            m[s[j]]--;
            if(m[s[j]]==0)count--;
        }
        if((j-i+1)<k)j++;
        else if((j-i+1)==k)
        {
            if(count==0)ans++;
            if(m.find(s[i])!=m.end())
            {
                m[s[i]]++;
                if(m[s[i]]==1)count++;
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    string s="forxxfroxdofr";
    string ana="for";
    int ans=solve(s,ana);
    cout<<ans;
    return 0;
}
