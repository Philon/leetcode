# [股票最佳买卖时间](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

有一个数组`prices`，`prices[i]`表示`第i天`的股票价格。

希望选择出**某一天**买入股票并在**未来的某一天**卖出以获得利润最大化。

*返回你通过交易能取得的最大利润值，如果得不到任何利润，就返回0*。

**案例1：**
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: 在第二天（价格为1）时买入并在第五天（价格为6）时卖出，利润为6-1 = 5。
注意：第2天买且第1天卖的情况是不允许的，买必须在卖之前发生。
```

**案例2：**
```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: 在本例中，无交易可做，因此利润为0。
```

**约束：**
- 1 <= prices.length <= 10^5
- 0 <= prices[i] <= 10^4
```

## 解题思路

我看的[答案](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solution/)。。。😭