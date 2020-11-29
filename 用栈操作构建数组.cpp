/*
����һ��Ŀ������ target ��һ������ n��ÿ�ε�������Ҫ��  list = {1,2,3..., n} �������ȡһ�����֡�
��ʹ����������������Ŀ������ target ��
Push���� list �ж�ȡһ����Ԫ�أ� ���������������С�
Pop��ɾ�������е����һ��Ԫ�ء�
���Ŀ�����鹹����ɣ���ֹͣ��ȡ����Ԫ�ء�
��Ŀ���ݱ�֤Ŀ�������ϸ����������ֻ���� 1 �� n ֮������֡�
�뷵�ع���Ŀ���������õĲ������С�
��Ŀ���ݱ�֤����Ψһ�ġ�
ʾ�� 1��
���룺target = [1,3], n = 3
�����["Push","Push","Pop","Push"]
���ͣ� 
��ȡ 1 ���Զ��������� -> [1]
��ȡ 2 ���Զ��������飬Ȼ��ɾ���� -> [1]
��ȡ 3 ���Զ��������� -> [1,3]
ʾ�� 2��
���룺target = [1,2,3], n = 3
�����["Push","Push","Push"]
ʾ�� 3��
���룺target = [1,2], n = 4
�����["Push","Push"]
���ͣ�ֻ��Ҫ��ȡǰ 2 �����־Ϳ���ֹͣ��
ʾ�� 4��
���룺target = [2,3,4], n = 4
�����["Push","Pop","Push","Push","Push"]
��ʾ��
1 <= target.length <= 100
1 <= target[i] <= 100
1 <= n <= 100
target ���ϸ������
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        int nextPush = 1;
        for (int i = 0; i < target.size(); i++)
        {
            while (nextPush < target[i])
            {
                ret.push_back("Push");
                ret.push_back("Pop");
                nextPush++;
            }
            ret.push_back("Push");
            nextPush++;
        }
        return ret;
    }
};
