#include<bits/stdc++.h>
using namespace std;

//reverse a stack using temporary stack
int main()
{
	stack<int> st,temp;
    st.push(10);
    st.push(15);
    st.push(18);
    st.push(22);
    st.push(25);
    st.push(32);
    cout<<"Given stack is : ";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        temp.push(st.top());
        st.pop();
    }
    cout<<"\n";
    cout<<"Reversed stack is : ";
    st = temp;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
	return 0;
}
