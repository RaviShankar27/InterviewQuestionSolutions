/*maximumchocolatesueat
Given following three values, the task is to find the total number of maximum chocolates you can eat.

money : Money you have to buy chocolates
price : Price of a chocolate
wrap : Number of wrappers to be returned for getting one extra chocolate.
It may be assumed that all given values are positive integers and greater than 1.*/

#include<iostream>

using namespace std;

int calculateMaxChocToEat(int money, int pricePerChoc, int wrapsToBuyAChoc)
{
	int initial_choc = money/pricePerChoc;

	int wraps = initial_choc;
	int chocs_from_wraps = wraps/wrapsToBuyAChoc;
	int wraps_remaining = wraps%wrapsToBuyAChoc;
	int next_chocs =  chocs_from_wraps;
	int total_chocs = initial_choc + next_chocs;
	int temp_chocs = (wraps_remaining+next_chocs)/wrapsToBuyAChoc;
		//now we have wraps from wraps_remainining from earlier + next_chocs
	while(temp_chocs > 0) {
		wraps_remaining = (wraps_remaining+next_chocs)%wrapsToBuyAChoc;
		next_chocs = temp_chocs;
		total_chocs += temp_chocs;
		temp_chocs = (wraps_remaining+next_chocs)/wrapsToBuyAChoc;
	}

	return total_chocs;
}

int main(int argc, char* argv[])
{
	int money = 235;
	int price_choc = 7;
	int wrap_num_per_choc = 11;
	/*if (argc < 4) {
		cout << "Error : Please pass arguments money, price and wrap" << endl;
		return 0; 
	}
	money = argv[0];
	price_choc = argv[1];
	wrap_num_per_choc = argv[2];
	*/
	//cin >> money >> price_choc >> wrap_num_per_choc;
	int max_choc = calculateMaxChocToEat(money, price_choc, wrap_num_per_choc);
	cout << "Max choc will be eaten " << max_choc << endl;
	return 0;
}