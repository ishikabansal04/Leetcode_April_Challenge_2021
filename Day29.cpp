class Solution {
public:
    int first = -1, last = -1;
    void helper1(int left, int right, int target, vector<int>&nums){
        while(left<=right){
            int mid = (left + (right-left)/2);
            if(nums[mid] == target){
                first = (first == -1)? mid : min(mid, first);
                right = mid-1;
            }
            else if(target < nums[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
    } 
    
    void helper2(int left, int right, int target, vector<int>&nums){
        while(left<=right){
            int mid = (left + (right-left)/2);
            if(nums[mid] == target){
                last = (last == -1)? mid : max(mid, last);
                left = mid+1;
            }
            else if(target >= nums[mid]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
    } 
    vector<int> searchRange(vector<int>& nums, int target) {
        helper1(0, nums.size()-1, target, nums);
        helper2(0, nums.size()-1, target, nums);
        vector<int>result;
        result.push_back(first);
        result.push_back(last);
        return result;
    }
};
