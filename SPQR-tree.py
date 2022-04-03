import igraph as ig
from igraph import *

added = set()

edges = []
with open('weighted edges list.txt') as f:
    for i in range(194):
        a = f.readline().split()
        temp = tuple((a[0], a[1]))
        if temp not in added:
            edges.append((int(a[0]) - 1, int(a[1]) - 1))
            temp = tuple((a[1], a[0]))
            added.add(temp)
            
g = Graph(edges)
elements = g.biconnected_components()[7]
d = {}
for i in edges:
    if (i[0] in elements) and (i[1] in elements):
        if d.get(i[0]) == None:
            d[i[0]] = []
        if d.get(i[1]) == None:
            d[i[1]] = []
        d[i[0]].append(i[1])
        d[i[1]].append(i[0])

print(d)
