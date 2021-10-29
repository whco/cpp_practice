#include <string>
#include <vector>

using namespace std;

bool starts_with(string s, string sub, int start) {
    if (s.length() < sub.length() + start) return false;
    if (s.substr(start, sub.length()) == sub) return true;
    return false;
}

int solution(string s) {
    string ans = "";
    string num[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    int pos = 0;
    while (pos < s.length()) {
        if ('0' <= s[pos] && s[pos] <= '9') {
            ans.push_back(s[pos]);
            ++pos;
            continue;
        }
        for (int i = 0; i < 10; ++i) {
            if (starts_with(s, num[i], pos)) {
                ans.push_back(i + '0');
                pos += num[i].length();
                break;
            }
        }
    }

    return stoi(ans);
}
