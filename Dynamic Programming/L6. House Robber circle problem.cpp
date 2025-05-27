class Solution {
public:


    int maxAdjustment(vector<int>& a) { 
        
    int prev = a[0],prev2=0,curi,pick,nonPick;
    
    for (int i = 1; i < a.size(); i++) {

        pick = a[i];
        if (i > 1)
            pick += prev2;
        nonPick = prev;
        
         curi = max(pick, nonPick);

        prev2=prev;
        prev=curi;
    }
    return prev;

    }

    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;

        int n = nums.size();
        if(n ==1)
        return nums[0];

        for(int i =0;i<n;i++)
        {
            if(i!=0 )
            temp1.push_back(nums[i]);
            if(i!=n-1)
            {
                temp2.push_back(nums[i]);
            }
        }

        return max(maxAdjustment(temp1),maxAdjustment(temp2));
    }
};