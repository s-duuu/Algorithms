#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

void Prim(std::vector<std::pair<int, int>> *edges, int n, int m, char **argv)
{
    bool *visited = new bool [n+1];
    int *parent = new int [n+1];
    int *dist = new int [n+1];

    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
        parent[i] = false;
        dist[i] = 1000000;
    }
    int root_idx = 1;
    dist[root_idx] = 0;
    parent[root_idx] = 1;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
    pq.push(std::make_pair(0, root_idx));

    for (;;)
    {
        if (pq.empty() == true)
        {
            break;
        }

        std::pair<int, int> x = pq.top();
        pq.pop();
        if (visited[x.second] == true)
        {
            continue;
        }

        visited[x.second] = true;

        for (int i = 0; i < edges[x.second].size(); i++)
        {
            int idx = edges[x.second][i].first;
            int weight = edges[x.second][i].second;

            if ( visited[idx] == false && weight < dist[idx])
            {
                pq.push(std::make_pair(weight, idx));
                parent[idx] = x.second;
                dist[idx] = weight;
            }
        }
    }

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += dist[i];
    }

    delete[] visited;
    delete[] parent;
    delete[] dist;

    std::ofstream write_txt;
    write_txt.open(argv[2]);
    write_txt << sum;
}

int main(int agrc, char **argv)
{
    int n, m;
    std::ifstream read_txt;
    read_txt.open(argv[1]);
    read_txt >> n >> m;
    
    std::vector<std::pair<int, int>> *edges = new std::vector<std::pair<int, int>> [n+1];

    for (int i = 0; i < m; i++)
    {
        int node1, node2, cost;
        read_txt >> node1 >> node2 >> cost;
        edges[node1].push_back(std::make_pair(node2, cost));
        edges[node2].push_back(std::make_pair(node1, cost));
    }

    Prim(edges, n, m, argv);

    return 0;
}