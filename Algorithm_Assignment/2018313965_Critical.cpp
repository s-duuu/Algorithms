#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

void Search(std::vector<int> *dependency, int *in_degree, int *task_time, int N, int M, char **argv)
{
    std::queue<int> queue;
    std::ofstream write_txt;
    write_txt.open(argv[2]);

    int *critical_time = new int [N+1];

    for (int i = 1; i <= N; i++)
    {
        critical_time[i] = 0;
    }

    // Search start
    for (int i = 1; i <= N; i++)
    {
        if (in_degree[i] == 0)
        {
            queue.push(i);
        }
    }

    int last_task;

    while (true)
    {
        int x;
        x = queue.front();
        queue.pop();
        critical_time[x] += task_time[x];
        
        if (dependency[x].size() == 0)
        {
            last_task = x;
            break;
        }

        for (int i = 0; i < dependency[x].size(); i++)
        {
            if (critical_time[dependency[x].at(i)] < critical_time[x])
            {
                critical_time[dependency[x].at(i)] = critical_time[x];
            }
            in_degree[dependency[x].at(i)]--;
            if (in_degree[dependency[x].at(i)] == 0)
            {
                queue.push(dependency[x].at(i));
            }
        }
    }

    write_txt << critical_time[last_task];
    delete[] critical_time;
}

int main(int argc, char **argv)
{
    int N, M;
    std::ifstream read_txt;
    read_txt.open(argv[1]);

    read_txt >> N >> M;

    int *task_time = new int [N+1];
    int *in_degree = new int [N+1];
    std::vector<int> *dependency = new std::vector<int> [N+1];

    for (int i = 1; i <= N; i++)
    {
        in_degree[i] = 0;
        read_txt >> task_time[i];
    }

    for (int i = 0; i < M; i++)
    {
        int start_idx, dst_idx;
        read_txt >> start_idx >> dst_idx;

        in_degree[dst_idx]++;
        dependency[start_idx].push_back(dst_idx);
    }

    Search(dependency, in_degree, task_time, N, M, argv);
    
    delete[] task_time;
    delete[] in_degree;
    return 0;
}