# Practice implementation of a binary tree in python
# Should perform basic operations like insert, delete,
# and different traversals (inorder, preorder, postorder)
#
# Author: Prashant Malani <p.malani@gmail.com>
# Date  : 12/21/2013
#
#-------------------------------------------------------------------
# Usage: Start the python interpreter, then run:
# import binary_tree
# After that, initialize a root node, and you can run all your operations from that
# root = Node(8)
# root.Insert
#

class Node:
  """ Node variable. Left node, right node, and data
  """
  def __init__(self, data):
    self.left = None
    self.right = None
    self.data = data

  def Insert(self, data):
    if data > self.data:
      if self.right == None:
        self.right = Node(data)
      else:
        self.right.Insert(data)
    else:
      if data < self.data:
        if self.left == None:
          self.left = Node(data)
        else:
          self.left.Insert(data)

  def PrintInorder(self):
    """ Recursive implementation of inorder traversal.
    """
    if self.left != None:
      self.left.PrintInorder()

    print self.data

    if self.right != None:
      self.right.PrintInorder()

  def IsPresent(self, data, parent=None):
    """ Search if a given element is present in the
    tree.
    Return the node and it's parent if the element is found.
    """
    if self.data == data:
      print 'Element is present'
      return self, parent
    elif data > self.data:
      if self.right is None:
        print 'Element is not present'
        return None, None
      return self.right.IsPresent(data, self)
    else:
      if self.left is None:
        print 'Element is not present'
        return None, None
      return self.left.IsPresent(data, self)

# Helper function to set up an initial binary tree:
#                8
#              /   \
#             3     10
#           /   \      \
#          1     6      14
#              /   \   /
#             4     7 13
#
def SetupBinTree():
  root = Node(8)
  root.Insert(3)
  root.Insert(10)
  root.Insert(1)
  root.Insert(6)
  root.Insert(4)
  root.Insert(7)
  root.Insert(14)
  root.Insert(13)
  return root


