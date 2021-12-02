equation_separator = "->"

commands = {
    "AND":True,
    "LSHIFT":True,
    "RSHIFT":True,
    "NOT":True,
    "OR":True
}

class Wire:
    def __init__(self, id, _source):
        self.identifier = id
        self.source = _source
        self.inputs = []
        self.signal = None

class Circuit:
    def __init__(self):
        self.wires = {}
        self.to_evaluate = []

    def add_line(self, line):
        pieces = line.split(" ")
        separator = pieces.index(equation_separator)
        
        self.to_evaluate.append(pieces[-1])
        self.wires[pieces[-1]] = Wire(pieces[-1], pieces[0:separator])


    def interpret_source(self, id, pieces):
        # pieces = self.wires[id].source.split(" ")
        can_evaluate = True

        for i, piece in enumerate(pieces):
            if piece in self.wires:
                if not self.wires[piece].signal == None:
                    pieces.pop(i)
                    pieces.insert(i,self.wires[piece].signal)
                else:
                    can_evaluate = False
            elif not piece.isdigit() and not piece in commands:
                can_evaluate = False

        self.wires[id] = Wire(id,pieces)

        return can_evaluate

    def evaluate_source(self, id, pieces):
        while len(pieces)>1:
            for i, piece in enumerate(pieces):
                if piece == "NOT":
                    temp = ~int(pieces[i+1]) & 65535
                    pieces.pop(i)
                    pieces.pop(i)
                    pieces.insert(i,str(temp))
                    break
                elif piece == "AND":
                    temp = int(pieces[i-1]) & int(pieces[i+1])
                    pieces.pop(i)
                    pieces.pop(i)
                    pieces.pop(i-1)
                    pieces.insert(i-1,str(temp))
                    break
                elif piece == "OR":
                    temp = int(pieces[i-1]) | int(pieces[i+1])
                    pieces.pop(i)
                    pieces.pop(i)
                    pieces.pop(i-1)
                    pieces.insert(i-1,str(temp))
                    break
                elif piece == "RSHIFT":
                    temp = int(pieces[i-1]) >> int(pieces[i+1])
                    pieces.pop(i)
                    pieces.pop(i)
                    pieces.pop(i-1)
                    pieces.insert(i-1,str(temp))
                    break
                elif piece == "LSHIFT":
                    temp = int(pieces[i-1]) << int(pieces[i+1])
                    pieces.pop(i)
                    pieces.pop(i)
                    pieces.pop(i-1)
                    pieces.insert(i-1,str(temp))
                    break

        print(f"{pieces[0]} for {id} signal")
        self.wires[id].signal = pieces[0]

        if id in self.to_evaluate:
            self.to_evaluate.remove(id)

    def evaluate_until_id(self, id):
        while(self.wires[id].signal==None):
            for eval_id in self.to_evaluate:
                can_evaluate = self.interpret_source(eval_id, self.wires[eval_id].source)

                if(can_evaluate):
                    self.evaluate_source(eval_id,self.wires[eval_id].source)

        return self.wires[id].signal


        


# def line_interpret()

def process_input(contents):
    c = Circuit()
    lines = contents.split("\n")
    for line in lines:
        c.add_line(line)
    
    c.evaluate_until_id("a")
    replacing_signal = c.wires["a"].signal

    c.wires.clear()
    for line in lines:
        c.add_line(line)

    c.wires["b"].source = [replacing_signal]
    return c.evaluate_until_id("a")



if __name__ == "__main__":
  f = open("../../input/2015/input6.txt", "r")
  contents = f.read()
  a_signal = process_input(contents)
  print(f"Signal provided to a is: {a_signal}")