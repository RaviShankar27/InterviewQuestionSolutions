#include<iostream>

using namespace std;

unsigned long int calculateChunk(int curr, int iters)
{
	unsigned long int mult = 1;
	for (int i = 1; i <= iters; ++i) {
		mult *= (curr+i);
	}
	return mult;
}

unsigned long int calculateFn(int N)
{
	int iters = 0; 
	unsigned long int sum = 0;
	int curr = 0;
	while(curr < N) {
		++iters;
		if (curr+ iters > N) iters = N - curr;
		sum += calculateChunk(curr, iters);
		curr = curr + iters;
	}
	return sum;
}

int main()
{
	int N = 9;
	// f(N) = 1 + (2*3) + (4*5*6) + (7*8*9)
	unsigned long int fN = calculateFn(N);
	cout << "F(N) of N is=" << fN << endl;
	return 0;
}
