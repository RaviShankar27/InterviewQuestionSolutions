class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> counter;
        
        if (nums.size()%2 != 0) {
            for (auto& val :nums) {
                counter[val]++;
            }
            for(auto& val : counter) {
                if (val.second == 1)
                    return val.first;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if (nums.size()%2 != 0) {
            int xor_it = 0;
            for (auto& val :nums) {
                xor_it ^= val;
            }
            if (xor_it)
                return xor_it;
        }
        return 0;
    }
};