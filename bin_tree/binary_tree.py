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

  def PrintInOrderNonRec(self):
    """ Print in order, but non recursively
    """
    stack = []
    cur = self
    while True:
      while cur is not None:
        stack.append(cur)
        cur = cur.left
      if len(stack) > 0 and cur is None:
        cur = stack.pop()
        print cur.data
        cur = cur.right
      elif len(stack) is 0 and cur is None:
        return
    pass


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

  def Delete(self, data):
    """ Delete element from tree. Three options have to be considered :-
    1. Element has no children (just make the parent's child link point to None
    2. Element has one child (Paren't new child is the deleted elements child)
    3. Element has 2 children (Replace the deleted element with the minimum element of
     the right sub-tree (to maintain the BST nature of the tree, and the delete that element)

    This function should only be called from Root.
    Returns the root. This is inserted because of the following possibility:
    Root is deleted, and root had only one child.
    """

    # Find the element and it's parent
    node_to_del, parent = self.IsPresent(data)
    if node_to_del is None:
      print "Node is not in Binary Tree!"
      return self

    # Case if there are no children (or 1 child)
    if node_to_del.left is None or node_to_del.right is None:
      # Have to take care of the case where node is Root
      if parent is None:
        if node_to_del.left is None:
          new_root = node_to_del.right
        else:
          new_root = node_to_del.left
        del node_to_del
        return new_root

      if node_to_del.data < parent.data:
        parent.left = node_to_del.left
      else:
        parent.right = node_to_del.right
      del node_to_del
      return self

    # Case with 2 children
    # Find the smallest element in right subtree
    new_replacement = FindMin(node_to_del.right)

    #Get the node and parent of the new replacement
    new_replacement, parent = self.IsPresent(new_replacement.data)
    node_to_del.data = new_replacement.data

    #Remove the parent's link to the new_replacement (which will then get deleted)
    # Since this is the smallest element, we can be guaranteed it doesn't have a left node
    parent.right = new_replacement.right

    del new_replacement
    return self

  def Depth(self):
    if self.left is None and self.right is None:
      return 1
    if self.left:
      l_depth = self.left.Depth()
    else:
      l_depth = 0
    if self.right:
      r_depth = self.right.Depth()
    else:
      r_depth = 0
    if l_depth > r_depth:
      return 1 + l_depth
    else:
      return 1 + r_depth


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

def FindMin(node):
  """ Find the minimum element in the binary search tree,
  rooted at the argument "node".
  """
  if node.left is None:
    return node
  else:
    return FindMin(node.left)



