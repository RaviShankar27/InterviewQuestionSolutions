
    class comp {
        public :
         bool operator()  (const vector<int>& lhs, const vector<int>& rhs) const {
             if (lhs.size() != rhs.size())
                 false;
             for (int index = 0; index < lhs.size(); index++) {
                 if (lhs[index] < rhs[index])
                     return true;
                 else if (lhs[index] == rhs[index])
                     continue;
                 else
                     return false;
             }
             return false;
         }
    };
    
    vector<vector<int>> twoSum(vector<int>& nums, int index) {
        vector<vector<int>> result;
        int first_elem = nums[index];
        int target = -nums[index];// sum of rest two
        
        unordered_map<int,int> counter;
       
        for (int i = index + 1; i < nums.size(); ++i) {
            if (counter.find(nums[i]) != counter.end())
                counter[nums[i]]++;
            else
                counter.emplace(std::pair<int, int>(nums[i], 1));
        }
        
        for (int i = index+1; i < nums.size() -1; ++i) {
            int sec_elem = nums[i]; 
                counter[nums[i]]--;
                if (counter[nums[i]] == 0)
                    counter.erase(sec_elem);
  
            unordered_map<int,int>::iterator found = counter.find(target - sec_elem);
            if (found != counter.end()) {
                vector<int> loc_vec;
                loc_vec.push_back(first_elem);
                loc_vec.push_back(sec_elem);
                loc_vec.push_back(found->first);
                result.push_back(loc_vec);
                counter[found->first]--;
                if (counter[found->first] == 0)
                    counter.erase(found);
                
                continue;
            }
        }
        return result;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        set<vector<int>, comp> results_set;
        if (nums.size() < 3) return results;
        if (nums.size() == 3 && nums[0] == 0 && nums[0] == nums[1] && nums[1] == nums[2]) {
            results.push_back(nums);
            return results;
        }
            
        for (int index = 0; index < nums.size() -2; ++index) {
            if (index != 0 && nums[index-1] == nums[index]) continue;
            vector<vector<int>> temp = twoSum(nums, index);
            if (temp.size()) {
                for (auto  elem : temp) {
                   results_set.insert(elem);
                }
            }
        }
        move(results_set.begin(),results_set.end(), back_inserter(results));
        
        return results;
    }


int main()
{
	std::vector<int> array = {-1, 0,1,2,-1,-4};
	vector<vector<int>> results = threeSum(array);
	return 0;
}