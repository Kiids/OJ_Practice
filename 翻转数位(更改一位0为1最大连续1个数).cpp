/*
����һ��32λ���� num������Խ�һ����λ��0��Ϊ1�����дһ�������ҳ����ܹ���õ����һ��1�ĳ��ȡ�
ʾ�� 1��
����: num = 1775(110111011112)
���: 8
ʾ�� 2��
����: num = 7(01112)
���: 4
*/

class Solution {
public:
    int reverseBits(int num) {
        int pre = 0, cur = 0, ret = 1;
        for (int i = 0; i < 32; i++)
        {
            if (num & (1 << i))
                cur++;
            else
            {
                ret = max(ret, pre + cur);
                pre = cur + 1;
                cur = 0;
            }
        }
        ret = max(ret, pre + cur);
        return ret;
    }
};

//pre��ʾ��һ������1�ĳ���+1
//cur��ʾ��ǰ����1�ĳ���
//�����Ϊ����pre+cur
//ע��ѭ������ʱ��Ҫ�ٴθ���res, ��Ϊ�п������λ��1
