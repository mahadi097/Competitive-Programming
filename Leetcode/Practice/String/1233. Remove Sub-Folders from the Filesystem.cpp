class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector <string> mainF;

        vector <string> lastSubF;
        for(string f: folder) {
            vector <string> subF;
            string curF;
            for(char c: f) {
                if (c == '/' and !curF.empty()) {
                    subF.push_back(curF);
                    curF.clear();
                } 
                else curF.push_back(c);
            }
            subF.push_back(curF);

            bool isItSub = lastSubF.size() <= subF.size();
            
            for(int i = 0; i < min(lastSubF.size(), subF.size()); i++) {
                if(lastSubF[i] != subF[i]) isItSub = false;
            }

            if(!isItSub or lastSubF.empty()) {
                lastSubF = subF;
                mainF.push_back(f);
            }
        }

        return mainF;
    }
};