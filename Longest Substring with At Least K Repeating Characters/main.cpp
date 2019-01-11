#include <string>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = 0;
        map<char, int> map;

        if(s.size() == 0 || k > s.size())
            return 0;
        if(k == 0)
            return (int) s.size();

        for (char c : s)
            map[c]++;


        while (len < s.size() && map[s[len]] >=k)
            len++;

        if (len == s.size())
            return len;

        int s1 = longestSubstring(s.substr(0, len), k);

        while (len < s.size() && map[s[len]] < k)
            len++;

        int s2 = longestSubstring(s.substr(len), k);

        return max(s1, s2);
    }
};

int main() {

    string s = "aaabb";
    Solution sol;
    int i = sol.longestSubstring(s, 3);
    cout << "Length is: " << i << endl;


    return 0;
}
