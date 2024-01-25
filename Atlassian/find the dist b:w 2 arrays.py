class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:        
        def check(x, y, d):
            return abs(x - y) > d
        
        cnt = 0
        for n1 in arr1:
            is_valid = True
            for n2 in arr2:
                if not check(n1, n2, d):
                    is_valid = False
            if is_valid:
                cnt += 1
        return cnt
    
        arr2.sort()
        res = 0
        
        for i in arr1:
            is_valid = True
            
            st = 0
            en = len(arr2) - 1
            while st <= en:
                m = (st + en) // 2
                
                if abs(arr2[m] - i) <= d:
                    is_valid = False
                    break
                
                elif arr2[m] > i:
                    en = m - 1
                else:
                    st = m + 1
            if is_valid:
                res += 1
                
        return res