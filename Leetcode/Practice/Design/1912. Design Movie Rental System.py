class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.unrented = defaultdict(SortedList) # movies -> price, shop
        self.rented = SortedList() # price, shop, movie
        self.price = defaultdict(int) # (shop, movie) -> price

        for shop, movie, price in entries:
            self.unrented[movie].add([price, shop])
            self.price[(shop, movie)] = price

    def search(self, movie: int) -> List[int]:
        ln = min(len(self.unrented[movie]), 5)
        shops = []
        for i in range(ln):
            shops.append(self.unrented[movie][i][1])
        
        return shops

    def rent(self, shop: int, movie: int) -> None:
        price = self.price[(shop, movie)]
        self.unrented[movie].discard([price, shop])
        self.rented.add([price, shop, movie])

    def drop(self, shop: int, movie: int) -> None:
        price = self.price[(shop, movie)]
        self.rented.discard([price, shop, movie])
        self.unrented[movie].add([price, shop])

    def report(self) -> List[List[int]]:
        ln = min(len(self.rented), 5)
        rented = []
        for i in range(ln):
            rented.append(self.rented[i][1:])
        
        return rented


# Your MovieRentingSystem object will be instantiated and called as such:
# obj = MovieRentingSystem(n, entries)
# param_1 = obj.search(movie)
# obj.rent(shop,movie)
# obj.drop(shop,movie)
# param_4 = obj.report()