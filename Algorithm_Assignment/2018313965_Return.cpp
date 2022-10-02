#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

double Calc_dist(int **H, std::pair<int, int> a, std::pair<int, int>b)
{
    if (H[a.first][a.second] != H[b.first][b.second])
    {
        return pow(H[a.first][a.second] - H[b.first][b.second], 2)+1;
    }

    else 
    {
        return 2;
    }
}

bool In_range(std::pair<int, int> idx, int N, int M)
{
    if (idx.first >= 0 && idx.first < N && idx.second >= 0 && idx.second < M)
    {
        return true;
    }

    else 
    {
        return false;
    }
}

void Dijkstra(int **H, int N, int M, int T, int S)
{
    double **dist = new double * [N];
    std::pair<double, int> **info = new std::pair<double, int> * [N];
    for (int i = 0; i < N; i++)
    {
        dist[i] = new double [M];
        info[i] = new std::pair<double, int> [M];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dist[i][j] = 9999999;
        }
    }

    std::pair<int, int> *move = new std::pair<int, int> [4];
    move[0] = std::make_pair(1, 0);
    move[1] = std::make_pair(-1, 0);
    move[2] = std::make_pair(0, 1);
    move[3] = std::make_pair(0, -1);

    int start_point = 0;
    dist[start_point/4][start_point%4] = (double)0;

    std::priority_queue<std::pair<int, int>> pq;
    
    pq.push(std::make_pair(dist[start_point/4][start_point%4], start_point));

    for (;;)
    {
        if (pq.empty() == true)
        {
            break;
        }

        std::pair<double, std::pair<int, int>> x= pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            std::pair<int, int> idx = std::make_pair(x.second.first+move[i].first, x.second.second+move[i].second);
            double w = Calc_dist(H, x.second, idx);
            if (In_range(idx, N, M) == true)
            {
                if (visited[idx.first][idx.second] != true && abs(H[x.second.first][x.second.second] - H[idx.first][idx.second]) <= T)
                {
                    if ((dist[idx.first][idx.second] > dist[x.second.first][x.second.second] + w) && (dist[x.second.first][x.second.second] + w <= S))
                    {
                        pq.push(std::make_pair(dist[x.second.first][x.second.second]+ w, idx));
                        dist[idx.first][idx.second] = dist[x.second.first][x.second.second] + w;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            info[i][j] = std::make_pair(dist[i][j], H[i][j]);
        }
    }
    int max = info[0][0].second;
    
    std::cout << max << std::endl;

    delete[] dist;
    delete[] info;
    delete[] move;
}

int main()
{
    int N, M, T, S;
    std::cin >> N >> M;
    int **H = new int *[N];
    for (int i = 0; i < N; i++)
    {
        H[i] = new int [M];
    }

    std::cin >> T >> S;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> H[i][j];
        }
    }

    Dijkstra(H, N, M, T, S);

    return 0;
}