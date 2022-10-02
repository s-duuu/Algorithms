#include <iostream>
#include <cstdlib>
#include <algorithm>

int BinarySearch(int *arr, int low, int high, int target)
{
    if (low > high)
    {
        return 0;
    }

    else
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return 1;
        }

        else if (arr[mid] < target)
        {
            return BinarySearch(arr, mid+1, high, target);
        }

        else
        {
            return BinarySearch(arr, low, mid-1, target);
        }
    }
}

int main()
{
    int N, M;
    std::cin >> N;
    int *arr = new int [N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr+N);

    std::cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a;
        std::cin >> a;
        std::cout << BinarySearch(arr, 0, N-1, a) << "\n";
    }

    return 0;
}