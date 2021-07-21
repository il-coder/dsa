#include<bits/stdc++.h>
using namespace std;

/*

arr = array of integers
n = either add or subtract nth element of array
ns = number of additions performed
nss = number of subtractions performed
sum = current sum upto now by performing addition/subtraction
*/

/*
Why abs(ns-nss)<=1 ?
Because divisibility rule says add alternate elements. So either additions and subtractions are equal (if number of digits even)
or they differ by one (in case of odd number of digits.
*/

/*
How recursion is working ?
Recursion is doing all possibility starting from right of array to left.
One is to add current element to sum and increment number of additions i.e. ns+1.
Second is to subtract element from sum and increment number of subtractions i.e. nss+1.
Now if in any case, if sum%11 is equal to 0 and abs(ns-nss)<=1, then it is possible to have multiple of 11 as per divisibility rule.
*/

bool isDiv(int arr[], int n, int ns, int nss, int sum)
{
    if(n<0)
    {
        if(sum%11 == 0 && abs(ns-nss) <= 1)
        {
            return true;
        }
        return false;
    }
    return isDiv(arr,n-1,ns+1,nss,sum+arr[n])||isDiv(arr,n-1,ns,nss+1,sum-arr[n]);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(isDiv(arr,n-1,0,0,0))
        {
            cout<<"Divisible by 11\n";
        }
        else
        {
            cout<<"Not divisible by 11\n";
        }
    }
    return 0;
}
