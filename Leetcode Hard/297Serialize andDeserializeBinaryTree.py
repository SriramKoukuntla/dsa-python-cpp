# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        :type root: TreeNode
        :rtype: str
        """
        ret = []
        def helper(node):
            if node == None:
                ret.append("N")
                return
            ret.append(str(node.val))
            helper(node.left)
            helper(node.right)
        helper(root)
        return ",".join(ret)
    
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        arr = data.split(",")
        self.i = 0
        def helper():
            if arr[self.i] == "N":
                self.i += 1
                return None
            node = TreeNode(int(arr[self.i]))
            self.i += 1
            node.left = helper()
            node.right = helper()
            return node
        return helper()
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))