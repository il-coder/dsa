/*
Algorithm for recursive solution of Tower of Hanoi
-------------------------------------------------------------------------------------------------------
Variables   N = number of disks
-------------------------------------------------------------------------------------------------------
TOH Function    if n==1
                    then print moved from src to dest
                    return
                move top n-1 disks from src to aux using dest i.e. call TOH(n-1,src,aux,dest)
                print moved from src to dest
                move top n-1 disks from aux to dest using src ie. call TOH(n-1,aux,dest,src)
-------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void TOH(int n,string src,string dest, string aux)
{
    if(n==1)
    {
        cout<<"Move disk 1 From "<<src<<" to "<<dest<<endl;
        return;
    }
    TOH(n-1,src,aux,dest);
    cout<<"Move disk "<<n<<" From "<<src<<" to "<<dest<<endl;
    TOH(n-1,aux,dest,src);
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int N;
	    cin>>N;
        TOH(N,"src","dest","aux");   //TOH(number,src,dest,aux)
	}
	return 0;
}
