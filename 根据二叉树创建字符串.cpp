/*
����Ҫ����ǰ������ķ�ʽ����һ��������ת����һ�������ź�������ɵ��ַ�����
�սڵ�����һ�Կ����� "()" ��ʾ����������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�
ʾ�� 1:
����: ������: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

���: "1(2(4))(3)"
����: ԭ�����ǡ�1(2(4)())(3())����
����ʡ�����в���Ҫ�Ŀ����Ŷ�֮��
�����ǡ�1(2(4))(3)����
ʾ�� 2:
����: ������: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

���: "1(2()(4))(3)"
����: �͵�һ��ʾ�����ƣ�
�������ǲ���ʡ�Ե�һ�����������ж���������֮���һ��һӳ���ϵ��
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void _tree2str(TreeNode* t, string& s)
    {
        if (t)
        {
            s += '(';
            s += to_string(t->val);
            if (t->left == NULL && t->right != NULL)
                s += "()";
            else
                _tree2str(t->left, s);
            _tree2str(t->right, s);
            s += ')';
        }
    }
    string tree2str(TreeNode* t) {
        if (t == NULL)
            return "";

        string ret;
        _tree2str(t, ret);
        ret = ret.substr(1, ret.size()-2);
        return ret;
    }
};
