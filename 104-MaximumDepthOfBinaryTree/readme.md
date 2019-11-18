# [二叉树的最大深度](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

给一个二叉树，找出它的最大深度。

所谓的最大深度是指从二叉树的根节点开始向下找，离它最远的那个叶节点的数量。

```
Example:
给一个二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回深度 depth = 3.
```

## 解题思路：一行代码搞定😂

不解释了：

```cpp
int maxDepth(TreeNode* root) {
   return root ? std::max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
 }
```