#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

void BFS(int **arr, bool **visited, int N, std::vector<int> &num, std::pair<int, int> start_idx)
{
    std::queue<std::pair<int, int>> queue;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    visited[start_idx.first][start_idx.second] = true;
    queue.push(start_idx);
    int flag = 1;

    while (queue.empty() != true)
    {
        std::pair<int, int> cur = queue.front();
        queue.pop();

        for (int i = 0; i < 4; i++)
        {
            std::pair<int, int> next = std::make_pair(cur.first+dx[i], cur.second+dy[i]);
            if (next.first >= 0 && next.first < N && next.second >= 0 && next.second < N)
            {
                if (visited[next.first][next.second] == false && arr[next.first][next.second] == 1)
                {
                    visited[next.first][next.second] = true;
                    queue.push(next);
                    flag++;
                }
            }
        }
    }

    num.push_back(flag);
}

int main()
{
    int N;
    std::cin >> N;
    int **arr = new int * [N];
    bool **visited = new bool * [N];
    std::vector<int> num;

    for (int i = 0; i < N; i++)
    {
        arr[i] = new int [N];
        visited[i] = new bool [N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        std::string row;
        std::cin >> row;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 1 && visited[i][j] == false)
            {
                std::pair<int, int> start_idx = std::make_pair(i, j);
                BFS(arr, visited, N, num, start_idx);
            }
        }
    }

    std::sort(num.begin(), num.end());
    std::cout << num.size();
    for (int i = 0; i < num.size(); i++)
    {
        std::cout << std::endl << num.at(i);
    }

    return 0;
}