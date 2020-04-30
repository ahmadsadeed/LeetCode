class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # sliding window method, could be optimized more
        # "abcabcbb", "bbbbb, "pwwkew", "abba"
        sub = ''
        longest = 0
        for ch in s:
            if ch in sub:
                sub = sub[sub.find(ch)+1:] + ch
                longest = max(longest, len(sub))
            else:
                sub += ch
                longest = max(longest, len(sub))

    return longest


