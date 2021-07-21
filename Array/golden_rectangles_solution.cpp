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
		int n,h,i,w,ans=0;
		double r;
		const double l=1.6,u=1.7;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>w>>h;
			if(w<h)
            {
                int temp = w;
                w = h;
                h = temp;
            }
            r = (double)w/(double)h;
            if(r>=l && r<=u)
            {
                ans++;
            }
		}
		cout<<ans<<endl;
	}
	return 0;
}
