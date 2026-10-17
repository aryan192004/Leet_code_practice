class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int multiplier = 1;
        long long ans = 0;
        bool isfirst = true;
        bool signFound = false;

        for (int i = 0; i < n; i++) {
            if (isfirst && s[i] == ' ') {
                continue;
            }

            if (isfirst) {
                if (s[i] == '-') {
                    multiplier = -1;
                    signFound = true;
                    isfirst = false;
                    continue;
                }
                else if (s[i] == '+') {
                    isfirst = false;
                    continue;
                }
                else if (!isdigit(s[i])) {
                    break;
                }

                isfirst = false;
            }

            if (!isdigit(s[i])) {
                break;
            }

            int digit = s[i] - '0';
            ans = ans * 10 + digit;

            if (multiplier == 1 && ans > INT_MAX) {
                return INT_MAX;
            }
            if (multiplier == -1 && -ans < INT_MIN) {
                return INT_MIN;
            }
        }

        return (int)(ans * multiplier);
    }
};