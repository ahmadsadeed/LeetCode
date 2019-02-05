class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> map;
        for (int x = 0; x < s.size(); x++) {
            map[s[x]]++;
            map[t[x]]--;
        }
        for (auto element : map) {
            if (element.second > 0) return false;
        }
        return true;
    }
};
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s == t;
//     }
// };
// Input: s = "saddeed", t = "ddatees"


// int main() {

//     return 0;
// }
