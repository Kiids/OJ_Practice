/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回?true，否则返回?false。假设输入的数组的任意两个数字都互不相同。
参考以下这颗二叉搜索树：
     5
    / \
   2   6
  / \
 1   3
示例 1：
输入: [1,6,3,2,5]
输出: false
示例 2：
输入: [1,3,2,6,5]
输出: true
提示：
数组长度 <= 1000
*/


//后续遍历，根节点为数组中的最后一个元素
//假如数组中的序列满足某个二叉树的后续遍历结果，那么有连续的一部分小于根，另外连续的一部分大于根
//判断是否存在这样的两部分(代码中的cur == j可以说用来判断是否这两部分)
//递归判断小于根的那部分时候满足二叉搜索树的后续遍历序列，大于根部分同（分治）
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return _verifyPostorder(postorder, 0, postorder.size() - 1);
    }
    bool _verifyPostorder(vector<int>& postorder, int i, int j)
    {
        if(i >= j)
            return true;
        int cur = i;
        while (postorder[cur] < postorder[j])
            cur++;
        int pre = cur - 1;
        while (postorder[cur] > postorder[j])
            cur++;
        // 假如cur 不等于 j，直接返回false
        return cur == j && _verifyPostorder(postorder, i, pre) && _verifyPostorder(postorder, pre + 1, j - 1);
    }
};
