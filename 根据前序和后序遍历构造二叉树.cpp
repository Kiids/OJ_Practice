/*
���������������飬preorder �� postorder ������ preorder ��һ������ ���ظ� ֵ�Ķ�������ǰ�������postorder ��ͬһ�����ĺ���������ع������ض�������
������ڶ���𰸣������Է������� �κ� һ����
ʾ�� 1��
���룺preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
�����[1,2,3,4,5,6,7]
ʾ�� 2:
����: preorder = [1], postorder = [1]
���: [1]
��ʾ��
1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
preorder ������ֵ�� ��ͬ
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
postorder ������ֵ�� ��ͬ
��֤ preorder �� postorder ��ͬһ�ö�������ǰ������ͺ������
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* Fun(vector<int>& pre, vector<int>& post, int prestart, int preend, int poststart, int postend)
    {
        if (prestart > preend)
            return NULL;
            
        TreeNode* root = new TreeNode(pre[prestart]);
        if (prestart == preend)                              //ֻ��һ����ֱ�ӷ���
            return root;
            
        int i = poststart; 
        while (i < postend && post[i] != pre[prestart + 1])  //ȷ���ֽ�㣬�������ĸ��ڵ�
            i++;

        int len = i - poststart + 1;                         //����������
        root->left = Fun(pre, post, prestart + 1, prestart + len, poststart, i);
        root->right = Fun(pre, post, prestart + 1 + len, preend, i + 1, postend - 1);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return Fun(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};

//���������ֽ��:
//1.ǰ��ĵ�һ���ͺ�������һ�����ǵ�ǰ���ڵ�λ��;
//2.ǰ���У��������ĸ��ڵ��ǵ�ǰ���ڵ�λ��+1�����ں����У����λ�����������ĸ��ڵ��λ��
//Ҳ����˵���ֽ��λ�������������ڵ��λ�ã��ں������ҵ����λ�ã������������������

