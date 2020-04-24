class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        d = {'(':')', '[':']', '{':'}'}
        stk = []
        # for char in s: not for char in range(len(s))...
        for char in s:
            # check main key
            if char in d:
                stk.append(char)
            else:
                if len(stk) == 0:
                    return False
                else:
                    top_element = stk.pop()
                    if d[top_element] != char:
                        return False
        return not stk
