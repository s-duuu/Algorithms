#include <iostream>
#include <cstdlib>

void Swapping(int *arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int LessValue(int *arr, int a, int b)
{
    if (arr[a] < arr[b])
    {
        return a;
    }

    else
    {
        return b;
    }
}

int Top(int *arr)
{
    return arr[1];
}

void Push(int *arr, int element)
{
    int index = 1;
    while (arr[index] != 0)
    {
        if (arr[index] == 0)
        {
            break;
        }

        index++;
    }
    arr[index] = element;

    while (arr[index] < arr[index / 2])
    {
        if (arr[index] > arr[index / 2])
        {
            break;
        }

        Swapping(arr, index, index / 2);
        index /= 2;
    }
}

void Pop(int *arr, int N)
{
    int index = 1;
    while (arr[index] != 0)
    {
        if (arr[index] == 0)
        {
            break;
        }
        index++;
    }

    Swapping(arr, 1, index);
    arr[index] = 0;
    N--;

    int cur = 1;
    while (arr[cur] > arr[2*cur] || arr[cur] > arr[2*cur + 1])
    {
        if (arr[cur] < arr[2*cur] && arr[cur] < arr[2*cur + 1])
        {
            break;
        }

        else if (arr[])

        Swapping(arr, cur, LessValue(arr, 2*cur, 2*cur+1));
        cur = LessValue(arr, 2*cur, 2*cur+1);
    }
}

int main()
{
    int N = 11;
    int arr[100] = {0, 3, 6, 12, 9, 14, 23, 29, 10, 25, 19, 15};

    Push(arr, 13);
    N++;

    for (int i = 1; i <= N; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    Pop(arr, N);

    for (int i = 1; i <= N; i++)
    {
        std::cout << arr[i] << " ";
    }
}
