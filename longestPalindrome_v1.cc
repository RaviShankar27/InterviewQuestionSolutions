class Solution {
public:
    
    string checkForLongestPalindrome(string& s, int index, string& temp_pal_odd, string& temp_pal_even) {
        // at each index, you can have two types of palindrome. one which will contain odd numbers of characte and other even
        // for even, if at every index only compare right with current, then it will work
        
        int temp = index;
        int incr = 1;

        temp_pal_even.push_back(s[index]);
        //even case    
        bool even_start = true;
        while((even_start || (temp-incr+1) >= 0) && temp+incr < s.size()) {
            if (s[temp-(incr-1)] == s[temp+incr]) {
                if (temp-(incr-1) != index)
                    temp_pal_even.insert(temp_pal_even.begin(), s[temp-(incr-1)]);
                temp_pal_even += s[temp+incr];
                even_start = false;
            }
            else {
                break;
            }
            incr++;
        }
        //odd case
        incr = 1;
        bool if_all_are_samechar = false;
        
        temp_pal_odd.push_back(s[index]);
        while(temp-incr >= 0 && temp+incr < s.size()) {
            if (s[temp -incr] == s[temp+incr]) {//odd case
                temp_pal_odd.insert(temp_pal_odd.begin(), s[temp-incr]);
                temp_pal_odd += s[temp+incr];
                if_all_are_samechar = true;
            }
            else {
                if_all_are_samechar = false;
                break;
            }
            incr++;
            
        }
        ///when all chars are same in string
        if (index == (s.size()/2 -1) && if_all_are_samechar && s[index] == s[index+1] && temp+incr == s.size()-1 && s[s.size()-1] == s[s.size()-2]) {
                temp_pal_odd += s[temp+incr];
        }
        
        return temp_pal_even.size() > temp_pal_odd.size() ? temp_pal_even : temp_pal_odd;
    }
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        if (s.size() == 2 && s[0] == s[1])
            return string("")+s[0]+s[0];
        
        string longestPalindrome;
        string temp_pal_odd, temp_pal_even;
        temp_pal_odd.reserve(1000);
        temp_pal_odd.reserve(1000);
        for (int index = 0; index <= s.size(); ++index) {
            string temp_res = checkForLongestPalindrome(s, index, temp_pal_odd, temp_pal_even);
            temp_pal_odd.clear();
            temp_pal_even.clear();
            if (longestPalindrome.size() < temp_res.size()) {
                longestPalindrome = temp_res;
            }
        }
        return longestPalindrome;
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
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}