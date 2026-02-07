class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        c = 0
        for f in fruits:
            unplaced = True
            for i in range(len(baskets)):
                if baskets[i] >= f:
                    baskets[i] = 0
                    unplaced = False
                    break
            c += (unplaced == True)

        return c