/*
Kadane's Algorithm
-------------------------------------------------------------------------------------------------------
This algorithm is used for finding maximum subarray sum efficiently in O(N) time and O(1) space.
Algorithm :

Step 1: Initialize max_so_far as INT_MIN and max_ending_here as 0 and start index and end index as 0
Step 2: Iterate over array and perform below steps for each element
Step 3: Add current element to max_ending_here
Step 4: If max_ending_here > max_so_far, then update max_so_far = max_ending_here
Step 5: If max_ending_here < 0, then update max_ending_here = 0
-------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void KadaneAlgo(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
       start =0, end = 0, s=0;

    for (int i=0; i< size; i++ )
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is "<< max_so_far << endl;
    cout << "Starting index "<< start << endl << "Ending index "<< end << endl;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int arr[]={-3,4,-5,-7,-2};
        KadaneAlgo(arr,5);
	}
	return 0;
}
