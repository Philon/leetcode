#include "solution.h"
#include <assert.h>

int main(int argc, char* argv[])
{
  Solution s;
  vector<int> prices1 = {7,1,5,3,6,4};
  vector<int> prices2 = {7,6,4,3,1};
  assert(s.maxProfit(prices1) == 5);
  assert(s.maxProfit(prices2) == 0);
  return 0;
}