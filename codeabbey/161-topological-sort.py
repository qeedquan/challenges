#!/usr/bin/env python3

"""

Have you ever played Sid Meyer's Civilization? It was a wonderful strategy game where you were founding and growing cities, exploring and colonizing the world, and making discoveries and inventions. This was an essential part of the game - certain discoveried technologies allowed you to create new types of buildings and weapons - and what is important - to investigate newer technologies.

For example:

MapMaking (requires Writing, allows Navigation) gives you power to build triremes and explore ocean, eventually visiting other continents;
Navigation (requires MapMaking and Astronomy, allows Physics and Magnetism) makes possible building more reliable ships;
Steam Engine (requires Physics and Invention, allows RailRoads) - with it you can create protected ironclads.
The game had the built-in "civilopedia" which described briefly the meaning of each "civilization advances" and showed their requirements and opportunities. If we think of each discovery as of a node - then the requirements between them will be directed edges - and so the whole "science" could be represented as a graph.

It is important that such graph have no cycles (otherwise certain discoveries could never be made) - i.e. it is an example of a directed acyclic graph (abbreviated as DAG).

Suppose we marked each discovery with some two letter code, like Mm for MapMaking or Se for Steam Engine and wrote down all requirements (i.e. edges of a graph) as pairs, like this:

Wr -> Mm
Mm -> Na
As -> Na
Na -> Py
Py -> Se
and now we want to put these discoveries into a list in such an order, that as we achieve them sequentially one by one starting from the top, we'll never encounter a problem of unsatisfied prerequisites. I.e. when we are going to work on each next technology, we found that all necessary preceding discoveries and inventions have been made already.

Such ordering is called a topological sorting - as you see it has great importance in planning tasks or activities which have dependencies between them.

Input data will contain the amount of discovery code pairs in the first line.
Next lines will contain two discovery codes each - so that first is required to start working on the second.
Answer should give a list of codes ordered according to topological sorting. (any such ordering is acceptable if there are more than one)

Example:

input data:
5
Wr Mm
Mm Na
As Na
Na Py
Py Se

answer:
Wr As Mm Na Py Se

"""

from collections import defaultdict, deque

# https://www.geeksforgeeks.org/python/python-program-for-topological-sorting/
# https://en.wikipedia.org/wiki/Topological_sorting
class Graph:
    def __init__(self, num_vertices):
        self.graph = defaultdict(list)
        self.num_vertices = num_vertices

    def add_edge(self, u, v):
        self.graph[u].append(v)

    # Kahn's Algorithm
    def toposort(self):
        # Count of incoming edges for each vertex
        in_degree = [0] * self.num_vertices

        # Calculate in-degree for each vertex
        for u in self.graph:
            for v in self.graph[u]:
                in_degree[v] += 1

        # Queue for vertices with 0 in-degree
        queue = deque([i for i in range(self.num_vertices) if in_degree[i] == 0])
        order = []
        while queue:
            u = queue.popleft()
            order.append(u)
            # Decrease in-degree for adjacent vertices
            for v in self.graph[u]:
                in_degree[v] -= 1
                if in_degree[v] == 0:
                    queue.append(v)
        return order

def make_mappings(codepairs):
    names = {}
    ids = {} 
    for pair in codepairs:
        for i in range(len(pair)):
            if pair[i] not in names:
                names[pair[i]] = len(names)
                ids[names[pair[i]]] = pair[i]
    return names, ids

def solve(codepairs):
    names, ids = make_mappings(codepairs)
    graph = Graph(len(names))
    for pair in codepairs:
        graph.add_edge(names[pair[0]], names[pair[1]])
    
    result = []
    for code in graph.toposort():
        result.append(ids[code])
    return result

def main():
    assert(solve([["Wr", "Mm"], ["Mm", "Na"], ["As", "Na"], ["Na", "Py"], ["Py", "Se"]]) == ["Wr", "As", "Mm", "Na", "Py", "Se"])

main()
