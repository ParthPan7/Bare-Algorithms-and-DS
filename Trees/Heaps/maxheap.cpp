#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void max_Heapify(vector<int>& vec, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    int N = vec.size();
    if (left < N && vec[left] > vec[i] )
    {
        largest = left;
    }
    if ( right < N && vec[largest] < vec[right] )
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(vec[i],vec[largest]);
        max_Heapify(vec, largest);
    }
    
}

void build_Max_Heap(vector<int>& num)
{
    int N = num.size();
    for (int j = N/2; j>=0; --j)
    {
        max_Heapify(num, j);
    }
}

void heap_sort(vector<int>& num)
{
    build_Max_Heap(num);
    vector<int> temp;
    while (num.size() > 0 )
    {
        swap(num[0],num[num.size()-1]);
        temp.push_back(num.back());
        num.pop_back();
        max_Heapify(num, 0);
    }
    num.clear();
    num = temp;
}

int main()
{
    vector<int> vec({46,-1,90,89,48,90,-506,46,46});
    heap_sort(vec);
    for (auto ele: vec)
    {
        cout << ele << " ";
    }
    return 0;
}
