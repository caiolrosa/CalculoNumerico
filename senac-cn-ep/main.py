import sys

if __name__ == "__main__":
    with open(sys.argv[1]) as f:
        strArr = f.read().split("\n")
        input = [i.split(" ") for i in strArr]
        input = [[float(j) for j in i] for i in input[:len(input) - 1]]
        print(input)
