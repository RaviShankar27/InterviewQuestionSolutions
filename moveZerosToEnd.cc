class Solution {
public:
    
    int countZerosInArray(vector<int>& array) {
        int count  =0 ;
        for (auto elem: array) {
            if (elem==0) count++;
        }
        return count;
    }
    
    void moveNonZeroes(vector<int>& nums) {
        int nonZeroIndex = 0;
        int index = 0;
        for (; index < nums.size(); ++index) {
            if (nums[index] != 0) {
                nums[nonZeroIndex] = nums[index];
                nonZeroIndex++;
            }
       }
    }
    
    void fillZeroes(vector<int>& nums, int zeros){
        for (int index = nums.size()-zeros; index < nums.size(); ++index){
            nums[index] = 0;
        }
    }
    
    void moveZeroes(vector<int>& nums) {
        int countZeros = countZerosInArray(nums);
        moveNonZeroes(nums);
        fillZeroes(nums, countZeros);
        for(auto elem: nums) {
            cout << elem << " ";
        }
        cout << endl;
    }
};