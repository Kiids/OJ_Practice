/*
СA �� СB ��������֡�СB ÿ�δ� 1, 2, 3 �����ѡ��һ����СA ÿ��Ҳ�� 1, 2, 3 ��ѡ��һ���¡�����һ���������������Ϸ���뷵�� СA �¶��˼��Σ�
�����guess����Ϊ СA ÿ�εĲ²⣬answer����Ϊ СB ÿ�ε�ѡ��guess��answer�ĳ��ȶ�����3��
ʾ�� 1��
���룺guess = [1,2,3], answer = [1,2,3]
�����3
���ͣ�СA ÿ�ζ��¶��ˡ�
ʾ�� 2��
���룺guess = [2,2,3], answer = [3,2,1]
�����1
���ͣ�СA ֻ�¶��˵ڶ��Ρ�
���ƣ�
guess�ĳ��� = 3
answer�ĳ��� = 3
guess��Ԫ��ȡֵΪ {1, 2, 3} ֮һ��
answer��Ԫ��ȡֵΪ {1, 2, 3} ֮һ��
*/

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        return !(guess[0]^answer[0]) + !(guess[1]^answer[1]) + !(guess[2]^answer[2]);
    }
};
