#include <iostream>

void DFS(int idx, int N, int M, int *arr)
{
    //Print array elements
    if (idx == M)
    {
        for (int i = 0; i < M; i++)
        {
            std::cout << arr[i] << " ";   
        }
        std::cout << "\n";
        return;
    }

    //Inserting the integers
    for (int i = 1; i <= N; i++)
    {
        arr[idx] = i;
        DFS(idx + 1, N, M, arr);
    }
}

int main()
{
    //Getting inputs of N & M
    int N, M;
    std::cin >> N >> M;

    int *arr = new int [M];

    DFS(0, N, M, arr);
}