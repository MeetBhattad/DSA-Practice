//Optimal approach is super hard.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int total = m + n;
        int cnt = 0;

        int ind1 = (total-1)/2;
        int ind2 = total/2;

        int i = 0;
        int j = 0;
        
        int el1 = 0;
        int el2 = 0;

        while(i<n && j<m){
            int val;
            if(nums1[i] <= nums2[j]){
                val = nums1[i++];
            }
            else val = nums2[j++];

            if(cnt == ind1) el1 = val;
            if(cnt == ind2) el2 = val;

            cnt++;
        }
        while(i < n){
            int val = nums1[i++];

            if(cnt == ind1) el1 = val;
            if(cnt == ind2) el2 = val;

            cnt++;
        }
        while(j < m){
            int val = nums2[j++];

            if(cnt == ind1) el1 = val;
            if(cnt == ind2) el2 = val;

            cnt++;
        }
        if(total % 2 == 1) return el2;
        return (el1+el2)/2.0;
    }
};
