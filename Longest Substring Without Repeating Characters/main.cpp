int x = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;

}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t lenBackup = 0;
        size_t len = 0;
        string sub = "";
        for (char c : s) {
            size_t pos = sub.find(c);
            size_t sLen = sub.length();
            if (pos != string::npos) {
                if (len >= lenBackup) {
                    lenBackup = len;
                    len = (sLen - (pos+1)) + 1;
                } else {
                    len = (sLen - (pos+1)) + 1;
                }
                sub = sub.substr(pos+1, sLen) + c;

            } else {
                len++;
                sub += c;
            }

        }
        int length = (len >= lenBackup) ? len : lenBackup;
        return length;
    }
};


/*
int main(){
    string s = "pwwkew";
    Solution sol;
    int i = sol.lengthOfLongestSubstring(s);
    cout << "Length is: " << i << endl;



    return 0;
}*/

