class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        ones = [0 for _ in range(n)]
        zeros = deque()
        for i in range(n):
            ones[i] = ones[i-1] + (s[i] == '1')
            if s[i] == '0':
                zeros.append(i)

        ans = 0
        for i in range(n):
            c, ln = 1, n-i
            c1 = ln
            if len(zeros) > 0:
                c1 = zeros[0] - i
            ans += c1
            while c + c*c <= ln and c <= len(zeros):
                j = zeros[c-1]
                c1 = ones[j]
                if i > 0:
                    c1 -= ones[i-1]
                j_next = n
                if c+1 <= len(zeros):
                    j_next = zeros[c]
                need1 = max(0, c*c-c1)
                if j+need1 < j_next:
                    ans += (j_next - (j+need1))
                c += 1
            if s[i] == '0':
                zeros.popleft()
        
        return ans