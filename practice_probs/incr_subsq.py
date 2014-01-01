#!/usr/bin/python2.7
# Given an unsorted array, find the max length of subsequence in which the
# numbers are in incremental order.
#
# For example: If the input array is {7, 2, 3, 1, 5, 8, 9, 6}, a subsequence with the most
# numbers in incremental order is {2, 3, 5, 8, 9} and the expected output is 5.
#
#
# Author: Prashant Malani <p.malani@gmail.com
# Date: 01/01/2014
#
import sys

def find_incr_sub_max(in_list):
  # Initialize a array to store the max_subsequence length for each element
  max_length = [1 for i in range(len(in_list))]

  for i in range(1, len(in_list)):
    min = sys.maxint

    # Iterate over each previous value, if you are larger, and if the resulting
    # subsequence is longer, update your max_length
    for j in range(0, i):
      if (in_list[i] > in_list[j] and max_length[j] + 1 > max_length[i]):
        max_length[i] = max_length[j] + 1

  return max(max_length)

if __name__ == "__main__":
  array = [7, 2, 3, 1, 5, 8, 9, 6]
  result = find_incr_sub_max(array)
  print "Array = " + ''.join(str(array))
  print "Length of max incremental subsequence is :" + str(result)
