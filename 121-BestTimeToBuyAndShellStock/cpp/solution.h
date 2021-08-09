#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = prices[0];
        int daycount = prices.size();

        for (int i = 1; i < daycount; i++) {
            if (minprice > prices[i]) {
                minprice = prices[i];
            } else {
                maxprofit = std::max(prices[i]-minprice, maxprofit);
            }
        }

        return maxprofit;
    }
};