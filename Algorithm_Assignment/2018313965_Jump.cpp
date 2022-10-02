#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

void Astar(std::pair<double, double> *p, int n, int G, char **argv)
{
    bool *visited = new bool [n+1];
    int *prev = new int [n+1];
    double *dist = new double [n+1];
    double *weight = new double [n+1];
    double *huristic = new double [n+1];

    int start_idx = 0;
    int dst_idx = 1;

    std::ofstream write_txt;
    write_txt.open(argv[2]);
    
    for (int i = 0; i < n+1; i++)
    {
        visited[i] = false;
        prev[i] = -1;
        dist[i] = 1000000*sqrt(2);
        weight[i] = 1000000*sqrt(2);

        huristic[i] = sqrt(pow(p[i].first-p[1].first, 2) + pow(p[i].second-p[1].second, 2));
    }

    dist[start_idx] = 0;
    prev[start_idx] = start_idx;

    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
    pq.push(std::make_pair((double)0, start_idx));

    for (;;)
    {
        if (pq.empty())
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

        if (x.second == dst_idx)
        {
            write_txt << round(x.first);
            break;
        }

        for (int i = 0; i <= n; i++)
        {
            if (abs(p[x.second].first-p[i].first)<=2 && abs(p[x.second].second-p[i].second) <= 2)
            {
                double edge_weight = (p[x.second].first - p[i].first) * (p[x.second].first - p[i].first);
                edge_weight += (p[x.second].second - p[i].second) * (p[x.second].second - p[i].second);
                edge_weight = sqrt(edge_weight);
                if (visited[i] == false && weight[i] > dist[x.second] + edge_weight + huristic[i])
                {
                    dist[i] = dist[x.second] + edge_weight;
                    weight[i] = dist[x.second] + edge_weight + huristic[i];
                    pq.push(std::make_pair(weight[i], i));
                }
            }
        }
    }

    delete[] visited;
    delete[] prev;
    delete[] dist;
    delete[] weight;
    delete[] huristic;
}

int main(int argc, char **argv)
{
    int n, G;
    std::ifstream read_txt;
    read_txt.open(argv[1]);
    read_txt >> n >> G;

    std::pair<double, double> *p = new std::pair<double, double> [n+1];

    int dst_idx;

    for (int i = 1; i <= n; i++)
    {
        read_txt >> p[i].first >> p[i].second;
        if (p[i].second == G)
        {
            dst_idx = i;
        }
    }

    std::swap(p[1], p[dst_idx]);
    
    p[0].first = 0;
    p[0].second = 0;
    int result;

    Astar(p, n, G, argv);

    return 0;
}