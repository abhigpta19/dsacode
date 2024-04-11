class Solution {
public:
       

    int lengthOfLIS(vector<int>& nums) 
    {
        int ans=1;
        int n=nums.size();
       vector<int> vec;
       int size=1;
       vec.push_back(nums[0]);
       for(int i=1;i<n;i++)
       {
           int x=lower_bound(vec.begin(),vec.end(),nums[i])-vec.begin();
           if(x==size)
           {
               vec.push_back(nums[i]);
               size++;
               ans=max(ans,size);
           }
           else
           {
               vec[x]=nums[i];
           }
       }
       return ans;
    }
};