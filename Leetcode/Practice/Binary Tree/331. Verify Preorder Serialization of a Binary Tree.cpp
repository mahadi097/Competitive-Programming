class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector <int> v;
        bool side[10005] = {0};

        for(int i = 0; i < preorder.size(); i++) {
            auto c = preorder[i];
            if(c >= '0' and c <= '9') {
                while(i < preorder.size() and preorder[i] != ',') i++;
                i--;
                v.push_back(1);
            }
            else if(c == '#') v.push_back(-1);
        }

        stack <int> st;
        st.push(0);

        if(v[0] == -1) return v.size() == 1;

        for(int i = 1; i < v.size(); i++) {
            if(st.empty()) return 0;

            int pos = st.top();

            if(!side[pos]) side[pos] = 1;
            else st.pop();

            if(v[i] != -1) st.push(i);
        }

        return st.empty();
    }
};
