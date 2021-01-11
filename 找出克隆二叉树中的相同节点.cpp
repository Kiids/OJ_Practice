/*
�������ö�������ԭʼ�� original �Ϳ�¡�� cloned���Լ�һ��λ��ԭʼ�� original �е�Ŀ��ڵ� target��
���У���¡�� cloned ��ԭʼ�� original ��һ�� ���� ��
���ҳ����� cloned �У��� target ��ͬ �Ľڵ㣬�����ضԸýڵ�����ã��� C/C++ ����ָ��������з��� �ڵ�ָ�룬�������Է��ؽڵ㱾����
ע�⣺
�� ���� �����ö��������Լ� target �ڵ���и��ġ�
ֻ�� ���ضԿ�¡�� cloned �����еĽڵ�����á�
���ף���������������ֵ��ͬ�Ľڵ㣬�㽫��ν��
ʾ�� 1:
����: tree = [7,4,3,null,null,6,19], target = 3
���: 3
����: ��ͼ�������� original �� cloned��target �ڵ����� original �У�����ɫ��ǡ������� cloned �еĻ���ɫ�Ľڵ㣨����ʾ�����ƣ���
ʾ�� 2:
����: tree = [7], target =  7
���: 7
ʾ�� 3:
����: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
���: 4
ʾ�� 4:
����: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
���: 5
ʾ�� 5:
����: tree = [1,2,null,3], target = 2
���: 2
��ʾ��
���нڵ��������ΧΪ [1, 10^4] ��
ͬһ�����У�û��ֵ��ͬ�Ľڵ㡣
target �ڵ����� original �е�һ���ڵ㣬���Ҳ����� null ��
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr || cloned == nullptr)
			return nullptr;
            
		if (target->val == original->val && target->val == cloned->val)
			if (dfs(original, cloned, target))
				return cloned;

		TreeNode * left = getTargetCopy(original->left, cloned->left, target);
		TreeNode * right = getTargetCopy(original->right, cloned->right, target);
		return left ? left : right;
    }

    bool dfs(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
		if (original == nullptr && cloned == nullptr && target == nullptr)
			return true;

		if (target->val == original->val && target->val == cloned->val)
			return dfs(original->left, cloned->left, target->left) && dfs(original->right, cloned->right, target->right);
            
		return false;
	}
};
