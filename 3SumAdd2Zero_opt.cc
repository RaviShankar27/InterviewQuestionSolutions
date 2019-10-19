class Solution {
public:
    struct vec_hash {
        template <class T1>
        std::size_t operator () (const std::vector<T1> &p) const {
            auto h1 = std::hash<T1>{}(p[0]);
            auto h2 = std::hash<T1>{}(p[1]);
            auto h3 = std::hash<T1>{}(p[2]);
            return h1 ^ h2 ^ h3;
        }
    };
    
    class comp {
        public :
         bool operator()  (const vector<int>& lhs, const vector<int>& rhs) const {
             if (lhs.size() != rhs.size())
                 false;
             for (int index = 0; index < lhs.size(); index++) {
                 if (lhs[index] == rhs[index])
                     continue;
                 else
                     return false;
             }
             return true;
         }
    };
    
    ///counter :: array index can be used here for counting and multimap can be used...
    vector<vector<int>> twoSum(vector<int>& nums, int index, unordered_multimap<int,int>& counter) {
        vector<vector<int>> result;
        int first_elem = nums[index];
        int target = -nums[index];// sum of rest two
        
        for (int i = index+1; i < nums.size() -1; ++i) {
            int sec_elem = nums[i]; 
            std::pair<unordered_multimap<int,int>::iterator, unordered_multimap<int,int>::iterator>  eq_rg_found = counter.equal_range(target - sec_elem);
            for (eq_rg_found.first; eq_rg_found.first != eq_rg_found.second; eq_rg_found.first++) {
                //see index of our requirement is greater that current(i)
                if (eq_rg_found.first->second > i) {
                    vector<int> loc_vec;
                    loc_vec.push_back(first_elem);
                    loc_vec.push_back(sec_elem);
                    loc_vec.push_back(eq_rg_found.first->first);
                    result.push_back(loc_vec);
                }
            }
        }
        return result;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> results;
        
        if (nums.size() < 3) return results;
        if (nums.size() == 3 && nums[0] == 0 && nums[0] == nums[1] && nums[1] == nums[2]) {
            results.push_back(nums);
            return results;
        }
        
        sort(nums.begin(), nums.end());
        
        if ((nums.size() > 3) && (nums[0] == nums[nums.size() -1])) {
            vector<int> loc_vec;
            loc_vec.push_back(nums[0]);
            loc_vec.push_back(nums[0]);
            loc_vec.push_back(nums[0]);
            results.push_back(loc_vec);
            return results;
        }
        
        unordered_set<vector<int>, vec_hash, comp> results_set;
        unordered_multimap<int,int> counter;
        for (int i = 0; i < nums.size(); ++i) {
            counter.emplace(std::pair<int, int>(nums[i], i));
        }
        
        for (int index = 0; index < nums.size() -2; ++index) {
            if (index != 0 && nums[index-1] == nums[index]) continue;
            vector<vector<int>> temp = twoSum(nums, index, counter);
            if (temp.size()) {
                for (auto  elem : temp) {
                   results_set.insert(elem);
                }
            }
        }
        move(results_set.begin(),results_set.end(), back_inserter(results));
        
        return results;
    }
};