#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int partition(int start, int end, vector<int>& nums)
{
    int i = start,j = start;
    int pivot = nums[end];
    for (; j<end; ++j)
    {
        if (nums[j] < pivot)
        {
            swap(nums[i],nums[j]);
            i++;
        }
    }
    swap(nums[i],nums[end]);
    return i;
}
int getPivotIndex(int start,int end, vector<int>& nums)
{
    int randomNum = rand();
    int pt = start + randomNum % (end-start+1);
    swap(nums[pt],nums[end]);
    return partition(start,end,nums);
}
void quickSort(int start,int end, vector<int>& nums)
{
    if ( start < end )
    {
        int pivot_idx = getPivotIndex(start,end,nums);
        quickSort(start,pivot_idx-1,nums);
        quickSort(pivot_idx+1, end, nums);
    }
}
int main()
{
    vector<int> vec ({5,2,78,-109,1,3,4});
    quickSort(0, vec.size()-1, vec);
    for (auto ele:vec)
    {
        cout << ele << endl;
    }
    return 0;
}
