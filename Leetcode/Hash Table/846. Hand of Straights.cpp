class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        if(n%groupSize) return false;
        
        unordered_map<int, int> f;
        for(auto v: hand) f[v]++;

        sort(hand.begin(), hand.end());

        for(auto v: hand) {
            if(!f[v]) continue;

            for(int x = v; x < v+groupSize; x++) {
                if(!f[x]) return false;
                f[x]--;
            }            
        }

        return true;
    }
};