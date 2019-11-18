# [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/solution/)

给定两个非空链表用来存储两个非负数。数字的每一位都存在链表的节点当中，把这两个数相加并将结果存在新链表中返回。  
可以假定两个数最高位非零，出本它本身就是个0。
```
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
解释: 342 + 465 = 807.
```

本题目就是两数相加求值，特殊的地方在于两数是两个单链表，求得的值也必须是单链表，这种算法可以应用于超大数运算，比(unsigned long long long long ...)还大。

## 算法
正如小学生在纸上一步一步求和的过程一样，我们会把两个数“纵向右对齐排列”，从最低有效数开始相加，l1和l2的表头就是这个最低有效数。显然，每一位的数字取值范围是0～9，两数之和有可能会超过10，小学生都知道，这个叫进位(carry = 1)，提供给下一组数字计算。当然，这个进位的值只会是0或1，因为9+9+1=19(那个1有可能是上一组的进位)

所以我们可以得到一下步骤：
- 初始化一个节点result作为求和链表，再初始化一个current作为result的表头
- 初始化进位变量carry = 0
- 初始化p和q作为l1和l2链表的表头(其实没必要，因为函数实参本身也是个局部变量)
- 循环遍历l1和l2的每一个节点(即p和q不为空，carry > 0)：
   - 如果p节点有数，把值存到x变量
   - 如果q节点有数，把值存到y变量
   - sum = x + y + carry
   - carry = sum / 10
   - current追加一个节点，并把新节点的值设为sum % 10(sum取模)，current指向下一节点
   - p和q指向下一节点
- 返回result表头的next即可

下面是代码：
```java
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(0);
    ListNode p = l1, q = l2, curr = dummyHead;
    int carry = 0;
    while (p != null || q != null) {
        int x = (p != null) ? p.val : 0;
        int y = (q != null) ? q.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (p != null) p = p.next;
        if (q != null) q = q.next;
    }
    if (carry > 0) {
        curr.next = new ListNode(carry);
    }
    return dummyHead.next;
}
```
时间复杂度: O(max(m, n))，m和n表示l1和l2各自的长度
空间复杂度: O(max(m, n))，因为求和链表也需要那么多位呀🤣
