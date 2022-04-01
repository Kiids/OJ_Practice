/*
������ˮ���������ֱ�Ϊ jug1Capacity �� jug2Capacity ����ˮ�Ĺ�Ӧ�����޵ġ�ȷ���Ƿ��п���ʹ����������׼ȷ�õ� targetCapacity ����
������Եõ� targetCapacity ��ˮ�������������ˮ���е�һ��������ʢ��ȡ�õ� targetCapacity ��ˮ��
����ԣ�
װ������һ��ˮ��
�������һ��ˮ��
��һ��ˮ��������һ��ˮ����ˮ��ֱ��װ�����ߵ���
ʾ�� 1: 
����: jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
���: true
���ͣ����������� "Die Hard"
ʾ�� 2:
����: jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5
���: false
ʾ�� 3:
����: jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3
���: true
��ʾ:
1 <= jug1Capacity, jug2Capacity, targetCapacity <= 10^6
*/

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity)
            return false;
        int a = max(jug1Capacity, jug2Capacity);
        int b = min(jug1Capacity, jug2Capacity);
        int c = a + b;
        while (c)
        {
            if (c == targetCapacity)
                return true;

            if (c >= b)
                c -= b;
            else
                c += a;
        }
        return false;
    }
};

//�ȴ������������������Ӹպ����㣬������һ���պ����㡣
//����ֻ��ͨ�������С�������µ����֣�
//�������a��С������b��ֻ��ͨ���������ˮ����С����Ȼ���ٰ�С����ˮ����������µ��������֣�
//�������µ������ǣ�a-b, a-2b, a-3b..., a-n*bֱ�������ʣ���ˮС��b����
//��ʱ��Ҫ������µ��������֣�Ҳֻ��һ������������
//�����ʣ���������С����Ȼ����װ����������һ���µ�����: 2a - n*b
//��ʱ��Ҫ������µ��������֣���ֻ��һ������������
//�Ӵ���ﵹһ��ˮ��С��������Ȼ���ٰ�С����գ�������һ���µ�����: 2a - n*b - b

//��һ������c��ʾ��ǰ��ˮ����
//�����ˮ������ʱ�򣬾Ͳ��ϼ�ȥС������b��Ҳ���ǲ��ϵ� c -= b��һ���ж� c �Ƿ���� targetCapacity��
//�����ˮ��������ʱ�򣬾Ͱ�ʣ���ˮ����С����Ȼ����������c += a
//���տ϶��ܹ��պü����㣬�������Ǵ����װ��b��ˮ������ʷ��װˮ������a * b, ��С����������������
//ʵ���������ʷ��װˮ�� a �� b ����С��������������֮���´��൱�ڻص���ʼ״̬��
//��������������û�����������Ժ�Ҳ�����������ˡ�
//��c��ʼ����a + b�������������Ҳ�˼�����
