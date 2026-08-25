template <typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;

        for(auto num:nums){
            mpp[num]++;
        }

        MinHeap<pair<int,int>> minHeap;

        for(auto it:mpp){
            minHeap.push({it.second,it.first});

            if(minHeap.size() > k) minHeap.pop();
        }

        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;

        
    }
};
