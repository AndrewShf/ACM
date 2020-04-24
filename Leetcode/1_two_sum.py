class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        '''
	# first solution TLE
        for i,v1 in enumerate(nums):
            for j,v2 in enumerate(nums[i+1:]):
                if v2+v1 == target:
                    return [i, j+i+1] # time limit exceed, using enumerate?
        '''
        d = {} #using dict
        for i, v in enumerate(nums):
            want = target-v
            if want not in d:
                d[v] = i
            else:
                return [d[want], i]
