class Solution {
public:
   
    string shortestPalindrome(string s) {
      
        if (s.size() <= 1) {
            return s;
        }
        
        int string_size = s.size();
        string reverse_s(s.rbegin(), s.rend());
        string temp = s + "#" + reverse_s;
        int* partial_match_table = new int[temp.size()]();
        for (int i = 1; i < temp.size(); ++i) {
            int j = partial_match_table[i-1];
            
            while (j > 0 && temp[i] != temp[j])
                j = partial_match_table[j-1];
            
            if (temp[i] == temp[j]) partial_match_table[i] = j+1;
        }
        
        return reverse_s.substr(0, s.size() - partial_match_table[temp.size()-1]) + s;
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
    //string line;
    //while (getline(cin, line)) {
    //    string s = stringToString(line);
        
        string ret = Solution().shortestPalindrome(string("abab"));

        string out = (ret);
        cout << out << endl;
    //}
    return 0;
}