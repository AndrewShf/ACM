class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        prefix=[]
        for x in zip(*strs):
            print(x)
            if len(set(x)) == 1: # set has only one element
                prefix.append(x[0])
            else:
                break
        return "".join(prefix) # how to tranfer list to str
