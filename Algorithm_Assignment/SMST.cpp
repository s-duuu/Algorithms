#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

struct Edge
{
    int id;
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

void Search(std::vector<Edge> edges, int root, int n, int *distance, bool *visited, int *parent, std::vector<int> &MST_COST, bool *edge_visited)
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
                    parent[edges.at(i).b] = root;
                    edge_visited[edges.at(i).id] = true;
                }
            }

            else if (edges.at(i).b == root && visited[edges.at(i).a] == false)
            {
                if (distance[edges.at(i).a] > edges.at(i).cost)
                {
                    distance[edges.at(i).a] = edges.at(i).cost;
                    parent[edges.at(i).a] = root;
                    edge_visited[edges.at(i).id] = true;
                }
            }
        }

        MST_COST.push_back(distance[Min_idx(distance, n, visited)]);
        int new_root = Min_idx(distance, n, visited);
        Search(edges, new_root, n, distance, visited, parent, MST_COST, edge_visited);
    }
}

bool Check(Edge edge1, Edge edge2)
{
    if (edge1.id == edge2.id)
    {
        return false;
    }

    else 
    {
        if (edge1.a == edge2.a || edge1.a == edge2.b || edge1.b == edge2.a || edge1.b == edge2.b)
        {
            return true;
        }

        else 
        {
            return false;
        }
    }
}

void SMST(std::vector<Edge> edges, bool *edge_visited, int m, std::vector<int> &Cost_diff)
{
    for (int i = 0; i < edges.size(); i++)
    {
        if (edge_visited[edges.at(i).id] == false)
        {
            for (int j = 0; j < edges.size(); j++)
            {
                if (Check(edges.at(i), edges.at(j)) == true && edge_visited[edges.at(j).id] == true && edges.at(i).cost - edges.at(j).cost > 0)
                {
                    Cost_diff.push_back(edges.at(i).cost - edges.at(j).cost);
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    int n, m;
    std::ifstream read_txt;
    read_txt.open(argv[1]);
    read_txt >> n >> m;
    
    std::vector<Edge> edges;

    for (int i = 0; i < m; i++)
    {
        Edge edge;
        edge.id = i;
        read_txt >> edge.a >> edge.b >> edge.cost;
        edges.push_back(edge);
    }
    bool *edge_visited = new bool [m];
    for (int i = 0; i < m; i++)
    {
        edge_visited[i] = false;
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
    std::vector<int> Cost_diff;
    Search(edges, 1, n, distance, visited, parent, MST_COST, edge_visited);

    int sum = 0;
    for (int i = 0; i < MST_COST.size(); i++)
    {
        sum += MST_COST.at(i);
    }

    std::ofstream write_txt;
    write_txt.open(argv[2]);

    SMST(edges, edge_visited, m, Cost_diff);
    int add = *std::min_element(Cost_diff.begin(), Cost_diff.end());
    write_txt << sum + add << std::endl;


    return 0;
}