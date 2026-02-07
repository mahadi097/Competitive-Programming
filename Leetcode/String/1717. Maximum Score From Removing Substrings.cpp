class Solution {
public:
    int mxGain = 0;

    int maximumGain(string s, int x, int y) {
        if(x >= y) {
            s = operation(s, 'a', 'b', x);
            s = operation(s, 'b', 'a', y);
        }
        else {
            s = operation(s, 'b', 'a', y);
            s = operation(s, 'a', 'b', x);
        }

        return mxGain;
    }

    string operation(string &s, char c1, char c2, int gain) {
        string newS;

        for(char c: s) {
            if(!newS.empty() and newS.back() == c1 and c == c2) {
                newS.pop_back();
                mxGain += gain;
            }
            else newS.push_back(c);
        }

        return newS;
    }
};