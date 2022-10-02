#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>

void Dijkstra(std::vector<std::pair<int, int>> *edges, int start_idx, int n, int m)
{
    bool *visited = new bool [n+1];
    int *parent = new int [n+1];
    double *dist = new double [n+1];

    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        parent[i] = -1;
        dist[i] = 99999999;
    }

    double ret = (double)0;
    dist[start_idx] = (double)0;
    parent[start_idx] = start_idx;

    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
    pq.push(std::make_pair(dist[start_idx], start_idx));

    for (;;)
    {
        if (pq.empty() == true)
        {
            break;
        }

        std::pair<double, int> x = pq.top();
        pq.pop();

        if (visited[x.second] == true)
        {
            continue;
        }

        visited[x.second] = true;
        ret += x.first;

        for (int i = 0; i < edges[x.second].size(); i++)
        {
            int idx = edges[x.second][i].first;
            int w = edges[x.second][i].second;
            if (visited[idx] != true && dist[idx] > dist[x.second]+w)
            {
                pq.push(std::make_pair(dist[x.second]+w, idx));
                parent[idx] = x.second;
                dist[idx] = dist[x.second]+w;
            }
        }
    }

    delete[] visited;
    delete[] parent;
    delete[] dist;
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

    Dijkstra(edges, 1, n, m);

}