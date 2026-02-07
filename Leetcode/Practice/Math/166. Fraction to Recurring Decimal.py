class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        n, d, r = abs(numerator), abs(denominator), abs(numerator)
        dividend_in = defaultdict(int)
        decimal = False
        repeat_start = -1
        fr = ""
        if (numerator < 0) ^ (denominator < 0):
            fr += "-"

        while r is not 0:
            n = r
            if decimal and dividend_in[n]: 
                repeat_start = dividend_in[n]
                break
            if n < d and not decimal:
                decimal = True
                if len(fr) == 0 or fr[-1] == '-':
                    fr += "0"
                fr += "."
            if decimal:
                dividend_in[n] = len(fr)

            first = True
            while n < d:
                n *= 10
                if not first:
                    fr += "0"
                first = False
            
            div = n // d
            fr += str(div)
            r = n % (d * div)
        
        if repeat_start is not -1:
            fr = fr[:repeat_start] + "(" + fr[repeat_start:] + ")"

        if len(fr) == 0 or fr[-1] == '-':
            fr = "0"

        return fr