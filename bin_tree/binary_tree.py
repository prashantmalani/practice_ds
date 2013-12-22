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
    if self.left != None:
      self.left.PrintInorder()

    print self.data

    if self.right != None:
      self.right.PrintInorder()

