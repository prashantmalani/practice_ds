# Implementation of quicksort
#
# Author: Prashant Malani <p.malani@gmail.com>
# Date : 12/23/2013
#
# Defines a class. Class get's initialized with a list of elements.
# Class has routines for recursive and non recursive implementations of quicksort

class QuickSort():
  def __init__(self, in_array):
    self.array = in_array

  def SortRec(self, beg, end):
    """ beg =  beginning index, end = end index
    This function is called by a wrapper, so we don't have to pass
    beginning and end arguments.
    """
    # End condition
    if beg >= end:
      return
    a = self.array
    i = beg
    j = end - 1
    pivot = a[end]
    while True:
      while a[i] < pivot and i < end:
        i = i + 1
      while a[j] > pivot and j > beg:
        j = j - 1
      if i < j:
        swap = a[i]
        a[i] = a[j]
        a[j] = swap
      else:
        swap = a[i]
        a[i] = a[end]
        a[end] = swap
        self.SortRec(beg, i - 1)
        self.SortRec(i + 1, end)
        return

  def SortRecursive(self):
    """ Function which calls the actual implementation.
    This conveniently avoids us having to send the index args
    """
    self.SortRec(0, len(self.array) - 1)

