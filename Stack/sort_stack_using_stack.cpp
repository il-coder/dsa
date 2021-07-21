#include<bits/stdc++.h>
using namespace std;

//sort a stack using temporary stack
void printStack(stack<int> st1)
{
    if(st1.empty())
    {
        cout<<"EMPTY\n";
        return;
    }
    while(!st1.empty())
    {
        cout<<st1.top()<<" ";
        st1.pop();
    }
    cout<<"\n";
}

int main()
{
	stack<int> st,temp;
    st.push(10);
    st.push(25);
    st.push(32);
    st.push(17);
    st.push(22);
    st.push(5);
    st.push(20);
    st.push(5);
    st.push(105);
    st.push(55);
    cout<<"Given stack is : ";
    printStack(st);
    while(!st.empty())
    {
        if(temp.empty())    //if temp stack is empty, just push the element
        {
            temp.push(st.top());
            st.pop();
        }
        else if(st.top()>=temp.top())   //if top of temp is less than top of st, then just push into temp
        {
            temp.push(st.top());
            st.pop();
        }
        else    //if top of temp > top of st, then push at appropriate position
        {
            int val = st.top();
            st.pop();
            while(!temp.empty() && temp.top()>val )
            {
                st.push(temp.top());
                temp.pop();
            }
            temp.push(val);
        }
    }
    while(!temp.empty())    // to print in ascending order
    {
        st.push(temp.top());
        temp.pop();
    }
    cout<<"Sorted Stack is : ";
    printStack(st);

	return 0;
}
