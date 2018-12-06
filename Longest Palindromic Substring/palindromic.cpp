static const auto _fast=[](){ios::sync_with_stdio(0);cin.tie(0);return nullptr;}();
class Solution {
public:
    string longestPalindrome(string s) {
        int sLen = s.length();

        int startIndex = 0, endIndex = 0;
        for (int i = 0; i < s.length(); i++) {
            int left = i, right = i;
            while (left >= 0 && right < sLen && s[left] == s[right]) {
                left--;
                right++;
            }
            int left2 = i, right2 = i + 1;
            while (left2 >= 0 && right2 < sLen && s[left2] == s[right2]) {
                left2--;
                right2++;
            }

            int subStrSize = right - left - 1;
            int subStrSize2 = right2 - left2 - 1;
            int bigger = ((subStrSize>subStrSize2) ? subStrSize : subStrSize2);
            if (bigger > (endIndex - startIndex)) {
                startIndex = i - (bigger - 1)/2;
                endIndex = i + bigger/2 ;
            }
        }
        
        return s.substr(startIndex, endIndex - startIndex + 1);
    }
};

/*


int main()
{
    Solution sol;
    string s = "abbc";
    string str = sol.longestPalindrome(s);

    cout << "The string is: " << str << endl;
    cout << "\n";



    cout << endl;
    return 0;
}
*/


