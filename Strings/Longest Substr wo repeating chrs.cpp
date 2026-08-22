class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(128, -1); 
        int maxlen = 0;
        int j = 0; 

        for (int i = 0; i < s.length(); i++) {
            
            if (lastSeen[s[i]] != -1 && lastSeen[s[i]] >= j) {
                
                j = lastSeen[s[i]] + 1;
            }
            
            lastSeen[s[i]] = i;
            
            maxlen = max(maxlen, i - j + 1);
        }
        return maxlen;
    }
};   
