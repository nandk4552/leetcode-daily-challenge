class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        // to store freq in map
        unordered_map<int,int> mp;
        int sum = 0;
        mp[0]++; // marking first element freq in map
        // adding each element to the sum
        for(auto x: nums) {
            sum += x;
            if(mp[(sum%k+k)%k] > 0) {
                cnt+=mp[(sum%k+k)%k];
            }
            mp[(sum%k+k)%k]++;
        }
        return cnt;
    }
};