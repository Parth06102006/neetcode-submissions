class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        int min_time = high;

        while(low<=high){
            int mid = low + ( (high-low) >> 1);
            if(mid == 0){
                low=1;
                continue;
            }

            bool ans = check(mid,h,piles);

            if(ans){
                min_time = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }


        }

        return min_time;

    }

    bool check(int speed,int h,vector<int> piles){
        
        int total_hours = 0;

        for(auto pile:piles){
            total_hours += ( pile/speed );
            if(pile % speed != 0) total_hours += 1;
        }

        return total_hours <= h;

    }
};
