#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

struct Edge
{
    int start;
    int end;
    int time;
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

bool Finish_check(std::vector<Edge> edges, int root, bool *visited)
{
    int flag = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges.at(i).start == root && visited[edges.at(i).end] == false)
        {
            return false;
        }
    }

    return true;
}

void Search(std::vector<Edge> edges, int root, int n, int *distance, bool *visited, std::vector<int> total_time, char **argv)
{
    visited[root] = true;
    std::ofstream write_txt;
    write_txt.open(argv[2]);
    if (Finish_check(edges, root, visited) == true)
    {
        int time = 0;
        for (int i = 0; i < total_time.size(); i++)
        {
            time += total_time.at(i);
        }

        int num = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == true)
            {
                num++;
            }
        }

        write_txt << num << " " << time << std::endl;
        return;
    }

    else 
    {
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges.at(i).start == root && visited[edges.at(i).end] == false)
            {
                if (distance[edges.at(i).end] > edges.at(i).time)
                {
                    distance[edges.at(i).end] = edges.at(i).time;
                }
            }
        }

        total_time.push_back(distance[Min_idx(distance, n, visited)]);
        int new_root = Min_idx(distance, n, visited);
        Search(edges, new_root, n, distance, visited, total_time, argv);
    }
}

int main(int argc, char **argv)
{
    int n, m, s;
    std::ifstream read_txt;
    read_txt.open(argv[1]);
    read_txt >> n >> m >> s;

    std::vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        Edge edge;
        read_txt >> edge.end >> edge.start >> edge.time;

        edges.push_back(edge);
    }

    int *distance = new int [n+1];
    for (int i = 1; i <= n; i++)
    {
        distance[i] = 1000;
    }

    bool *visited = new bool [n+1];
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    distance[s] = 0;
    std::vector<int> total_time;

    Search(edges, s, n, distance, visited, total_time, argv);

    delete[] distance;
    delete[] visited;

    return 0;
}