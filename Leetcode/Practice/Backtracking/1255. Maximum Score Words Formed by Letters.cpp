class Solution {
private:
    int intV(char c) {
        return c - 'a';
    }

    int solve(int in, vector<string>& words, vector<int> &f, vector<int>& score) {
        if(in == words.size()) return 0;

        int scoreWord = 0, r2 = 0, r1 = solve(in+1, words, f, score);
        
        for(auto letter: words[in]) {
            int v = intV(letter);
            f[v]--;
            scoreWord += score[v];
            if(f[v] < 0) r2 = -1; 
        }

        if(r2 == 0) r2 = scoreWord + solve(in+1, words, f, score);

        // revert frequency changes
        for(auto letter: words[in]) {
            int v = intV(letter);
            f[v]++;
        }

        return  max(r1, r2);
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> f(26, 0);
        
        for(auto letter: letters) f[intV(letter)]++;
        
        return solve(0, words, f, score);
    }
};