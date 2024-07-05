# Linked list example going off of the example created in C in this dir

class Node:
    """ Initializing Node Parameters """
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """ Initializing Node Parameters """
    def __init__(self):
        self.head = None

    def insert_at_head(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        else:
            new_node.next = self.head
            self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        tmp = self.head
        while tmp.next is not None:
            tmp = tmp.next
        tmp.next = new_node
    
    def insert_at_index(self, data, index):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        pos = 0
        tmp = self.head
        while tmp.next != None and pos != index:
            tmp = tmp.next
            pos += 1
        new_node.next = tmp.next
        tmp.next = new_node

    def find_node(self, value):
        if self.head is None:
            print("Error: head node is null")
            return
        tmp = self.head
        while tmp is not None:
            if tmp.data is value:
                return tmp
            tmp = tmp.next
        return 0

    def remove_node(self, node):
        if self.head == node:
            self.head = node.next
            node = None
            return
        tmp = self.head
        while tmp != None and tmp.next != node :
            tmp = tmp.next
        if tmp is not None:
            tmp.next = node.next
            node = None

    def sizeofLL(self):
        size = 0
        if self.head:
            tmp = self.head
            while tmp:
                size += 1
                tmp = tmp.next
            return size
        else:
            return 0

    def printLL(self):
        tmp = self.head
        while tmp is not None:
            print(tmp.data, end="")
            tmp = tmp.next
            if tmp is not None:
                print(" -> ", end="")
        print()


if __name__ == "__main__":

    head = LinkedList()
    head.insert_at_head(10)
    head.insert_at_end(5)
    head.insert_at_head(20)
    head.insert_at_end(50)
    head.insert_at_index(6,1)
    head.printLL()

    if head.find_node(10):
        print("found")
    else:
        print("not found")
    
    head.remove_node(head.find_node(10))
    head.printLL()

    if head.find_node(10):
        print("found")
    else:
        print("not found")

    print(head.sizeofLL())


