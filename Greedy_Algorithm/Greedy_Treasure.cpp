#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

void swapping(int *arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void Reverse_QuickSort(int *arr, int start, int last)
{
    if (start >= last)
    {
        return;
    }

    int pivot = start;
    int left = pivot+1;
    int right = last;

    while(left <= right)
    {
        while (arr[left] >= arr[pivot] && left <= last)
        {
            left++;
        }
        while (arr[right] <= arr[pivot] && right > start)
        {
            right--;
        }

        if (left > right)
        {
            swapping(arr, pivot, right);
            break;
        }
        else
        {
            swapping(arr, left, right);
        }
    }

    Reverse_QuickSort(arr, start, right - 1);
    Reverse_QuickSort(arr, right + 1, last);
}


int main()
{
    int N;
    std::cin >> N;
    int *a = new int [N];
    int *b = new int [N];

    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i < N; i++)
    {
        std::cin >> b[i];
    }

    std::sort(a, a+N);
    Reverse_QuickSort(b, 0, N-1);

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += a[i] * b[i];
    }

    std::cout << sum << std::endl;

    return 0;
}
