#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        int max_len = 0;
        int counter = 0;
        unordered_map<int, int> valIndexMap;
        int local_start_index = 0;
        for (auto iter = s.begin(); iter != s.end(); ++iter, ++counter) {
            pair<unordered_map<int,int>::iterator, bool> result = valIndexMap.insert(pair<int, int>(*iter, counter));
            if (!result.second) {
                if (max_len < valIndexMap.size()) {
                    max_len = valIndexMap.size();
                }
                pair<int,int> tmp_val = *(result.first);
                const int matched_index_in_hash = valIndexMap[tmp_val.first];
                //now erase values from hash range[local_start_index, matched_index_in_hash]
                for (auto int_var = local_start_index; int_var <= matched_index_in_hash; ++int_var) {
                    valIndexMap.erase(s[int_var]);
                }
                
                valIndexMap.insert(pair<int, int>(*iter, counter));
                
                local_start_index = matched_index_in_hash +1;
                //this will be used as start for next substring
            }
        }
        if (max_len < valIndexMap.size()) {
             max_len = valIndexMap.size();
        }
        return max_len;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    //while (getline(cin, line)) {
        //string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring("dvdf");

        string out = to_string(ret);
        cout << out << endl;
    //}
    return 0;
}