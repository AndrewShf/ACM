class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
	    # strip, remove whitespace in bottom and top
        str = str.strip()
        try:
            ''' ^:start, 
            [\+\-]?: + and - can only appear no more than once 
            /d = num
            +: must appear at least once 
            '''
            res = re.search('(^[\+\-]?\d+)', str).group()
            res = int(res)
            res = res if res <= 2147483647 else 2147483647
            res = res if res >= -2147483648 else -2147483648
    	# if illegal, jump out res = 0
        except:
            res = 0
        return res
