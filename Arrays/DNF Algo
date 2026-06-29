Approach-
We will be using 3 pointers low mid and high. 
0 to low-1 would be there to store 0, low to mid - 1 for storing 1's, mid to high would be for the unosrted array and high to n would be for 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low] , nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid] == 1){
                mid++;
            }

            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
