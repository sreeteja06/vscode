class hello:
    def __init__(self, first, second="hello"):
        self.first = first
        self.second = second
        print(self.first+" "+self.second)
    
def main():
    name_first="sree"
    name_last="teja"
    hello(name_first, name_last)
    hello("test", "name")


if __name__ == '__main__':
    main()
    