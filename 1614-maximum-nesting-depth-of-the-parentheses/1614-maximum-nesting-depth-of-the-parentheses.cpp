class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int count = 0;
        int maxc= INT_MIN;
        for(int i = 0;i<n;i++){
            if(s[i]=='('){
                count++;
               
            }
            if(s[i]==')'){
                count--;
            }
             maxc=max(maxc,count);
        }
        return maxc;
    }
};