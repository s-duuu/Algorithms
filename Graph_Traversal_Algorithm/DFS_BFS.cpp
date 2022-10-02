#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

//DFS Traversal
void DFS(int **graph, int vertex, bool *visited, int root)
{
    std::stack<int> stack;
    stack.push(root);

    while (stack.empty() == false)
    {
        root = stack.top();
        stack.pop();

        if (visited[root] == false)
        {
            visited[root] = true;
            std::cout << root << " ";
        }

        for (int i = vertex; i > 0; i--)
        {
            if (graph[root][i] != 0 && visited[i] != true)
            {
                stack.push(i);
            }
        }
    }
    std::cout << std::endl;
}

//BFS Traversal
void BFS(int **graph, int vertex, bool *visited, int root)
{
    std::queue<int> queue;
    queue.push(root);

    while (queue.empty() == false)
    {
        root = queue.front();
        queue.pop();

        std::cout << root << " ";

        for (int i = 1; i <= vertex; i++)
        {
            if (graph[root][i] == 1 & visited[i] == false)
            {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    //v = number of vertices & e = number of edges
    int vertex, edge, root;
    std::cin >> vertex >> edge >> root;
    
    //dynamic allocation of graph and visited
    int **graph = new int * [vertex+1];
    for (int i = 0; i <= vertex+1; i++)
    {
        graph[i] = new int [vertex+1];
    }

    bool *visited = new bool [vertex+1];
    //initializing graph
    for (int i = 0; i <= vertex; i++)
    {
        for (int j = 0; j <= vertex; j++)
        {
            graph[i][j] = 0;
        }
    }

    //initializing visited array
    for (int i = 0; i <= vertex; i++)
    {
        visited[i] = false;
    }

    //get inputs of edges
    for (int i = 0; i < edge; i++)
    {
        int start, end;
        std::cin >> start >> end;

        graph[start][end] = 1;
        graph[end][start] = 1;
    }

    DFS(graph, vertex, visited, root);

    //again initializing visited array
    for (int i = 0; i <= vertex; i++)
    {
        visited[i] = false;
    }
    visited[root] = true;

    BFS(graph, vertex, visited, root);

    return 0;
}