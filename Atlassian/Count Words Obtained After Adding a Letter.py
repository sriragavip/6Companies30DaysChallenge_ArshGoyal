class Solution:
    def wordCount(self, startWords, targetWords):
        dicts = {}
        for i in startWords:
            li = []
            for j in i:
                li.append(j)
            li.sort()
            dicts[tuple(li)] = 1
        count = 0
        for i in targetWords:
            li = []
            for j in i:
                li.append(j)
            li.sort()
            li = tuple(li)
            for j in range(len(li)):
                if dicts.get(li[:j]+li[j+1:]):
                    count+=1
                    break
        return count
        