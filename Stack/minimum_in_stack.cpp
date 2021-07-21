#include<bits/stdc++.h>
using namespace std;

// Program to find minimum element from stack
int main()
{
    stack<int> st,temp;
    int ch=1,ele;
    while(ch)
    {
        cout<<"Enter element to push : ";
        cin>>ele;
        st.push(ele);
        if(temp.empty())
        {
            temp.push(ele);
        }
        else
        {
            if(ele<=temp.top())
            {
                temp.push(ele);
            }
            else
            {
                temp.push(temp.top());
            }
        }
        cout<<"Enter more element : ";
        cin>>ch;
    }
    cout<<"Minimum element : "<<temp.top()<<"\n";
	return 0;
}
