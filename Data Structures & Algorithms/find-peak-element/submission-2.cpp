class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int nums_size = nums.size();

        int left = 0;
        int right = nums_size-1;

        while(left < right){

            int mid = left + ((right-left)>>1);

            if(nums[mid+1] < nums[mid]) right=mid;
            else left=mid+1;


        }


        return left;

    }
};