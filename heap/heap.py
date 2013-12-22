# Implementation of a max heap
# Arrays are used to implement this heap
# Any node is greater than either of the children
# To get the children of a node at index n, look at index 2n and 2n+1
#
#
# Author: Prashant Malani <p.malani@gmail.com>



class Heap:
  def __init__(self, element_list):
    """Initialize the heap array with a few value. Doesn't have the heap
    property.
    """
    self.array = element_list[:]
    self.ConstructHeap()

  def MaxHeapify(self, i):
    """ Index i is where you want to start the heapification.
    """
    l = 2*i + 1
    r = 2*i + 2
    largest = i
    if l <= len(self.array) - 1:
      if self.array[l] > self.array[i]:
        largest = l
    if r <= len(self.array) - 1:
      if self.array[r] > self.array[largest]:
        largest = r
    if largest is not i:
      swap = self.array[i]
      self.array[i] = self.array[largest]
      self.array[largest] = swap
      self.MaxHeapify(largest)

  def ConstructHeap(self):
    """ Convert the array into a heap, basically call max_heapify on all the  children which have
    at most 2 children (max_heapify needs both sub children to have heap property
    """
    end_val = len(self.array) - 1
    end_val = (end_val - 1) / 2
    list_of_indices = range(end_val + 1)
    list_of_indices.reverse()
    for i in list_of_indices:
      self.MaxHeapify(i)

