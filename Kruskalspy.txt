class Graph:
    def _init_(self, v):  
        self.V = v
        self.edges = []  

    def add_edge(self, u, v, w):
        self.edges.append([u, v, w])

    def find(self, parent, i):
        if parent[i] != i:
            parent[i] = self.find(parent, parent[i])
        return parent[i]

    def union(self, parent, rank, x, y):
        if rank[x] < rank[y]:
            parent[x] = y
        elif rank[x] > rank[y]:
            parent[y] = x
        else:
            parent[y] = x
            rank[x] += 1

    def kruskal(self):
        self.edges.sort(key=lambda x: x[2])
        parent = [i for i in range(self.V)]
        rank = [0] * self.V
        result = []
        cost = 0

        for u, v, w in self.edges:
            x, y = self.find(parent, u), self.find(parent, v)
            if x != y:
                result.append([u, v, w])
                cost += w
                self.union(parent, rank, x, y)

        print("\nEdges in Minimum Spanning Tree:")
        for u, v, w in result:
            print(f"{u} -- {v} == {w}")
        print("Total Cost:", cost)


# ---- Main ----
g = Graph(5)
g.add_edge(0, 1, 10)
g.add_edge(0, 2, 8)
g.add_edge(1, 2, 5)
g.add_edge(1, 3, 3)
g.add_edge(2, 3, 7)
g.add_edge(2, 4, 6)
g.add_edge(3, 4, 4)

g.kruskal()