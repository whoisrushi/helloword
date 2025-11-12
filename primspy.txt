V = 5
INF = 9999

def primMST(graph):
    key = [INF]*V
    parent = [-1]*V
    mstSet = [False]*V
    key[0] = 0

    for _ in range(V-1):
        u = min((k for k in range(V) if not mstSet[k]), key=lambda x: key[x])
        mstSet[u] = True
        for v in range(V):
            if graph[u][v] and not mstSet[v] and graph[u][v] < key[v]:
                parent[v], key[v] = u, graph[u][v]

    print("Edge \tWeight")
    for i in range(1, V):
        print(f"{parent[i]} - {i}\t{graph[i][parent[i]]}")

graph = [
    [0, 2, 0, 6, 0],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0]
]

primMST(graph)