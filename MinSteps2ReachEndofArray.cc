//find-the-minimum-number-of-moves-to-reach-end-of-the-array

#include <iostream>
#include <unordered_map>//it will have key vs index as pair
#include <vector>
using namespace std;

int minStepsToReachEnd(vector<int>& nums)
{
    unordered_multimap<int, int> hash_keys;
    
    int N = nums.size();
    if (N <= 1) return 0;
    std::vector<int> Table_minsteps(nums.size());
    Table_minsteps.push_back(0);
    Table_minsteps.push_back(1);
    
    for (int index = 0; index < N; index++) {
        int start = nums[index];
        
        if (index == 0 || index == 1) {
            hash_keys.emplace(std::pair<int,int>(nums[index], index));
            continue;
        }
        
        auto equal_ranges = hash_keys.equal_range(start);
        int min_in_range = 9999999;
        bool found = false;
        for (auto it = equal_ranges.first; it != equal_ranges.second; ++it) {
            found = true;
            if (Table_minsteps[it->second] < min_in_range)
                min_in_range = Table_minsteps[it->second];
        }
        
        if (!found) {
            Table_minsteps[index] = Table_minsteps[index-1] + 1;
        }
        else {
            Table_minsteps[index] = min_in_range + 1;
        }
    }
    return Table_minsteps[N-1];
}

int main() {
	std::vector<int> inputs = {1,2,3,4,1,5};
	int result = minStepsToReachEnd(inputs);
	cout << result ;
	return 0;
}