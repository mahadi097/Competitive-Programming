class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        n, m = len(skill), len(mana)
        done = [0] * n
        for i, p in enumerate(mana):
            for j, w in enumerate(skill):
                if i == 0:
                    done[j] = p*w if j == 0 else done[j-1] + p*w
                else:
                    if j == 0:
                        done[j] += p*w
                    else:
                        done[j] = max(done[j], done[j-1]) + p*w
            for j in range(n-2, -1, -1):
                done[j] = done[j+1] - (p * skill[j+1])
        
        return done[n-1]