import igraph as ig
from igraph import *

added = set()
g = Graph()
g.add_vertices(52)
with open('edges-list.txt') as f:
    for i in range(194):
        a = f.readline().split()
        temp = tuple((a[0], a[1]))
        if temp not in added:
            g.add_edge(int(a[0]) - 1, int(a[1]) - 1)
            temp = tuple((a[1], a[0]))
            added.add(temp)

print(g.largest_cliques())
