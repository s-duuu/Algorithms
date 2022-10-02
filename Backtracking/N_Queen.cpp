#include <iostream>
#include <vector>
#include <cmath>

bool Queen_check(std::pair<int, int> *arr, std::pair<int, int> cur, int depth)
{
    for (int i = 0; i < depth; i++)
    {
        if (arr[i].first == cur.first || arr[i].second == cur.second || abs(arr[i].first - cur.first) == abs(arr[i].second - cur.second))
        {
            return false;
        }
    }
    return true;
}

void DFS(std::pair<int, int> *arr, bool **visited, int N, int depth, int res)
{
    if (depth == N)
    {
        res ++;
        return;
    }

    std::vector<std::pair<int, int>> loc;
    for (int i = 0; i < N; i++)
    {
        std::pair<int, int> point = std::make_pair(depth, i);
        loc.push_back(point);
    }

    for (int i = 0; i < loc.size(); i++)
    {
        if (visited[loc.at(i).first][loc.at(i).second] == false)
        {
            if (Queen_check(arr, loc.at(i), depth) == true)
            {
                visited[loc.at(i).first][loc.at(i).second] = true;
                arr[depth] = loc.at(i);
                DFS(arr, visited, N, depth+1, res);
                visited[loc.at(i).first][loc.at(i).second] = false;
            }
        }
    }
}

int main()
{
    int N;
    std::cin >> N;

    bool **visited = new bool * [N];
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        visited[i] = new bool [N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }

    std::pair<int, int> *arr = new std::pair<int, int> [N];

    DFS(arr, visited, N, 0, res);

    std::cout << res;

    return 0;
}