/*
���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С��Ϊ 0 �����Կ����������֡�A ������Ϊ 14��
ʾ�� 1:
����: [1,2,3,4,5]
���: True
ʾ�� 2:
����: [0,0,1,2,5]
���: True
���ƣ�
���鳤��Ϊ 5
�������ȡֵΪ [0, 13] .
*/

// ����֮���˿�������ֱ���ж�����������֮����Ҫ���ٸ�������С���
// �����Ҫ���С�����������������д�С�����������򷵻� false 
// �෴�������Ҫ���С����������С�ڻ�������д�С�����������򷵻� true 
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = 0;
        for (int i = 0; i < 4; i++)
        {
            if (nums[i] == 0)
            {
                n++;
                continue;
            }
            if (nums[i] == nums[i + 1])
                return false;
            n -= nums[i + 1] - nums[i] - 1;
        }
        return n >= 0;
    }
};

// ������ 
//5 ���˿����е����ֵ maxValue ����Сֵ minValue ��ʹ��Ϊ˳����Ҫ maxValue - minValue + 1 ����
//�ڲ��� maxValue �� minValue �����У�������С�� 0
//��� maxValue - minValue + 1 > 5��˵����Ŀ���� 5 ���Ʋ����Թ���˳�ӣ����� false .
//��ʹ�����д�С����Ҳ���������ʹ������˳�ӡ�
//��� maxValue - minValue + 1 <= 5��˵�� 5 �������Թ���˳�ӣ����� true��
//����Ĵ�С����ں���λ�ü��ɡ�
//�ٶ���һ����־�����ж��Ƿ����ظ����֣������ظ�����ֱ�ӷ��� false��
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        bool m[15];
        memset(m, 0, sizeof(m));
        int minValue = 14, maxValue = 0;
        for (int item : nums) {
            if (item == 0) {
                continue;
            }
            if (m[item]) {
                return false;
            }
            m[item] = true;
            minValue = min(minValue, item);
            maxValue = max(maxValue, item);            
        }
        return maxValue - minValue + 1 <= 5;
    }
};
