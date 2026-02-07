class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[] for _ in range(numRows)]

        for i in range(numRows):
            for j in range(i+1):
                if j == 0 or j == i:
                    ans[i].append(1)
                else:
                    ans[i].append(ans[i-1][j-1] + ans[i-1][j])

        return ans