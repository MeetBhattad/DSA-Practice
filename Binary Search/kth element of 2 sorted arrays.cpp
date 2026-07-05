class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int m = a.size();
        int n = b.size();
        int i = 0;
        int j = 0;
        while(i < m && j < n){
            int val;
            if(a[i] <= b[j]){
                val = a[i++];
                k--;
                if(k == 0) return val;
            }
            else{
                val = b[j++];
                k--;
                if(k == 0) return val;
            }
        }
        while(i < m){
            int val = a[i++];
            k--;
            if(k == 0) return val;
        }
        while(j < n){
            int val = b[j++];
            k--;
            if(k == 0) return val;
        }
        return -1;
    }
};
