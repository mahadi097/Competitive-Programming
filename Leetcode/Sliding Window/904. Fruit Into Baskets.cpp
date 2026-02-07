class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, f0 = -1, f1 = -1;
        vector<queue<int>> b(2);

        auto emptyBasket = [&](int in) {
            int lastPos = -1;
            while(!b[in].empty()) {
                lastPos = b[in].front();
                b[in].pop();
            }
            return lastPos;
        };

        auto removeTillPos = [&](int in, int pos) {
            while(!b[in].empty() and b[in].front() < pos) b[in].pop();
        };

        for(int i = 0; i < fruits.size(); i++) {
            int f = fruits[i];

            if(f0 == -1 or f == f0) {
                f0 = f, b[0].push(i);
            }
            else if(f1 == -1 or f == f1) {
                f1 = f, b[1].push(i);
            }
            else {
                if(fruits[i-1] == f0) {
                    int lastPos = emptyBasket(1);
                    removeTillPos(0, lastPos);
                    f1 = f, b[1].push(i);
                }
                else {
                    int lastPos = emptyBasket(0);
                    removeTillPos(1, lastPos);
                    f0 = f, b[0].push(i);
                }
            }

            int curSize = b[0].size()+b[1].size();
            ans = max(ans, curSize);
        }

        return ans;
    }
};