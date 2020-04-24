class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) == 0:
            return 0
        if len(haystack) == 0:
            return -1
        # getfail:
        f = []
        f.append(0)
        f.append(0)
        for i in range(1, len(needle)):
            j = f[i]
            while j and needle[i]!=needle[j]:
                j = f[j]
            tmp = j+1 if needle[i]==needle[j] else 0
            f.append(tmp)
        
        # find
        j = 0
        for i in range(len(haystack)):
            while j and haystack[i]!=needle[j]:
                j = f[j]
            if needle[j] == haystack[i]:
                j = j+1
            if j==len(needle):
                #print(haystack[i:])
                return i-j+1
        return -1
