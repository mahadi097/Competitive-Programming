class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        r1 = version1.split('.')
        r2 = version2.split('.')

        ln = max(len(r1), len(r2))
        while len(r1) < ln:
            r1.append('0')
        while len(r2) < ln:
            r2.append('0')

        for i in range(ln):
            vr1 = int(r1[i])
            vr2 = int(r2[i])

            if vr1 < vr2:
                return -1
            elif vr1 > vr2:
                return 1

        return 0