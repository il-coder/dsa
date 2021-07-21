#include<bits/stdc++.h>
using namespace std;

void insert_element(int *arr,int *size, int element, int position)
{
	int i;
	for(i=*size;i>=position;i--)
	{
		arr[i] = arr[i-1];
	}
	arr[position-1] = element;
	*size = *size+1;
}

void delete_element(int arr[],int *size, int element)
{
	int i,pos=-1;
	for(i=0;i<(*size);i++)
	{
		if(arr[i]==element)
		{
			pos = i;
			break;
		}
	}
	if(pos==-1)
	{
		return;
	}
	else
	{
		for(i=pos;i<(*size-1);i++)
		{
			arr[i] = arr[i+1];
		}
		*size = *size-1;
	}
}

int search_element(int arr[],int size, int element)
{
	int i,pos=-1;
	for(i=0;i<size;i++)
	{
		if(arr[i]==element)
		{
			pos=i;
			break;
		}
	}
	return pos;
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
    int arr[100],i,n, pos,ele;
    // Input and traverse of array begin
    cout<<"Enter number of elements in array (<=50): ";
    cin>>n;
    cout<<"Enter array elements : ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    print_array(arr,n);
    cout<<endl;
    // Input and traverse of array end

    //Insertion begin
    cout<<"Enter position and element to insert : ";
    cin>>pos>>ele;
    insert_element(arr,&n,ele,pos);
    print_array(arr,n);
    cout<<endl;
    //insertion end

    //deletion begin
    cout<<"Enter element to delete : ";
    cin>>ele;
    delete_element(arr,&n,ele);
    print_array(arr,n);
    cout<<endl;
    //deletion end

    //linear search begin
    cout<<"Enter element to search : ";
    cin>>ele;
    pos = search_element(arr,n,ele);
    cout<<ele<<" found at "<<pos<<" index.\n";
    cout<<endl;
    //linear search end

	return 0;
}
