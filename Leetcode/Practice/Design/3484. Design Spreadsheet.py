class Spreadsheet:

    def __init__(self, rows: int):
        self.ss = [[0 for _ in range(26)] for _ in range(rows)]

    def setCell(self, cell: str, value: int) -> None:
        r = self.getRow(cell[1:])
        c = self.getCol(cell[0])
        self.ss[r][c] = value

    def resetCell(self, cell: str) -> None:
        self.setCell(cell, 0)

    def getValue(self, formula: str) -> int:
        xy = formula[1:]
        x, y = xy.split('+')
        
        x = self.getRefVal(x)
        y = self.getRefVal(y)

        return x+y
    
    def getCol(self, col: str) -> int:
        return ord(col) - ord('A')
    
    def getRow(self, row: str) -> int:
        return int(row) - 1
    
    def getRefVal(self, ref: str) -> int:
        if ref[0].isalpha():
            r = self.getRow(ref[1:])
            c = self.getCol(ref[0])
            val = self.ss[r][c]
        else:
            val = int(ref)
        
        return val


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)