#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,i;
	cin>>n>>k;
	ll arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	// if n is one and no. of operations is odd,
	// then it will always empty stack
	if(n==1 && k%2==1)
	{
		cout<<"-1"<<endl;
	}
	// if n is one and k is even, then always first element will be top
	else if(n==1)
	{
		cout<<arr[0]<<endl;
	}
	// if k==1 then always 2nd element will be top
	else if(k==1)
	{
		cout<<arr[1]<<endl;
	}
	// if n>1 and above conditions are false
	else
	{
		ll ma=0,a=0;
		// when k is less than n the kth element can't be at top
		// because only possibility to reach upto there will be to delete all elements including it
		// but in such case k+1th element can be at top
		// and all other elements from 1 to k-1 can be at top
		if(k<=n)
		{
			a=1;
			if(k<n && arr[k]>ma)
			{
				ma=arr[k];
			}
		}
		// if k>n, then all elements can be at top in different scenarios
		k = min(k,n);
		for(i=0;i<k-a;i++)
		{
			if(arr[i]>ma)
			{
				ma = arr[i];
			}
		}
		cout<<ma<<endl;
	}
	return 0;
}
