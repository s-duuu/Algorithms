#include <iostream>
#include <cstdlib>
#include <ctime>

void swap (int *arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void Quicksort(int *arr, int start, int end)
{
    std::cout << "Sorting... " << start << " " << end << std::endl;
    if (start >= end)
    {
        return;
    }

    int pivot = start;
    int a = pivot + 1;
    int b = end;

    while(a <= b)
    {
        while(arr[a] <= arr[pivot] && a <= end)
        {
            a++;
        }

        while (arr[b] >= arr[pivot] && b > start)
        {
            b--;
        }

        if (a > b)
        {
            swap(arr, pivot , b);
            break;
        }

        else 
        {
            swap(arr, a, b);
        }
    }

    Quicksort(arr, start, b - 1);
    Quicksort(arr, b + 1, end);
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
    srand((unsigned int)time(NULL));
    int n = 1000000;
    //std::cin >> n;

    int *arr = new int [n];
    for (int i = 0; i < n; i++)
    {
        int num = rand();
        arr[i] = num;
        //std::cin >> arr[i];
    }
    Quicksort(arr, 0, n - 1);

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