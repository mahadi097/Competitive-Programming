/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int midPos, st = 0, en = n-1;
        while(st <= en) {
            int mid1 = st + (en - st) / 3;
            int mid2 = en - (en - st) / 3;

            int v1 = mountainArr.get(mid1), v2 = mountainArr.get(mid2);

            if(v1 < v2) midPos = mid2, st = mid1 + 1;
            else midPos = mid1, en = mid2 - 1;
        }

        st = 0, en = midPos;
        while(st <= en) {
            int mid = (st + en) / 2;
            int v = mountainArr.get(mid);

            if(v == target) return mid;

            if(v < target) st = mid + 1;
            else en = mid - 1;
        }

        st = midPos+1, en = n-1;
        while(st <= en) {
            int mid = (st + en) / 2;
            int v= mountainArr.get(mid);

            if(v == target) return mid;

            if(v < target) en = mid - 1;
            else st = mid + 1;
        }

        return -1;
    }
};
