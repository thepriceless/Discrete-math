import igraph as ig
from igraph import *

added = set()

nodes = [i for i in range(52)]
edges = []
weight = []
with open('weighted edges list.txt') as f:
    for i in range(194):
        a = f.readline().split()
        temp = tuple((a[0], a[1]))
        if temp not in added:
            weight.append(int(a[2]))
            edges.append((int(a[0]) - 1, int(a[1]) - 1))
            temp = tuple((a[1], a[0]))
            added.add(temp)
g = Graph(edges)
print(weight)
print(g.spanning_tree(weight))
