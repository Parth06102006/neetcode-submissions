class Solution {
public:
    int findMin(vector<int> &nums) {
        int minNumber = nums[0];

        int left = 0 , right = nums.size()-1;

        while(left<=right){
            int mid = left + ( (right-left) >> 1) ;

            if(nums[mid] < minNumber){
                if(mid == 0 || nums[mid-1] >= minNumber) {
                    minNumber = nums[mid];
                    break;
                }
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return minNumber;
    }
};
