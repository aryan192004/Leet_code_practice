class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        map<int,int>mp;
        mp[5]=0;
        mp[10]=0;
        mp[20]=0;
        for(int i = 0;i<n;i++){
            mp[bills[i]]++;
            if(bills[i]==10){
                if(mp[5]>0){
                    mp[5]--;
                    continue;
                }else{
                    return false;
                }
            }
            if(bills[i]==20){
                if(mp[10]>0 && mp[5]>0){
                    mp[10]--;
                    mp[5]--;
                    continue;
                }
                else if(mp[10]==0 && mp[5]>=3){
                    mp[5]-=3;
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};