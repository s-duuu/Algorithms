#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>

int Find_Set(int x, int *parent)
{
    while (parent[x] != x)
    {
        x = parent[x];
    }

    return x;
}

void Union_Set(int x, int y, int *parent, int *height)
{
    x = Find_Set(x, parent);
    y = Find_Set(y, parent);

    if (height[x] == height[y])
    {
        parent[y] = x;
        height[x]++;
    }

    else if (height[x] > height[y])
    {
        parent[y] = x;
    }

    else 
    {
        parent[x] = y;
    }
}

void Kruskal(std::vector<std::pair<int, int>> *edges, int n, int m)
{
    int *parent = new int [n+1];
    int *height = new int [n+1];
    std::vector<std::pair<int, std::pair<int, int>>> d;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        height[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < edges[i].size(); j++)
        {
            if (i < edges[i][j].first)
            {
                d.push_back(std::make_pair(edges[i][j].second, std::make_pair(i, edges[i][j].first)));
            }
        }
    }
    std::sort(d.begin(), d.end());
    int ret = 0;

    for (int i = 0; i < d.size(); i++)
    {
        int x = d[i].second.first;
        int y = d[i].second.second;
        int weight = d[i].first;

        if (Find_Set(x, parent) != Find_Set(y, parent))
        {
            ret += weight;
            Union_Set(x, y, parent, height);
        }
    }

    std::cout << ret << std::endl;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> *edges = new std::vector<std::pair<int, int>> [n+1];
    for (int i= 0; i < m; i++)
    {
        int node1, node2, cost;
        std::cin >> node1 >> node2 >> cost;
        edges[node1].push_back(std::make_pair(node2, cost));
        edges[node2].push_back(std::make_pair(node1, cost));
    }

    Kruskal(edges, n, m);

    return 0;
}