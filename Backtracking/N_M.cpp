#include <iostream>

void DFS(int idx, int N, int M, int *arr, bool *visited)
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

    //Inserting the integers which are not visited
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            arr[idx] = i;
            DFS(idx + 1, N, M, arr, visited);
            visited[i] = false;
        }
    }
}

int main()
{
    //Getting inputs of N & M
    int N, M;
    std::cin >> N >> M;

    //Declaring and initializing visited array
    bool *visited = new bool [N+1];
    for (int i = 0; i <= N; i++)
    {
        visited[i] = false;
    }

    int *arr = new int [M];

    DFS(0, N, M, arr, visited);
}