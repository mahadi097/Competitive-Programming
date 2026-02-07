class Solution {
private: 
    void addOne(string &s) {
        int carry = 1;
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == '0') {
                s[i] = '1';
                carry = 0;
                break;
            }
            s[i] = '0';
        }

        if(carry) s.insert(s.begin(), '1');
    }

public:
    int numSteps(string s) {
        int steps = 0;
        while(s.size() != 1) {
            steps++;
            
            int n = s.size();
            
            if(s[n-1] == '0') s.pop_back();
            else addOne(s);
        }

        return steps;
    }
};