#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>

void BFS(int **arr, int N, int M, int **cost, std::vector<std::pair<int, int>> start_idxs)
{
    std::queue<std::pair<int, int>> queue;
    for (int i = 0; i < start_idxs.size(); i++)
    {
        queue.push(start_idxs.at(i));
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (queue.empty() != true)
    {
        std::pair<int, int> cur = queue.front();
        queue.pop();

        for (int i = 0; i < 4; i++)
        {
            std::pair<int, int> next = std::make_pair(cur.first + dx[i], cur.second + dy[i]);
            if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < M)
            {
                if (arr[next.first][next.second] == 0)
                {
                    queue.push(next);
                    arr[next.first][next.second] = 1;
                    cost[next.first][next.second] = cost[cur.first][cur.second] + 1;
                }
            }
        }
    }
}

int main()
{
    int M, N;
    std::cin >> M >> N;

    int **arr = new int * [N];
    int **cost = new int * [N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int [M];
        cost[i] = new int [M];
    }
    std::vector<std::pair<int, int>> start_idxs;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> arr[i][j];
            cost[i][j] = 0;
            if (arr[i][j] == 1)
            {
                start_idxs.push_back(std::make_pair(i, j));
            }
        }
    }

    BFS(arr, N, M, cost, start_idxs);
    
    int max = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
            {
                std::cout << -1;

                return 0;
            }

            else
            {
                if (cost[i][j] > max)
                {
                    max = cost[i][j];
                }
            }
        }
    }

    std::cout << max;

    delete[] arr;
    delete[] cost;

    return 0;

    
}