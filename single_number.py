
class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        apro = {}
        v = 0
        ss = 0
        ss2 =0
        for it in A:
            ss += it
            if it not in apro:
                apro[it] = v
                v+=1
                ss2 += it
        return ss2*2-ss
            
        
