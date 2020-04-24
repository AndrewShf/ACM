class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        #1. Using bin method return str in binary form
        #return bin(int(a, 2)+int(b,2))[2:]
        
        #2. recursive method
        if len(a)==0:
            return b
        if len(b)==0:
            return a
        if a[-1] != b[-1]:
            return self.addBinary(a[:-1], b[:-1])+'1'
        if b[-1] == '1':
            return self.addBinary(self.addBinary(a[:-1], '1'), b[:-1]) + '0'
        else:
            return self.addBinary(a[:-1], b[:-1]) + '0'
