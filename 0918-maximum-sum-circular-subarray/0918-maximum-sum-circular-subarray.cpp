class Solution {
private:
    int minsumSubarray(vector<int> &nums) {
        int minsum=INT_MAX;
        int currentsum=0;
        
        for(int i=0; i<nums.size(); i++) {
            currentsum+=nums[i];
            minsum=min(minsum,currentsum);
            
            if(currentsum>0){
                currentsum=0;
            }
        }
        return minsum;
    }
    int maxsumSubarray(vector<int> &nums) {
        int maxsum=INT_MIN;
        int currentsum=0;
        
        for(int i=0; i<nums.size(); i++) {
            currentsum+=nums[i];
            maxsum=max(maxsum,currentsum);
            
            if(currentsum<0){
                currentsum=0;
            }
        }
        return maxsum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int x=1;
        int ans = INT_MIN;
        for(int i=0; i<nums.size();i++) {
            if(nums[i]>=0) {
                x=0;
                break;
            }
            ans=max(ans,nums[i]);
        }
        if(x) return ans;
        
        // case1
        int a=maxsumSubarray(nums);
        //case22
        int totalSum=0;
        for(int i=0; i<nums.size(); i++) {
            totalSum+=nums[i];
        }
        
        int b=totalSum-minsumSubarray(nums);
        
        return max(a,b);
    }
};