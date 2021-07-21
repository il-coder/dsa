#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;
	//cin>>t;
	//while(t--)
	{
		int n,m,i,j,ans=0,d=-1;
		cin>>n>>m>>g;
		int arr[m],a,b=0;

		//Our motive is to find maximum time gap between two successive time because we can collect all clothes whose drying time is less than  or equal to
		//this maximum time gap and we can do this because there is no limit on number of dry clothes collected at a time

		for(i=0;i<n;i++)
		{
			cin>>a; //a to store current rain time
			if(i>0)
			{
				if(a-b>d)
                {
                    d = a - b;
                }
			}
			b=a; //to store previous rain time
		}
		for(i=0;i<m;i++)
		{
			cin>>arr1[i];   //input of drying time of m clothes
		}
		for(i=0;i<m;i++)
		{
		    if(arr1[i]<=d) //if time taken to dry is less than or equal to maximum time gap between rains
            {
                ans++;
            }
		}
		cout<<ans<<endl;
	}
	return 0;
}
