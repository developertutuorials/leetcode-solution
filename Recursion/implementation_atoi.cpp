// Recursive Implementation of atoi()
class Solution {
public:
    int helper(string &s, int i, long long ans, int sign) {
        if (i >= s.size() || !isdigit(s[i])) return sign * ans;

        ans = ans * 10 + (s[i] - '0');

        if (sign == 1 && ans >= INT_MAX) return INT_MAX;
        if (sign == -1 && -ans <= INT_MIN) return INT_MIN;

        return helper(s, i + 1, ans, sign);
    }

    int myAtoi(string s) {
        int i = 0, n = s.size();

        while (i < n && s[i] == ' ') i++;

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        return helper(s, i, 0, sign);
    }
};