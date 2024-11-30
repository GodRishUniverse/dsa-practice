
from graph import *

def dfs(graph, start_vertex, end_vertex):
    
    stack = []  
    start_vertex.color = "gray"
    stack.append(start_vertex)

    while len(stack) != 0:
        vertex = stack.pop() # pop
        

        if vertex in graph.vertices:
            for i in graph.get_adjacency_list(vertex):
                if i.color is None:
                    i.color = "gray"
                    if i == end_vertex:
                        return "Path found"
                    stack.append(i)
            # graph.print_graph()

            vertex.color = "black"
    return "No path found"


if __name__ == '__main__':
    # undirected
    # 1 - 2,3
    # 2 - 4,5
    # 3 - 6,7
    # 4 - 
    # 5 - 
    # 6 - 
    # 7 -

    vertices = [Vertex("1", 1), Vertex("2", 2), Vertex("3", 3), Vertex("4", 4), Vertex("5", 5),  Vertex("6", 6), Vertex("7", 7)]

    graph = Graph(vertices, directed=False)

    graph.add_edge(vertices[0], vertices[1])
    graph.add_edge(vertices[0], vertices[2])
    graph.add_edge(vertices[1], vertices[3])
    graph.add_edge(vertices[1], vertices[4])
    graph.add_edge(vertices[2], vertices[5])
    graph.add_edge(vertices[2], vertices[6])    

    # graph.print_graph()


    print(dfs(graph, vertices[0], Vertex("5", 5)))
