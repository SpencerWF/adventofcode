# Python 2015 Day 1 Code By Spencer Walker-Fooks

def follow_guide(str):
  floor = 0

  for char in str:
    if(char=="("):
      floor+=1
    elif(char==")"):
      floor-=1
    else:
      print(f"Character not recognised: {char}")

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
  f = open("input1.txt", "r")
  contents = f.read()
  floor = follow_guide(contents)
  print(f"Floor is: {floor}")