#include <iostream>
#include <vector>

using namespace std;

// compare subarray and merge
void merge(int start,int mid,int end,vector<int>& data)
{
    vector<int> temp(end-start+1,0);
    int i = start, j = mid+1, k = 0;
    
    while (i<=mid && j<=end)
    {
        if (data[i]<=data[j])
        {
            temp[k] = data[i];
            i++; k++;
        }
        else
        {
            temp[k] = data[j];
            j++; k++;
        }
    }
    while (i<=mid)
    {
        temp[k] = data[i];
        k++; i++;
    }
    while (j<=end)
    {
        temp[k] = data[j];
        k++; j++;
    }
    
    for (int i=start; i<=end; ++i)
    {
        data[i] = temp[i-start];
    }
}




//divide an array recursively until they aren't divisible anymore, and later compare and merge
//coverting unsorted list of length n to n sublist and later applying comparing and merging Logic
void mergeSort(int start, int end, vector<int>& data)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(start, mid,data);
        mergeSort(mid+1,end,data);
        merge(start,mid,end,data);
    }
}

int main()
{
    int arr[] = {-1,0,85,101,11,9,34,};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
    
    for (int i=0; i<nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    mergeSort(0,nums.size()-1,nums);
    for (int i=0; i<nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
