class Solution {
public:
    string removeSubstring(string s, int k) {
        string st;
        int n = s.size();
        
        for (char c : s) {
            st.push_back(c);
            
            if (st.size() >= 2 * k) {
                bool valid = true;
                
                for (int i = 0; i < k; i++) {
                    if (st[st.size() - 2 * k + i] != '(') {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    for (int i = k; i < 2 * k; i++) {
                        if (st[st.size() - 2 * k + i] != ')') {
                            valid = false;
                            break;
                        }
                    }
                }
                
                if (valid) {
                    st.erase(st.end() - 2 * k, st.end());
                }
            }
        }
        
        return st;
    }
};
