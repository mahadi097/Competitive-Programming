class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        n_o = n // 2 + (1 if n & 1 == 1 else 0)
        n_e = n // 2
        m_o = m // 2 + (1 if m & 1 == 1 else 0)
        m_e = m // 2

        return (n_o * m_e) + (n_e * m_o)