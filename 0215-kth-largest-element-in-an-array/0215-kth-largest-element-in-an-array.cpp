class Solution {
public:
void heapify(vector<int>& nums,int n,int i){
    int min = i;
    int left = i*2+1;
    int right = i*2+2;
    if(left<n && nums[min]>nums[left]){
        min = left;
    
    }
    if(right < n && nums[min]>nums[right]){
        min = right;
    
    }
    if(min!=i){
        swap(nums[min],nums[i]);
        heapify(nums,n,min);
    }

}
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = (n/2)-1; i >=0;i--){
            heapify(nums,n,i);
        }
        for(int i = n-1; i >0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
        return nums[k-1];
       
    }
};