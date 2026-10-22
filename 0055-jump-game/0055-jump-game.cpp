class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return true;
        }
        if(nums[0]==0){
            return false;
        }
        for(int i = 0;i<n;i++){

            if(nums[i]==0){
                int flag = false;
                for(int j = 0;j<i;j++){
                    if(j+nums[j]>i || j+nums[j]==n-1){
                        flag = true;
                        break;
                    }
                }
                if(flag == false){
                    return false;
                }

            }
        }
        return true;
    }
};