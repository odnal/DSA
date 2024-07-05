# well.. a stack in python is just a list but will still do for implementation purposes

class Stack:

    def __init__(self):
        self.stack = []

    def push(self, val):
        self.stack.append(val)

    def pop(self):
        if self.stack:
            self.stack.pop()

    def peek(self):
        if self.stack:
            return self.stack[-1]

    def show(self):
        print(self.stack)


if __name__ == "__main__":

    stack_obj = Stack()
    print(stack_obj)
    stack_obj.push(1)
    stack_obj.push(2)
    stack_obj.push(3)
    stack_obj.show()
    top = stack_obj.peek()
    print(top)
    stack_obj.pop()
    stack_obj.show()
    top = stack_obj.peek()
    print(top)

