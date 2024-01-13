class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
      m, n, c = len(img), len(img[0]), 0
      ans = [[0 for _ in range(n)] for _ in range(m)]
      
      for i in range(m):
        rowStart, rowEnd = max(0, i - 1), min(m, i + 2)
        for j in range(n):
          colStart, colEnd = max(0, j - 1), min(n, j + 2)
          for l in range(rowStart, rowEnd):
            c += len(img[l][colStart:colEnd])
            ans[i][j] += sum(img[l][colStart:colEnd])
          ans[i][j] //= c
          c = 0
          
      return ans