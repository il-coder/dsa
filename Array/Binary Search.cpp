#include<bits/stdc++.h>
using namespace std;

//code for binary search
int binary_search_my(int *arr, int n, int element)
{
	int l,h,mid;
	l=0;
	h=n-1;
	while(l<=h)
	{
		mid = (l+h)/2;
		if(arr[mid]==element)
		{
			return mid;
		}
		else if(arr[mid]>element)
		{
			h = mid-1;
		}
		else
		{
			l = mid+1;
		}
	}
	return -1;
}

void print_array(int arr[],int size)
{
    cout<<"Array : ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//main() function starts here

int main()
{
    int arr[100],i,n,q,ans,ele;
    // Input and traverse of array begin
    cout<<"Enter number of elements in array (<=50): ";
    cin>>n;
    cout<<"Enter array elements (sorted) : ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    print_array(arr,n);
    cout<<endl;
    // Input and traverse of array end

    //search begin
    cout<<"Enter number of queries : ";
    cin>>q;
    while(q--)
    {
        cout<<"\n";
        cout<<"Enter element to search : ";
        cin>>ele;
        ans = binary_search_my(arr,n,ele);
        if(ans!=-1)
        {
            cout<<ele<<" found at "<<ans+1<<" position.";
        }
        else
        {
            cout<<"Element not found";
        }
        cout<<endl;
    }
    //searching ends

	return 0;
}
