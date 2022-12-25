/*
在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 逐行 依次按 “之” 字形进行标记。
如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；
而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。
给你树上某一个节点的标号 label，请你返回从根节点到该标号为 label 节点的路径，该路径是由途经的节点标号所组成的。
示例 1：
输入：label = 14
输出：[1,3,4,14]
示例 2：
输入：label = 26
输出：[1,2,6,10,26]
提示：
1 <= label <= 10^6
*/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int deep = log2(label), n = deep + 1;
        vector<int> v(n, 1);
        while(label != 1)
        {
            v[--n] = label;
            int up = deep % 2 ? ceil((pow(2, deep + 1) - label) / 2) : pow(2, deep - 1) + 1 - ceil((pow(2, deep + 1) - label) / 2);
            label = (--deep) % 2 ? pow(2, deep + 1) - up : pow(2, deep) + up - 1;
        }
        return v;
    }
};

// double ceil(double x); 返回大于或者等于指定表达式的最小整数 
// res尾部添加label
// 判断label所在行
// 找到label父亲节点所在位置（左->右）
// 更新label为父亲节点数值

