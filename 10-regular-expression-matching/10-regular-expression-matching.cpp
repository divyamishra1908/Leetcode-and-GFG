class Solution {
public:
    bool isMatch(string s, string p) {
        bool h[21][31] = { 1 };
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                h[i][j] = 
                    (p[j - 1] == '*') ? h[i][j - 2] ||
                    (i > 0) && h[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.') :
                    (i > 0) && h[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
            }
        }
        return h[s.size()][p.size()];
    }
};