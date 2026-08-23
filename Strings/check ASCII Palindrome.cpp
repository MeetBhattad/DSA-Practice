class Solution {
public:
    bool isPalindromic(string s) {

        string binary = "";

        for(char c : s){
            int x = (int)c;

            for(int i = 7; i >=0; i--){
                binary  += ((x >> i) & 1) + '0';
            }
        }

        int i = 0;
        int j = binary.size() - 1;

        while( i < j){
            if(binary[i] != binary[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
};
