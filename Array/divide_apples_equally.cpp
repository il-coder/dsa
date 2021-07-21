/*
Ques.:-
There are certain boys M sitting in a circle.
Each boy has apples (distribution given) in his hand.
Divide all apples equally.
O/p the minimum steps if only one apple can be shared at one step.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,i,ans=0,sum=0,eqDiv = 0,j,k;
        cin>>n;
        long long int arr[n];
        for(i=0;i<n; i++)
        {
            cin>>arr[i];
            sum += arr[i];
        }
        eqDiv = sum/n;
        for(i=0;i<n;i++)
        {
            if(arr[i] < eqDiv)
            {
                j = (i-1+n)%n;
                k = (i+1)%n;
                //cout<<"j = "<<j<<" k = "<<k<<endl;
                while(arr[i] < eqDiv)
                {
                    int diff1 = min(abs(j-i),abs(n-j+i));
                    int diff2 = min(abs(k-i),abs(n-k+i));
                    //cout<<"i = "<<i<<" "<<diff1<<" "<<diff2<<endl;
                    if(diff1 <= diff2)
                    {
                        if(arr[j] > eqDiv )
                        {
                            int temp = min(eqDiv - arr[i], arr[j]-eqDiv);
                            ans += diff1*temp;
                            arr[i]+=temp;
                            arr[j]-=temp;
                            continue;
                        }
                        else
                        {
                            j = (j-1+n)%n;
                        }
                    }
                    else
                    {
                        if(arr[k] > eqDiv)
                        {
                            int temp = min(eqDiv - arr[i], arr[k]-eqDiv);
                            ans += diff2*temp;
                            arr[i]+=temp;
                            arr[k]-=temp;
                            continue;
                        }
                        else
                        {
                            k = (k+1)%n;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
