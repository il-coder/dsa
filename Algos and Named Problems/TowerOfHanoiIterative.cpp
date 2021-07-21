/*
Algorithm for Iterative solution of Tower of Hanoi
-------------------------------------------------------------------------------------------------------
Variables   N = number of disks
            n = number of movements = 2^N - 1
            src = Source stack (1)
            aux = Auxiliary stack (2)
            dest = Destiantion stack (3)
-------------------------------------------------------------------------------------------------------
Helping Function    move(stack1,stack2,i,j)
                    It move disk from stack1 to stack2 or vice versa according to situation.

                    If stack1 is empty, push TOP(stack2) into stack1 and pop.
                    else if stack2 is empty, push TOP(stack1) into stack2 and pop.
                    else if TOP(stack1) > TOP(stack2) then push TOP(stack2) into stack1 and pop.
                    else if TOP(stack2) > TOP(stack1) then push TOP(stack1) into stack2 and pop.
-------------------------------------------------------------------------------------------------------
Main Function       Case 1: N is even
                        Start from move 1 to n:
                            if move%3==1
                                then move from src to aux or vice versa
                            else if move%3==2
                                then move from src to dest or vice versa
                            else if move%3==0
                                then move from aux to dest or vice versa

                    Case 2: N is Odd
                        Start from move 1 to n:
                            if move%3==1
                                then move from src to dest or vice versa
                            else if move%3==2
                                then move from src to aux or vice versa
                            else if move%3==0
                                then move from aux to dest or vice versa
-------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void move(stack<int> &src, stack<int> &dest,string i,string j)
{
    if(src.empty())
    {
        cout<<"Move disk "<<dest.top()<<" from "<<j<<" to "<<i<<endl;
        src.push(dest.top());
        dest.pop();
    }
    else if(dest.empty())
    {
        cout<<"Move disk "<<src.top()<<" from "<<i<<" to "<<j<<endl;
        dest.push(src.top());
        src.pop();
    }
    else if(src.top()>dest.top())
    {
        cout<<"Move disk "<<dest.top()<<" from "<<j<<" to "<<i<<endl;
        src.push(dest.top());
        dest.pop();
    }
    else if(dest.top() > src.top())
    {
        cout<<"Move disk "<<src.top()<<" from "<<i<<" to "<<j<<endl;
        dest.push(src.top());
        src.pop();
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int N,n,i,total;
	    cin>>N;
	    n = pow(2,N) - 1;
	    stack<int> src,dest,aux;
	    for(i=n;i>=1;i--)
	    {
	        src.push(i);
	    }
	    if(N%2==0)
	    {
	        for(i=1;i<=n;i++)
    	    {
    	        if(i%3==1)
    	        {
    	            move(src,aux,"src","aux");
    	        }
    	        else if(i%3==2)
    	        {
    	            move(src,dest,"src","dest");
    	        }
    	        else
    	        {
    	            move(aux,dest,"aux","dest");
    	        }
    	    }
	    }
	    else
	    {
	        for(i=1;i<=n;i++)
    	    {
    	        if(i%3==1)
    	        {
    	            move(src,dest,"src","dest");
    	        }
    	        else if(i%3==2)
    	        {
    	            move(src,aux,"src","aux");
    	        }
    	        else
    	        {
    	            move(aux,dest,"aux","dest");
    	        }
    	    }
	    }
	}
	return 0;
}
