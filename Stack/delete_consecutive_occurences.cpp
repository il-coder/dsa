#include<bits/stdc++.h>
using namespace std;

// Program to delete consecutive substring from given string using stack
int main()
{
    stack<char> st,temp;
    string s;
    cout<<"Enter string : ";//aaabccdaa
    cin>>s;
    for(int i=0;s[i];i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
        }
        else if(st.top()==s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    cout<<"Modified string is : ";
    while(!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    while(!temp.empty())
    {
        cout<<temp.top();
        temp.pop();
    }
    cout<<"\n";
 	return 0;
}
