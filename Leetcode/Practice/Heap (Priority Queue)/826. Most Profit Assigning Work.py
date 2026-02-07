class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(difficulty, profit))
        worker.sort()
        
        mxProfit = mxCurrent = pos = 0
        for w in worker:
          while pos < len(jobs) and w >= jobs[pos][0]:
            mxCurrent = max(mxCurrent, jobs[pos][1])
            pos += 1
          mxProfit += mxCurrent
          
        return mxProfit