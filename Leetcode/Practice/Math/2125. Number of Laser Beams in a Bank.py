class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        ans = prv_beams = 0
        for row in bank:
            beams = row.count('1')
            if beams:
                ans += (prv_beams * beams)
                prv_beams = beams

        return ans