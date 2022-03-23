import igraph as ig
from igraph import *

added = set()

edges = []
weight = []
with open('weighted edges list.txt') as f:
    for i in range(194):
        a = f.readline().split()
        temp = tuple((a[0], a[1]))
        if temp not in added:
            #g.add_edge(int(a[0]) - 1, int(a[1]) - 1)
            weight.append(int(a[2]))
            edges.append((int(a[0]) - 1, int(a[1]) - 1))
            temp = tuple((a[1], a[0]))
            added.add(temp)
g = Graph(edges)

mst = Graph()
mst = g.spanning_tree(weight)
#print(mst)

#deleting 'island countries' to form a real Tree
mst.delete_vertices(51)
mst.delete_vertices(32)
mst.delete_vertices(24)
mst.delete_vertices(23)
mst.delete_vertices(22)
mst.delete_vertices(14)
mst.delete_vertices(10)

#print(mst)
print('Prufer code:')
print(mst.to_prufer())
