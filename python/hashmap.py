import random

class MyHashMap:

    def __init__(self, size):
        self.size = size
        self.hash_table = [[] for _ in range(self.size)]

    def hash_f(self, key):
        # ensure key is an integer/number
        if isinstance(key, str):
            key = len(key)
        if key == []:
            return None
        key = key * 1023
        key = key+key
        return key % self.size

    def print_table(self):
        print("Start")
        for i in self.hash_table:
            print(f"{'':<5} {i}: {self.hash_f(i)}")
        print("End")

    def hash_put(self, key):
        index = self.hash_f(key)
        for i in range(len(self.hash_table)):
            tri = (index + i) % self.size
            if not self.hash_table[tri]:
                self.hash_table[tri] = key
                break

    def hash_lookup(self, key):
        index = self.hash_f(key)
        for i in range(len(self.hash_table)):
            tri = (index + i) % self.size
            if self.hash_table[tri] == key:
                return {self.hash_table[tri]: tri}
             
    def hash_remove(self, key):
        index = self.hash_f(key)
        for i in range(len(self.hash_table)):
            tri = (index + i) % self.size
            if self.hash_table[tri] == key:
                self.hash_table[tri] = None


if __name__ == "__main__":

    hash_table = MyHashMap(10)

    hash_table.hash_put("jake")
    hash_table.hash_put("dan")
    hash_table.hash_put(5)
    hash_table.hash_put(4)
    hash_table.hash_put(100)
    hash_table.hash_put(100)

    #hash_table.print_table()

    print(hash_table.hash_lookup(100))
    hash_table.hash_remove("jake")
    print(hash_table.hash_lookup("jake"))
