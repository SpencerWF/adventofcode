# Python 2015 Star 3 Code By Spencer Walker-Fooks

def get_total_area(contents):
  lines = contents.split("\n")
  total_area = 0
  for line in lines:
    if(line!=''):
      sides = line.split("x")
      print(f"{line}")
      line_area = get_surface_area(int(sides[0]), int(sides[1]), int(sides[2]))
      # print(f"Area {line_area} from list {sides}")
      total_area += line_area

  return total_area

def get_surface_area(length, width, height):
  surface_area = 0
  side_1 = 2*length*width
  smallest_side = side_1
  side_2 = 2*width*height

  if(smallest_side>side_2):
    smallest_side = side_2

  side_3 = 2*height*length

  if(smallest_side>side_3):
    smallest_side = side_3

  smallest_side = smallest_side/2

  print(f"Side 1:{side_1} Side 2:{side_2} Side 3:{side_3} Smallest Side:{smallest_side}")

  surface_area = side_1 + side_2 + side_3 + smallest_side

  return surface_area


def test():
  print("No Tests for This Star")

if __name__ == "__main__":
  f = open("../../input/2015/input2.txt", "r")
  contents = f.read()
  total_area = get_total_area(contents)
  print(f"Total Area is: {total_area}")