/*
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������������򷵻�?true�����򷵻�?false���������������������������ֶ�������ͬ��
�ο�������Ŷ�����������
     5
    / \
   2   6
  / \
 1   3
ʾ�� 1��
����: [1,6,3,2,5]
���: false
ʾ�� 2��
����: [1,3,2,6,5]
���: true
��ʾ��
���鳤�� <= 1000
*/


//�������������ڵ�Ϊ�����е����һ��Ԫ��
//���������е���������ĳ���������ĺ��������������ô��������һ����С�ڸ�������������һ���ִ��ڸ�
//�ж��Ƿ����������������(�����е�cur == j����˵�����ж��Ƿ���������)
//�ݹ��ж�С�ڸ����ǲ���ʱ����������������ĺ����������У����ڸ�����ͬ�����Σ�
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
        // ����cur ������ j��ֱ�ӷ���false
        return cur == j && _verifyPostorder(postorder, i, pre) && _verifyPostorder(postorder, pre + 1, j - 1);
    }
};
