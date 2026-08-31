class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *min_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        int ans = high;

        while(low <= high){
            int mid = low + ( (high-low) >> 1 );

            if(check(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }

    bool check(vector<int> weights,int days,int leastWeightCapacity){
        int total_day = 0;
        int total_weight = 0;

        for(auto weight : weights){
            if(total_weight + weight <= leastWeightCapacity){
                total_weight += weight;
            }else{
                total_day ++;

                if(weight <= leastWeightCapacity) total_weight = weight;
                else return false;
            }
        }

        if(total_weight > leastWeightCapacity) return false;
        else total_day++;

        return (total_day <= days);
    }
};