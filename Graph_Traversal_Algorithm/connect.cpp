#include <iostream>
#include <vector>
#include <stack>

void DFS(bool *visited, std::vector<int> *edges, int start_node)
{
    std::stack<int> stack;
    stack.push(start_node);

    while (stack.empty() == false)
    {
        int num = stack.top();
        stack.pop();

        if (visited[num] == false)
        {
            visited[num] = true;
        }

        for (int i = 0; i< edges[num].size(); i++)
        {
            if (visited[edges[num].at(i)] == false)
            {
                stack.push(edges[num].at(i));
            }
        }
    }
}

int main()
{
    //getting inputs of basic variables
    int N, M;
    std::cin >> N >> M;

    //declaring visited array and edge array of vector
    bool *visited = new bool [N+1];
    std::vector<int> *edges = new std::vector<int> [N+1];

    //initializing visited array
    for (int i = 0; i < N+1; i++)
    {
        visited[i] = false;
    }

    //getting inputs of edge information
    for (int i = 0; i < M; i++)
    {
        int a, b;
        std::cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int flag = 0;
    //Executing DFS function
    for (int i = 1; i < N+1; i++)
    {
        if (visited[i] == false)
        {
            DFS(visited, edges, i);
            flag ++;
        }
    }

    std::cout << flag;
    return 0;
}