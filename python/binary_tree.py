# Example creating binary tree and a few tree traversal's

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.right = right
        self.left = left

# An iterative way to create a binary tree from the input array
# This is essentially BFS (level order traversal)
def insert_level_order(arr):
    if not arr:
        return None

    root = TreeNode(arr[0])
    queue = [root]

    i = 1
    while i < len(arr):
        node = queue.pop(0)

        if i < len(arr):
            node.left = TreeNode(arr[i])
            queue.append(node.left)
            i += 1

        if i < len(arr):
            node.right = TreeNode(arr[i])
            queue.append(node.right)
            i += 1

    return root
        
    """ 
    # A recursive approach to creating a binary tree from an input array
def insert_level_order(arr, root, i, n):
    # base case
    if i < n:
        temp = TreeNode(arr[i])
        root = temp

        l = 2*i + 1
        r = 2*i + 2

        root.left = insert_level_order(arr, root.left, l, n)
        root.right = insert_level_order(arr, root.right, r, n)

    return root 
    """

# Level order traversal - BFS
def level_order_traversal(root):
    stack = [] # stores nodes with respective level
    if not root:
        return stack

    q = [root]
    level = 0
    while q:
        for i in range(len(q)):
            node = q.pop(0)
            stack.append([node.val, level+1])
            if node.left:
                q.append(node.left)

            if node.right:
                q.append(node.right)

        level += 1 

    return stack

# The order traversals below are all DFS techniques
def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

def preorder_traversal(root):
    return [root.val] + preorder_traversal(root.left) + preorder_traversal(root.right) if root else []

def postorder_traversal(root):
    return postorder_traversal(root.left) + postorder_traversal(root.right) + [root.val] if root else []

def pre_order(root):
    if not root:
        return 
    
    print(root.val, end=" ")
    pre_order(root.left)
    pre_order(root.right)

def in_order(root):
    if not root:
        return 
    
    in_order(root.left)
    print(root.val, end=" ")
    in_order(root.right)

def post_order(root):
    if not root:
        return 
    
    post_order(root.left)
    post_order(root.right)
    print(root.val, end=" ")

# Iterative DFS traversals
def iterative_preorder(root):

    if not root:
        return None
        
    stack = [root]
    res = []
    while stack:
        node = stack.pop()
        res.append(node.val)
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)

    return res

def iterative_inorder(root):

    if not root:
        return None
        
    stack = []
    res = []
    node = root
    while True:
        if node:
            stack.append(node)
            node = node.left
        else:
            if not stack: break
            node = stack[-1]
            res.append(node.val)
            stack.pop()
            node = node.right
    
    return res

def iterative_postorder(root):

    if not root:
        return None
        
    stack = [root]
    res = []
    while stack:
        node = stack.pop()
        res.append(node.val)
        if node.left:
            stack.append(node.left)
        if node.right:
            stack.append(node.right)

    #res.reverse()
    #return res
    #return list(reversed(res))
    return res[::-1] # kind of a hack (we actually dont visit every node in post order fashion) below is actual way

    """
    if not root:
        return None
        
    stack = []
    res = []
    while stack or root:
        while root:
            if root.right:
                stack.append(root.right)
            stack.append(root)
            root = root.left
        node = stack.pop()
        if stack and stack[-1] == node.right:
            root = stack.pop()
            stack.append(node)
        else:
            res.append(node.val)
    return res 
    """

class Solution:
    def lca(self, root: "TreeNode", p: "TreeNode", q: "TreeNode"):
        
        def dfs(root, p, q):

            if not root or root.val == p.val or root.val == q.val:
                return root

            lh = dfs(root.left, p, q)
            rh = dfs(root.right, p, q)

            if not lh:
                return rh
            elif not rh:
                return lh
            else:
                return root
        return dfs(root, p, q)

    def level_order(self, root: "TreeNode"):
        if not root:
            return []

        stack = [(root, 0)]
        level = 0
        res = []
        while stack:
            node, level = stack.pop()
            if level == len(res):
                res.append([])
            res[level].append(node.val)
            if node.right:
                stack.append((node.right, level+1))
            if node.left:
                stack.append((node.left, level+1))

        return res

    def diameter_of_tree(self, root):
        maxi = 0
        def dfs(root):
            nonlocal maxi
            if not root:
                return 0

            lh = dfs(root.left)
            rh = dfs(root.right)
            
            maxi = max(maxi, lh+rh)

            return 1 + max(lh, rh)

        dfs(root)
        return maxi

    def isBalanced(self, root):
        def dfs(root):
            if not root:
                return 0
            lh = dfs(root.left)
            rh = dfs(root.right)

            if lh == -1 or rh == -1 or abs(lh-rh) > 1:
                return -1
            return 1 + max(lh, rh)
        return dfs(root) != -1

    def height(self, root):
        def dfs(root):
            if not root:
                return 0, 0
            lh_left, rh_left = dfs(root.left)
            lh_right, rh_right = dfs(root.right)
            left_height = 1 + max(lh_left, rh_left)
            right_height = 1 + max(lh_right, rh_right)
            return left_height, right_height
        l, r = dfs(root)
        return l, r

    def sum_recur(self, root):
        if not root:
            return 0
        return root.val + self.sum_recur(root.left) + self.sum_recur(root.right)
    
    def sum_iter(self, root):
        if not root:
            return None
        stack = [root]
        res = 0
        while stack:
            node = stack.pop()
            res += node.val
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        return res


if __name__ == "__main__":

    arr = [1,3,4,6]

    root = insert_level_order(arr)
    #root = insert_level_order(arr, None, 0, len(arr))

    print(inorder_traversal(root))
    print(preorder_traversal(root))
    print(postorder_traversal(root))

    in_order(root)
    print()
    pre_order(root)
    print()
    post_order(root)
    print()

    print("HERE")
    print(level_order_traversal(root))
    print(Solution().level_order(root))


    print(iterative_inorder(root))
    print(iterative_preorder(root))
    print(iterative_postorder(root))


    tree = [5,3,8,1,4,7,9,None,2]
    root = insert_level_order(tree)
    print(preorder_traversal(root))
    print(Solution().lca(root, TreeNode(9), TreeNode(3)).val)
    print(Solution().level_order(root))

    import heapq
    test = [2,1,4]
    heap = [-x for x in test]
    heapq.heapify(heap)
    print(test)
    print(heap)
    heapq.heappop(heap)
    print(heap)
    heapq.heappush(heap, -3)
    print(heap)


    a = [1,2,3,3]
    t = insert_level_order(a)
    print("HERE")
    print(Solution().level_order(t))
    print(Solution().sum_recur(t))
    print(Solution().sum_iter(t))
    print(Solution().diameter_of_tree(t))


    x = [1,2,3,4,5,None,4,4,4,None,3,None,3]
    z = insert_level_order(x)
    print(Solution().level_order(z))
    print(Solution().isBalanced(z))
    print(Solution().height(z))

    x = [1,2,2,3,3,None,None,4,4]
    z = insert_level_order(x)
    print(Solution().level_order(z))
    print(Solution().isBalanced(z))
    print(Solution().height(z))
