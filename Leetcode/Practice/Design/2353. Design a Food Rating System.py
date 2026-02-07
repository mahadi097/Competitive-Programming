class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.fr = defaultdict(int)
        self.fc = defaultdict(str)
        self.cuisines = defaultdict(SortedList)

        for index, food in enumerate(foods):
            self.fr[food] = ratings[index]
            self.fc[food] = cuisines[index]
            self.cuisines[cuisines[index]].add((-ratings[index], food))

    def changeRating(self, food: str, newRating: int) -> None:
        self.cuisines[self.fc[food]].discard((-self.fr[food], food))
        self.fr[food] = newRating
        self.cuisines[self.fc[food]].add((-self.fr[food], food))
        
    def highestRated(self, cuisine: str) -> str:
        return self.cuisines[cuisine][0][1]
        

# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)