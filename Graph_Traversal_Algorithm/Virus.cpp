#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

void BFS(std::vector<int> *edges, int N)
{
    bool *visited = new bool [N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }

    int start_idx = 1;
    std::queue<int> queue;
    queue.push(start_idx);
    visited[start_idx] = true;

    int flag = 0;
    while (queue.empty() != true)
    {
        int cur = queue.front();
        queue.pop();

        for (int i = 0; i < edges[cur].size(); i++)
        {
            if (visited[edges[cur].at(i)] == false)
            {
                queue.push(edges[cur].at(i));
                visited[edges[cur].at(i)] = true;
                flag++;
            }
        }
    }

    std::cout << flag;
}

int main()
{
    //Declaration of variables (# of computers, # of network pairs)
    int N;
    int N_edge;

    std::cin >> N >> N_edge;

    std::vector<int> *edges = new std::vector<int> [N+1];
    for (int i = 0; i < N_edge; i++)
    {
        int a, b;
        std::cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    BFS(edges, N);

    return 0;
}