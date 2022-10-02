#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int *arr, int a, int b)
{
    if (a == b)
    {
        return;
    }

    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void MaxHeap(int *arr, int n, int cur_idx)
{

    while (true)
    {
        int left_child = 2*cur_idx+1;
        int right_child = 2*cur_idx+2;
        if (left_child >= n)
        {
            break;
        }

        else 
        {
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
                break;
            }

            else 
            {
                swap(arr, cur_idx, bigger_element);
                cur_idx = bigger_element;
            }
        }
    }
}

bool Validate(int n, int *d)
{
	for(int i=1;i<n;i++)
	{
		if( d[i-1] > d[i] )
		{
			return false;
		}
	}
	return true;
}

int main()
{
    

    int n = 1000000; //= rand();
    int *arr = new int [n];

    std::cout << n << std::endl;

    for (int i = 0; i < n; i++)
    {
        int num = rand();
        arr[i] = num;
    }
    
    for (int i = (n-1)/2; i >=0; i--)
    {
        MaxHeap(arr, n, i);
    }

    for (int i = n-1; i > 0; i--)
    {
        swap(arr, 0, i);
        for (int j = (i-1)/2; j >= 0; j--)
        {
            MaxHeap(arr, i, j);
        }
    }

    if (Validate(n, arr))
    {
        std::cout << "Sort Succeed" << std::endl;
    }

    else 
    {
        std::cout << "Sort Failed" << std::endl;
    }
    return 1;
}