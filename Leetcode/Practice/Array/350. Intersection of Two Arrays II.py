class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        f1 = Counter(nums1) #can also calculate frequency using this method
        f2 = Counter(nums2)
        
        intersection = []
        for key in f1:
            count = min(f1[key], f2[key])
            while count > 0:
                intersection.append(key)
                count -= 1
        
        return intersection
      