from itertools import permutations

class Salesman():
    def __init__(self, lines):
        self.cities = []
        self.distances = {}
        self.paths = []
        self.path_lengths = []

        for line in lines:
            line_list = line.split()
            start_city = line_list[0]
            end_city = line_list[2]
            distance = line_list[4]
            if not start_city in self.cities:
                self.cities.append(line_list[0])
                self.distances[start_city] = {}
                self.distances[start_city][start_city] = 0
            if not end_city in self.cities:
                self.cities.append(line_list[2])
                self.distances[end_city] = {}
                self.distances[end_city][end_city] = 0
            
            self.distances[start_city][end_city] = int(distance)
            self.distances[end_city][start_city] = int(distance)
            
        self.get_paths()

    def get_paths(self):
        for path in permutations(self.cities):
            self.paths.append(path)

    def get_path_lengths(self):
        current_length = 0

        for i, path in enumerate(self.paths):
            for j, city in enumerate(path):
                if j >= len(path) - 1:
                    break
                else:
                    current_length += self.distances[city][path[j+1]]
            
            self.path_lengths.append(current_length)
            current_length = 0

def process_input(contents):
    lines = contents.split("\n")
    salesman = Salesman(lines)

    salesman.get_path_lengths()

    return min(salesman.path_lengths)
    
    # return total_length_diff

if __name__ == "__main__":
  f = open("../../input/2015/input8.txt", "r")
  contents = f.read()
  shortest_distance = process_input(contents)
  print(f"The shortest route is: {shortest_distance}")