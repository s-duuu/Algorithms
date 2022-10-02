#include <iostream>
#include <cstdlib>

void InsertionSort(int *arr, int first, int last)
{
    for (int i = first+1; i < last; i++)
    {
        int tmp = arr[i];
        for (int j = i; j > 0; j--)
        {
            if (arr[j-1] > tmp)
            {
                arr[j] = arr[j-1];
            }

            else 
            {
                arr[j] = tmp;
                break;
            }
        }

        if (arr[first] > tmp)
        {
            arr[first] = tmp;
        }
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
    int first, last;
    std::cin >> first >> last;
    InsertionSort(arr, first, last);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 1;
}