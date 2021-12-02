equation_separator = "->"

def get_value_length(line):
    py_length = len(line)
    value_length = py_length
    char_skip = 0

    for i, character in enumerate(line):
        if char_skip > 0:
            char_skip -= 1
            continue
        else:
            if character == "\\":
                print(f"Line: {line} has a \\ at position {i}")
                if line[i+1] == "\\" or line[i+1] == "\"":
                    value_length -= 1
                    char_skip = 1
                elif line[i+1] == "x":
                    value_length -= 3
                    char_skip = 3

    return value_length

def get_encoded_length(line):
    py_length = len(line) + 4
    encoded_length = py_length
    char_skip = 0

    for i, character in enumerate(line):
        if character == "\\" or character == "\"":
            print(f"Line: {line} has a \\ at position {i}")
            encoded_length += 1
            
    return encoded_length

def process_line(line):
    code_length = len(line) + 2

    encoded_length = get_encoded_length(line)

    return encoded_length - code_length
        


# def line_interpret()

def process_input(contents):
    lines = contents.split("\n")
    total_length_diff = 0

    for line in lines:
        total_length_diff += process_line(line)
    
    return total_length_diff

if __name__ == "__main__":
  f = open("../../input/2015/input7.txt", "r")
  contents = f.read()
  total_length_diff = process_input(contents)
  print(f"The difference between the various code lengths and value lengths is: {total_length_diff}")