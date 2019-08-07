class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int ,int > hash;
        vector<int> s(2,0);
        for(int i=0;i<nums.size();i++)
        {
            if(hash.find(target-nums[i])!=hash.end())
            {
                s[1]=i;
                s[0]=hash[target-nums[i]];
                return s;
            }
            hash[nums[i]]=i;
        }
        return s;

    }
};
