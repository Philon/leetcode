# [字符串相乘](https://leetcode.com/problems/multiply-strings/)

以字符串的形式给两个非负整数`num1`和`nums2`，返回`num1`和`nums2`的乘积，也是以字符串的形式。

```
Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
```

注意：

1. `num1`和`nums2`的长度<110
2. `num1`和`nums2`仅包含数字0-9的字符
3. `num1`和`nums2`都不会以0开头，除非它本身就是0
4. 你**不可以使用内建的大数库**或者**直接把输入字符串转为整型**

## 我的思路

这道题我最开始的想法是这样的：
```
        123
x       456
------------
        738
       615
+     492
------------
=     56088
```

简单来说，就是num1的每个数字乘以num2，得到一个二维矩阵，再把这个矩阵相加，即可求得两数之积。程序实现主要是几个步骤：

1. 先反转num1和num2，因为计算需要从数的低位开始
2. 把每次相乘的结果以字符串的形式保存到一个集合中
3. 把集合中的每个元素相加，得出最终结果

但是上边的方法走了很多弯路，因为字符串反转，每次结果又以字符串的形式保存，数字-字符转换会大幅增加时间、空间复杂度。

之后看了别人的帖子，发现自己是真傻逼了：
1. 反转字符串纯粹是自己脑子进水，从0开始i++遍历改为从末尾开始i--遍历，不就可以了😂
2. 根本没必要做一个字符串集合，每次相乘的结果直接与之前的结果相加不就可以了😂

所以比较好的解决办法是这样的：
1. 首先，两个数相乘的结果长度，肯定不会超过两数的长度之和，所以可以分配个一维数组，用来保存每次相乘的结果
2. num1和num2，第1位数乘第1位数，起结果肯定放在第1位，其进位肯定放在第1位。因此，第n位乘第m位，其结果肯定放在n*m位，进位放在n*m+1位
3. 把一位数字数组转换位字符串，搞定！

```cpp
class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }
    
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> products(len1 + len2, 0);

    for (int i = len1-1; i >= 0; i--) {
      int n1 = num1[i] - '0';
      for (int j = len2-1; j >= 0; j--) {
        int p = n1 * (num2[j] - '0');
        p += products[i+j+1];
        products[i+j+1] = p % 10;
        products[i+j] += p / 10;
      }
    }

    string result = "";
    int len = len1 + len2;
    int i = 0;
    while (products[i] == 0) i++;
    for (; i < len; i++) {
      result += products[i] + '0';
    }

    return result;
  }
};
```

- 时间复杂度：O(n²)，需要嵌套遍历num1和num2
- 空间复杂度：O(n)，num1和num2长度之和