#!/usr/bin/python2.7
# Python implementation of counting sort
# Author : Prashant Malani <p.malani@gmail.com
# Date : 1/2/2014
#
import sys

def csort(in_array):
  """ C sort algorithm  implementation.
  Input is an un sorted array, output is sorted array."""

  # keep track of min and max allows us to use negative numbers, but it
  # has to be handled carefully.
  min_el = min(in_array)
  max_el = max(in_array)

  #array to store number of elements less than or equal to a given element.
  c = [0 for i in range(0, max_el-min_el + 1)]
  for i in in_array:
    c[i - min_el] = c[i - min_el] + 1

  for i in range(1, len(c)):
    c[i] = c[i] + c[i-1]

  b = [0 for x in range(len(in_array))]
  for j in reversed(in_array):
    b[c[j - min_el] - 1] = j
    c[j - min_el] = c[j - min_el] - 1
  return b

if __name__ == "__main__":
  if len(sys.argv) is not 2:
    print 'Format is ./csort.py "<list of elements to be sorted, comma separated>"'
    exit(1)
  in_str = sys.argv[1]
  in_list = in_str.split(",")
  in_array = [int(x) for x in in_list]
  sorted_list = csort(in_array)
  print sorted_list
