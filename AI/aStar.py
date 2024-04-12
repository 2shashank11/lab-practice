class Graph:
    def __init__(self):
        self.graph = {
            'A': [('B', 6), ('F', 3)],
            'B': [('A', 6), ('C', 3), ('D', 2)],
            'C': [('B', 3), ('D', 1), ('E', 5)],
            'D': [('B', 2), ('C', 1), ('E', 8)],
            'E': [('C', 1), ('D', 8), ('I', 5), ('J', 5)],
            'F': [('A', 3), ('G', 1), ('H', 7)],
            'G': [('F', 1), ('I', 3)],
            'H': [('F', 7), ('I', 2)],
            'I': [('E', 5), ('G', 3), ('H', 2), ('J', 3)],
            'J': [('E', 5), ('I', 3)]
        }
        self.vertices = len(self.graph)
    
    def heuristic(self, v):
        H_dist = {
            'A': 10,
            'B': 8,
            'C': 5,
            'D': 7,
            'E': 3,
            'F': 6,
            'G': 5,
            'H': 3,
            'I': 1,
            'J': 0
        }
        return H_dist[v]

    def aStarAlgo(self, src, goal):
        queue = []
        queue.append((self.heuristic(src), 0, src, [src]))
        frontier = []
        visited = []

        while queue:
            queue.sort()
            _, cost, current, path = queue.pop(0)

            if current == goal:
                print(path)
                print(f'Cost: {cost}')
                return

            visited.append(current)

            for neighbour, toReachCost in self.graph[current]:
                new_cost = cost + toReachCost

                if neighbour not in visited and neighbour not in frontier:
                    new_path = path + [neighbour]
                    queue.append((new_cost + self.heuristic(neighbour), new_cost, neighbour, new_path))
                    frontier.append(neighbour)

                elif neighbour in frontier:
                    for i in range(len(queue)):
                        if queue[i][2] == neighbour:
                            if new_cost + self.heuristic(neighbour) < queue[i][0]:
                                queue.pop(i)
                                new_path = path + [neighbour]
                                queue.append((new_cost + self.heuristic(neighbour), new_cost, neighbour, new_path))


g = Graph()
g.aStarAlgo('A', 'J')
