class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string fancy = "";

        for(int i = 0; i < n; i++) {
            int j = i, c = 1;
            
            while(j < n and s[j] == s[i]) {
                j++;
                if(c <= 2) fancy += s[i];
                c++;
            }
            
            i = j-1;
        }

        return fancy;
    }
};