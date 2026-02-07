class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort(reverse=True)
        pairs = []
        for spell in spells:
            st, en, c = 0, len(potions)-1, 0
            while st <= en:
                mid = (st + en) // 2
                if spell*potions[mid] >= success:
                    c = mid + 1
                    st = mid + 1
                else:
                    en = mid - 1
            pairs.append(c)
        
        return pairs