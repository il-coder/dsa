#include<bits/stdc++.h>
using namespace std;

// Program to find number of elements to delete to get minimum element deleted
int main()
{
    stack<int> st,temp;
    int ch=1,ele;
    while(ch)
    {
        cout<<"Enter element to push : ";
        cin>>ele;   //9,6,8,3,5
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
    int cnt=0;
    while(st.top()!=temp.top())
    {
        st.pop();
        temp.pop();
        cnt++;
    }
    st.pop();temp.pop();
    cout<<"Number of elements to deleted : "<<cnt<<"\n";
    cout<<"Remaining Stack Elements are : ";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
        temp.pop();
    }
	return 0;
}
