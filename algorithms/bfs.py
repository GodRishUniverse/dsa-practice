from graph import *


def bfs(graph, start_vertex, end_vertex):
    
    queue = []  
    start_vertex.color = "gray"

    queue.append(start_vertex)

    while len(queue) != 0:
        vertex = queue.pop(0) # dequeue

        if vertex in graph.vertices:
            for i in graph.get_adjacency_list(vertex):
                if i.color is None:
                    i.color = "gray"
                    if i == end_vertex:
                        return "Path found"
                    queue.append(i)
            # graph.print_graph()

            vertex.color = "black"


    return "No path found"





if __name__ == '__main__':

    # undirected
    # 1 - 2,3,4
    # 2 - 1,5
    # 3 - 1,5
    # 4 - 1
    # 5 - 2,3

    vertices = [Vertex("1", 1), Vertex("2", 2), Vertex("3", 3), Vertex("4", 4), Vertex("5", 5)]

    graph = Graph(vertices, directed=False)

    graph.add_edge(vertices[0], vertices[1])
    graph.add_edge(vertices[0], vertices[2])
    graph.add_edge(vertices[0], vertices[3])
    graph.add_edge(vertices[1], vertices[0])
    graph.add_edge(vertices[1], vertices[4])
    graph.add_edge(vertices[2], vertices[0])
    graph.add_edge(vertices[2], vertices[4])
    graph.add_edge(vertices[3], vertices[0])
    graph.add_edge(vertices[4], vertices[1])
    graph.add_edge(vertices[4], vertices[2])

    # graph.print_graph()


    print(bfs(graph, vertices[0], Vertex("5", 5)))

