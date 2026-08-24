class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        int n = nums.size();

        while(j<n){

            while( ((i<n) && (i == j)) && (nums[i] != val) ){
                i++;
                j++;
            }

            if(nums[j] != val){
                swap(nums[j],nums[i]);
                i++;
                j++;
            }else{
                j++;
            }
        }

        return (i==n+1) ? n : i;
    }
};