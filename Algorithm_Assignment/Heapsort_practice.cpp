#include <iostream>
#include <cstdlib>

void swap(int *arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void MaxHeap(int *arr, int n, int cur_idx)
{
    int left_child = 2*cur_idx+1;
    int right_child = 2*cur_idx+2;
    
    if (left_child >= n)
    {
        return;
    }
    
    int bigger_element = cur_idx;
 
    if (left_child < n && arr[left_child] > arr[bigger_element])
    {
        bigger_element = left_child;
    }

    if (right_child < n && arr[right_child] > arr[bigger_element])
    {
        bigger_element = right_child;
    }

    if (bigger_element == cur_idx)
    {
        return;
    }

    else 
    {
        swap(arr, cur_idx, bigger_element);
        MaxHeap(arr, n, bigger_element);
    }
}


void HeapSort(int *arr, int idx)
{
    if (idx == 0)
    {
        return;
    }

    swap(arr, 0, idx);
    for (int i = (idx-1)/2; i >= 0; i--)
    {
        MaxHeap(arr, idx, i);
    }
}
int main()
{
    int n;
    std::cin >> n;

    int *arr = new int [n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = (n-1)/2; i >= 0; i--)
    {
        MaxHeap(arr, n, i);
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 1;

} 
