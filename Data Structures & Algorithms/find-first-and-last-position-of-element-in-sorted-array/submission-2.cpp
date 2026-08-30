class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int left = 0 , right = nums.size()-1;

        int firstOccurence = -1;
        int lastOccurence = -1;

        while(left <= right ){
            
            int mid = left + ( (right-left) >> 1);

            if(nums[mid] == target){
                
                if(firstOccurence == -1) firstOccurence = mid;
                if(lastOccurence == -1) lastOccurence = mid;

                firstOccurence = min(firstOccurence,mid);

                lastOccurence = max(lastOccurence,mid);
            }

            if(target > nums[mid]) left = mid+1;
            else right=mid-1;
        }

        while(lastOccurence+1 < nums.size() and nums[lastOccurence+1] == target)lastOccurence++;

        return {firstOccurence,lastOccurence};

    }
};