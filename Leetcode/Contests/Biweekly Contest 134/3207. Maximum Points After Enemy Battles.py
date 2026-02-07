from collections import deque


class Solution:
    def maximumPoints(self, enemyEnergies: List[int], currentEnergy: int) -> int:
        ans = 0
        enemyEnergies.sort()
        enemies = deque(enemyEnergies)
        
        while enemies:
            if currentEnergy < enemies[0]:
                if ans == 0:
                    return 0
                currentEnergy += enemies.pop()
            else:
                count = currentEnergy // enemies[0]
                ans += count
                currentEnergy -= count * enemies[0]
            
        return ans