class Vertex:
    def __init__(self, name, value):
        self.name = name
        self.value = value
        self.color = None
    
    def __str__(self):
        return f"Vertex {self.name}: {self.value}, color: {self.color}"
    
    def __repr__(self):
        return f"Vertex {self.name}: {self.value}, color: {self.color}"
    
    def __eq__(self, other):
        return self.name == other.name and self.value == other.value
    
    def __hash__(self):
        return hash((self.name, self.value, self.color))
        
    def get_color(self):
        return self.color

class Graph:
    def __init__(self, vertices: list[Vertex], directed=False):
        self.vertices = vertices
        self.directed = directed

        self.graph = {}

        for i in self.vertices:
            self.graph[i.name] = []
    
    def add_vertex(self, vertex: Vertex):
        self.vertices.append(vertex)
        self.graph[vertex.name] = []
    
    def add_vertices(self, vertices: list[Vertex]):
        for vertex in vertices:
            self.add_vertex(vertex)

    def add_edges(self, edges):
        for edge in edges:
            self.add_edge(edge[0], edge[1])

    def add_edge(self, u:Vertex, v:Vertex):
        if self.directed:
            if v not in self.graph[u.name]:
                self.graph[u.name].append(v)
        else:
            if v not in self.graph[u.name] and u not in self.graph[v.name]:
                self.graph[u.name].append(v)
                self.graph[v.name].append(u)    
    
    def get_adjacency_list(self, vertex: Vertex):
        return self.graph[vertex.name]

    def print_graph(self):
        print("Graph")
        for vertex in self.vertices:
            print(vertex, "ADJACENCY LIST:",self.get_adjacency_list(vertex))
    
