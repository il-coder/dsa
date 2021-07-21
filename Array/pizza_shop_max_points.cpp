/*
Boy named John
John select pizza shop based on best


We are given with Count of shops = 3
Pizzahut - 116
Pizzaria = 155
Pizzahouse - 65

O/p the Name of shop with maximum point. If two shops have same point, print one with smaller in alphabetic order.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,score,maxScore = 0;
        cin>>n;
        string s,ans="";
        for(i=0;i<n; i++)
        {
            cin>>s;
            cin>>score;
            if(score > maxScore)
            {
                maxScore = score;
                ans = s;
            }
            else if(score == maxScore && s < ans)
            {
                ans = s;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
