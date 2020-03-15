
#include<iostream>
#include<vector>
using namespace std;


int findRightIndex(std::vector<int>& arr, int val, int left, int right) {
	 if (left+1 == right) {
        if (arr[left] == val) return left;
        else if (arr[right] == val) return right;
    }
	if (left == right) return right;
	int right_mid = left + (right - left)/2;
	int result = -1;
	if (arr[right_mid] == val) {
		result = findRightIndex(arr, val, right_mid, right);
	}
	else {
		result = findRightIndex(arr, val, left, right_mid);
	}
	return result;
}

int findLeftIndex(std::vector<int>& arr, int val, int left, int right)
{
    if (left+1 == right) {
        if (arr[left] == val) return left;
        else if (arr[right] == val) return right;
    }

	if (left == right) return left;
	int left_mid = left + (right - left)/2;
	int result = -1;
	if (arr[left_mid] == val) {
		result = findLeftIndex(arr, val, left, left_mid);
	}
	else {
		result = findLeftIndex(arr, val, left_mid, right);
	}
	return result;
}


int findCount(std::vector<int>& arr, int val, int left, int right)
{
	int mid = left + (right-left)/2;
	int left_index = findLeftIndex(arr, val, left, mid);
	int right_index = findRightIndex(arr, val, mid, right);
	return right_index - left_index +1;
	
}
int findRange(std::vector<int>& arr, int left, int right, int val)
{
	int result = 0;
	while(left < right) {
		int mid = left + (right - left)/2;
		if (arr[mid] == val) {
			result = findCount(arr, val, left, right);
			break;
		}
		else {
			if (arr[mid] > val) {
			    right = mid -1;
			    result = findRange(arr, left, mid-1, val);
			}
			else if (arr[mid] < val) {
			    left = mid+1;
			    result = findRange(arr, mid+1, right, val);
			}
		}
	}
	return result;
}


int main()
{
    std::vector<int> sorted_arr = {1,3,6,8,23,45,55,55,55,67, 69, 450};
  int k = 55;
  int count = findRange(sorted_arr, 0, sorted_arr.size() - 1, k);
  if (count)
      std::cout << "number of " << std::to_string(k) << " is " << count << std::endl;
  else
      std::cout << "None" << std::endl;
	return 0;
}