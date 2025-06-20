class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // To handle subarrays starting from index 0

        int count = 0;
        int prefixSum = 0;

        for (int num : nums) {
            prefixSum += num;

            if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
                count += prefixCount[prefixSum - k];
            }

            prefixCount[prefixSum]++;
        }

        return count;
    }
};
