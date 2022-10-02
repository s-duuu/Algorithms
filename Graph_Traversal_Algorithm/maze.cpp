#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

void BFS(int **arr, int **cost, int N, int M)
{
    //Declaration of visited array (boolean)
    bool **visited = new bool * [N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = new bool [M];
    }

    //Initializing visited array
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }

    //Four cases of move after one step
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    //Declaration of start index pair
    std::pair<int, int> start_idx;
    start_idx = std::make_pair(0, 0);
    visited[start_idx.first][start_idx.second] = true;

    //Declaration of BFS algorithm queue
    std::queue<std::pair<int,int>> queue;

    queue.push(start_idx);
    cost[start_idx.first][start_idx.second] ++;

    while (queue.empty() != true)
    {
        std::pair<int, int> cur;
        cur.first = queue.front().first;
        cur.second = queue.front().second;
        queue.pop();

        for (int i = 0; i < 4; i++)
        {
            std::pair<int, int> next = std::make_pair(cur.first+dx[i], cur.second+dy[i]);

            if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < M)
            {
                if (visited[next.first][next.second] == false && arr[next.first][next.second] == 1)
                {
                    visited[next.first][next.second] = true;
                    queue.push(next);
                    cost[next.first][next.second] = cost[cur.first][cur.second] + 1;
                }
            }
        }
    }
}

int main()
{
    int N, M;
    std::cin >> N >> M;

    //Declaration of maze array and cost array
    int **arr = new int * [N];
    int **cost = new int * [N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = new int [M];
        cost[i] = new int [M];
    }

    //Initializing cost array
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cost[i][j] = 0;
        }
    }

    //Get input of maze information
    for (int i = 0; i < N; i++)
    {
        std::string row;
        std::cin >> row;

        for (int j = 0; j < M; j++)
        {
            arr[i][j] = row[j]-'0';
        }
    }

    //Executing BFS algorithm
    BFS(arr, cost, N, M);

    std::cout << cost[N-1][M-1];
    return 0;

}