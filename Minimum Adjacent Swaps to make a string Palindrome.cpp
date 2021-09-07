#include<bits/stdc++.h>
using namespace std;
int fun(string s)
{
    map<char, int>mp;
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
    }
    int odd=0;
    char odd_one;
    for(auto i:mp)
    {
        if(i.second%2==1)
        {
            odd++;
            odd_one=i.first;
        }
        if(odd>1)
        {
            return -1;
        }
    }
    if(s.length()%2==0 && odd==1)
    {
        return -1;
    }

    int l, r;
    int ans=0;
    int odd_placed=0;

    for(int i=0;i<s.size()/2;i++)
    {
        l=i;
        r=s.size()-1-i;

        if(s[r]==s[l])
        {
            continue;
        }

        if(mp[s[l]]==1) //right fix
        {
            while(r>l)
            {
                if(s[r]==s[l])
                {
                    break;
                }
                l++;
            }
            for(int j=l;j>i;j--)
            {
                swap(s[j], s[j-1]);
                ans++;
            }
            mp[s[r]]-=2;
            cout<<s<<'\n';
            continue;
        }
        
        while(r>l)
        {
            if(s[r]==s[l])
            {
                break;
            }
            r--;
        }
        for(int k=r;k<s.size()-1-i;k++)
        {
            swap(s[k], s[k+1]);
            ans++;
        }
        mp[s[l]]-=2;
        cout<<s<<'\n';
    }
    return ans;
}
int solve(string s) {
    int ans1=fun(s);
    
    return ans1;
}
