class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans;
        vector<int> take(n, 0);
        int start = 0;
        int count = 0;

        for (int end = 0; end < n; end++) {
            if (s[end] == '(') {
                if (count == 0) {
                    take[end] = 1;  // Outer opening parenthesis
                    start = end;
                }
                count++;
            }
            else {
                count--;

                if (count == 0) {
                    take[end] = 1;  // Outer closing parenthesis
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (take[i] == 0) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};