def depthFirstSearch(graph, vertex, visited, root):
    stack = []
    stack.append(root)

    while len(stack) != 0:
        root = stack[-1]
        stack.pop()

        if visited[root] == False:
            visited[root] = True
            print(root)
        
        for i in range(vertex, 0, -1):
            if graph[root][i] != 0 and visited[i] != True:
                stack.append(i)
            

def main():
    vertex, edge, root = map(int, input().split())
    graph = [[0 for j in range(vertex+1)] for i in range(vertex+1)]
    visited = [False for i in range(vertex+1)]

    for i in range(edge):
        start, end = map(int, input().split())

        graph[start][end] = 1
        graph[end][start] = 1
    
    depthFirstSearch(graph, vertex, visited, root)

if __name__ == "__main__":
    main()
