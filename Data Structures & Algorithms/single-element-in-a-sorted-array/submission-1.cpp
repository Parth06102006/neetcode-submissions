class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // BIT MANIPULATION
        /* int num = 0;
        for(int i=0;i<nums.size();i++){
            num ^= nums[i];
        }

        return num; */

        if(nums.size() == 1) return nums[0];

        if(nums[0] != nums[1]) return nums[0];

        int end = nums.size()-1;

        if(nums[end] != nums[end-1]) return nums[end];

        int low = 1;
        int high = end-1;

        while(low<=high){

            int mid = low + ( (high-low) >> 1 );


            if 
            (
                nums[mid-1] != nums[mid] 
                    and 
                nums[mid+1] != nums[mid]
            ) return nums[mid];

            if ( (mid%2 == 0 and nums[mid] == nums[mid+1])) low=mid+1;
            else if( mid%2 == 1 and nums[mid] == nums[mid-1]) low=mid+1;
            else high=mid-1;

        }

        return -1;
    }
};