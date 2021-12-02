# Python 2015 Day 1 Code By Spencer Walker-Fooks

def follow_guide(str):
  basement_flag = True
  position = 1
  floor = 0

  for char in str:
    if(char=="("):
      floor+=1
    elif(char==")"):
      floor-=1
    else:
      print(f"Character not recognised: {char}")

    if(basement_flag and floor==-1):
      print(f"First Basement Entrance at Position: {position}")
      basement_flag = False
    
    position += 1

  return floor

def test():
  test_set = [
    "(())",
    "()()",
    "(((",
    "(()(()(",
    "))(((((",
    "())",
    "))(",
    ")))",
    ")())())"
  ]

  result_set = [
    0,0,3,3,3,-1,-1,-3,-3
  ]

  floor = 0
  for i in range(len(test_set)):
    floor = follow_guide(test_set[i])
    assert floor==result_set[i]
    floor = 0
  
  print("Completed Tests Successfully")

if __name__ == "__main__":
  f = open("../../input/input1.txt", "r")
  contents = f.read()
  floor = follow_guide(contents)
  print(f"Floor is: {floor}")