class Solution {
private:
    int lnR, lnK; // length of ring, key
    vector<vector<vector<int>>> dp; 

    // current state of index of the ring, index of the key currently matching, direction the ring is currently moving
    int solve(int inR, int inK, int dir, string &ring, string &key) { 
        if(inK == lnK) return 0;
        int &res = dp[inR][inK][dir];
        if(res != -1) return res;

        if(ring[inR] == key[inK]) { // if the characters are equal we go both directions to match the next character of the key 
            int r1 = solve(inR, inK+1, 0, ring, key); // direction = 0 means clockwise
            int r2 = solve(inR, inK+1, 1, ring, key); // // direction = 1 means anti clockwise

            res = min(r1, r2);
        }    
        else { // if not equal we go to the next step of the current direction
            int nextInR = (dir == 0) ? inR + 1 : inR - 1;
            if(nextInR == lnR) nextInR = 0;
            if(nextInR == -1) nextInR = lnR - 1;

            res = 1 + solve(nextInR, inK, dir, ring, key);
        }

        return res;
    }

public:
    int findRotateSteps(string ring, string key) {
        lnR = ring.size(), lnK = key.size();
        dp.resize(lnR, vector<vector<int>>(lnK, vector<int>(2, -1)));

        return min(solve(0, 0, 0, ring, key), solve(0, 0, 1, ring, key)) + lnK;
    }
};