#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

struct Edge
{
    int a;
    int b;
    int cost;
};

int Min_idx(int *arr, int n, bool *visited)
{
    int flag = 1;
    int min_val, min_idx;

    while (true)
    {
        if (visited[flag] == false)
        {
            min_val = arr[flag];
            min_idx = flag;
            break;
        }

        else 
        {
            flag++;
        }
    }

    for (int i = min_idx+1; i <= n; i++)
    {
        if (arr[i] < min_val && visited[i] == false)
        {
            min_val = arr[i];
            min_idx = i;
        }
    }

    return min_idx;
}

void Search(std::vector<Edge> edges, int root, int n, int *distance, bool *visited, int *parent, std::vector<int> MST_COST)
{
    visited[root] = true;
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            flag++;
        }
    }

    if (flag == 0)
    {
        int sum = 0;
        for (int i = 0; i < MST_COST.size(); i++)
        {
            sum += MST_COST.at(i);
        }

        std::cout << sum << std::endl;
        return;
    }

    else 
    {
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges.at(i).a == root && visited[edges.at(i).b] == false)
            {
                if (distance[edges.at(i).b] > edges.at(i).cost)
                {
                    distance[edges.at(i).b] = edges.at(i).cost;
                }
            }

            else if (edges.at(i).b == root && visited[edges.at(i).a] == false)
            {
                if (distance[edges.at(i).a] > edges.at(i).cost)
                {
                    distance[edges.at(i).a] = edges.at(i).cost;
                }
            }
        }

        MST_COST.push_back(distance[Min_idx(distance, n, visited)]);
        int new_root = Min_idx(distance, n, visited);
        Search(edges, new_root, n, distance, visited, parent, MST_COST);
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    
    std::vector<Edge> edges;

    for (int i = 0; i < m; i++)
    {
        Edge edge;
        std::cin >> edge.a >> edge.b >> edge.cost;
        edges.push_back(edge);
    }

    int *distance = new int [n+1];
    for (int i = 1; i <= n; i++)
    {
        distance[i] = 1000000;
    }
    bool *visited = new bool [n+1];
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    int *parent = new int [n+1];
    for (int i = 1; i <= n; i++)
    {
        parent[i] = 0;
    }

    distance[1] = 0;
    std::vector<int> MST_COST;

    Search(edges, 1, n, distance, visited, parent, MST_COST);

    int sum = 0;
    for (int i = 0; i < MST_COST.size(); i++)
    {
        sum += MST_COST.at(i);
    }

    std::cout << "Out of function" << MST_COST.size() << std::endl;

    delete[] distance;
    delete[] visited;
    delete[] parent;

    return 0;
}