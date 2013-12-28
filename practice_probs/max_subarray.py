# A sub-array has one number of some continuous numbers. Given an integer array
# with positive numbers and negative numbers, get the maximum sum of all sub-arrays. Time complexity should be O(n).
#
# For example, in the array {1, -2, 3, 10, -4, 7, 2, -5}, its sub-array {3, 10, -4, 7, 2} has the maximum sum 18.
#
#
#
def max_subarray(list_nums):
  max_array = -1000000000
  cur_sum = 0
  start = 0
  end = 0
  for i in range(len(list_nums)):
    cur_sum = cur_sum + list_nums[i]

    if cur_sum < list_nums[i]:
      # Our new number is greater than the sub array, hence start and end have to be updated to the new val
      cur_sum = list_nums[i]
      start = i
      end = i;

    if cur_sum > max_array:
      max_array = cur_sum
      end = i

  return max_array, start, end

if __name__ == "__main__":
  list_nums = [1, -2, 3, 10, -4, 7, 3, 4, -5]
  result, start, end = max_subarray(list_nums)

  print "Max subarray sum is:" + str(result) + " and subarray is " + str(list_nums[start:end])
