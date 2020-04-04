class Solution {
public:
    bool isHappy(int n) {
        if (n==1) return true;
        std::set<int> intermediate_sums;
        while (n != 1) {
            intermediate_sums.insert(n);
            
            int temp_sum = 0;
            while(n/10){
                temp_sum += (n%10)*(n%10);
                n = n/10;
            }
            temp_sum += n*n;
            if (intermediate_sums.find(temp_sum) != intermediate_sums.end()) return false;
            n = temp_sum;
        }
        return true;
    }
};

class Solution {
public:
    int squareSum(int n) {
        int sum = 0;
        while (n != 0) {
            int last_number = n % 10;
            n = n / 10;
            sum += last_number * last_number;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        if (n == 1)
            return true;
        int slow = n;
        int fast = squareSum(n);
        while (slow != fast) {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }
        if (slow == 1) {
            return true;
        } else {
            return false;
        }
    }
};