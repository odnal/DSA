import time

# Quick example problem on permuatations
# Q: Given the set (1,2,3) determine the number of possible permutations
#    that can be achieved.
# Formula: P(n,r) = n!/(n-r)!

# non-recursive
def permute(array):
    if array is None:
        return []
    if len(array) == 1:
        return [array]

    array.sort()
    perm = []
    permuatations = []
    stack = [-1]

    while len(stack):
        index = stack.pop()
        index += 1
        while index < len(array):
            if array[index] not in perm:
                break
            index += 1
        else:
            if len(perm):
                perm.pop()
            continue
        perm.append(array[index])
        stack.append(index)
        stack.append(-1)
        if len(perm) == len(array):
            permuatations.append(perm)
            print(permuatations)
    return permuatations 

# note, the recursive approach splits up the call to the function in sublists
def permute_recursive(array):
    if array is None:
        return []
    if len(array) == 1:
        return [array]

    permuatations = []
    for i in range(len(array)):
        m = array[i]
        rem_list = array[:i] + array[i+1:]
        for perm in permute_recursive(rem_list):
            permuatations.append([m]+perm)

    return permuatations

# Examples focusing on recursion
# note, that once recursion has terminated the cpu has to cycle 
# all the returns that are currently on the call stack - the last
# thing poped should be the answer - hence why steps prints sequentially 
# from 1-5 if we use the print statement after the recursive call and in reverse if we use it before the recursive call
def walk(steps):
    if steps < 1: return
    print("Steps",steps)
    walk(steps-1)
    #print("Steps",steps)

def factorial(n):
    if n < 1: return 1
    return n*factorial(n-1)

def power(base, exponent):
    if exponent < 1: return 1
    return base * power(base, exponent-1)
'''
power(2,5):
   call stack   ----> popping off of call stack and return answer is 2*16 = 32
 2 * power(2,0)       2 * power(2,4)   2 * 16
 2 * power(2,1)       2 * power(2,3)   2 * 8
 2 * power(2,2)       2 * power(2,2)   2 * 4
 2 * power(2,3)       2 * power(2,1)   2 * 2
 2 * power(2,4)       2 * power(2,0)   2 * 1 
'''
nums = [1,2,3]
#nums = [x for x in range(10)]
start = time.perf_counter()
#permute_recursive(nums)
#permute(nums)
permute(nums)
end = time.perf_counter()
print(end-start)


walk(5)
print(factorial(7))
print(power(2,5))
