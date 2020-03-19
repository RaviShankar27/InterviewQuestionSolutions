//longestIncreasingSubSequence
/*The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence
of a given sequence such that all elements of the subsequence are sorted in increasing order.
For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}
*/

#include <iostream>
#include <vector>
using namespace std;
int longestIncreasingSubSequence(vector<int> sequence, vector<int>& lonSeq)
{
    if (sequence.empty()) return 0;
	int index_of_prev_max = 0;
	int max_length_of_prev = 1;
	int current_index = 0;
	int current_max_length = 1;
	lonSeq.push_back(sequence[0]);
	for (int index = 1; index < sequence.size(); ++index) {
		if ( (sequence[index] >= sequence[index-1])) {
		    if ((index_of_prev_max != 0) && (sequence[index] >= sequence[index_of_prev_max])) {
		        index_of_prev_max = index;
				max_length_of_prev++;
		    }
		    lonSeq.push_back(sequence[index]);
			current_index++;
			current_max_length++;
		}
		else {
		    if (index_of_prev_max == 0) index_of_prev_max = current_index;
			if ((index-1 != index_of_prev_max) && (sequence[index-1] >= sequence[index_of_prev_max])) {
				index_of_prev_max = index-1;
				max_length_of_prev++;
				lonSeq.push_back(sequence[index-1]);
			}
			if (max_length_of_prev <= current_max_length) {
			  
			    if ((lonSeq.size() != current_max_length) || (lonSeq[lonSeq.size()-1] > sequence[current_index])) {
			        lonSeq.clear();
				    for(int i = 1; i <= current_max_length; ++i) {
				        lonSeq.push_back(sequence[index_of_prev_max+i]);   
				    }
			    }
				max_length_of_prev = current_max_length;
				index_of_prev_max = current_index;
			}
			current_max_length = 1;
			current_index = index;
		}
	}
	if (max_length_of_prev < current_max_length) {
		max_length_of_prev = current_max_length;
	}
	return max_length_of_prev;
}


int main()
{
	vector<int> sequence = {10,22,9,33,21,50,41,60,80};
	//vector<int> sequence = {1,2,9,33,121,150,241,260,280};
	//vector<int> sequence = {10,9,8,7,6,5,3,2};
	//vector<int> sequence = {10,9,8,7,16,25,43,52,65};
	//vector<int> sequence = {10,6,8,12,14,16,25,43,52,65};
	vector<int> longestSeq;
	int length = longestIncreasingSubSequence(sequence, longestSeq);
	cout << "LIS length = " << length << endl;
	for (auto elem: longestSeq) {
		cout << " " << elem;
	}
	return 0;
}

