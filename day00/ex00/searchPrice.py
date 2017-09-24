import sys

class art:
    def __init__(self, name, price):
        self.name = name
        self.price = price
    def __str__(self):
        return self.name + "  " + str(self.price)

if __name__ == "__main__":
    with open("art.txt", "r") as file:
        array = []
        error = False
        for line in file:
            try: 
                if error is True:
                    line = tmp + line
                name, number = line.split(" => ")
            except ValueError: 
                error = True
                tmp = line.strip()
            else:
                error = False
                array.append(art(name, int(number)))

    for i in range(1, len(sys.argv)):
        for j in array:
            if j.name == sys.argv[i]:
                print(j.price)
