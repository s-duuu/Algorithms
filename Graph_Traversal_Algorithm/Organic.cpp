#include <iostream>
#include <cstdlib>
#include <queue>

void BFS(int **arr, bool **visited, int N, int M, std::pair<int, int> start_idx)
{
    std::queue<std::pair<int, int>> queue;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue.push(start_idx);
    visited[start_idx.first][start_idx.second] = true;

    while (queue.empty() != true)
    {
        std::pair<int, int> cur = queue.front();
        queue.pop();
        for (int i = 0; i < 4; i++)
        {
            std::pair<int, int> next = std::make_pair(cur.first + dx[i], cur.second + dy[i]);
            if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < M)
            {
                if (visited[next.first][next.second] == false && arr[next.first][next.second] == 1)
                {
                    queue.push(next);
                    visited[next.first][next.second] = true;
                }
            }
        }
    }
}

int main()
{
    int T;
    std::cin >> T;
    std::vector<int> result;

    for (int i = 0; i < T; i++)
    {
        //Getting input of # of farm length, # of vegetables
        int M, N, K;
        std::cin >> M >> N >> K;

        //Declaration of farm information array
        int **arr = new int * [N];
        bool **visited = new bool * [N];
        for (int j = 0; j < N; j++)
        {
            arr[j] = new int [M];
            visited[j] = new bool [M];
        }

        //Initializing farm inforamtion array
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                arr[j][k] = 0;
                visited[j][k] = false;
            }
        }

        //Getting input of locations of vegetables and assigning them
        for (int j = 0; j < K; j++)
        {
            int x, y;
            std::cin >> x >> y;
            arr[y][x] = 1;
        }

        int flag = 0;

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (arr[j][k] == 1 && visited[j][k] == false)
                {
                    std::pair<int, int> start_idx = std::make_pair(j, k);
                    BFS(arr, visited, N, M, start_idx);
                    flag++;
                }
            }
        }
        result.push_back(flag);
    }

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result.at(i) << std::endl;
    }

    return 0;
}