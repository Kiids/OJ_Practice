/*
�� buckets ͰҺ�壬���� ������һͰ ���ж�ҩ������װ�Ķ���ˮ�����Ǵ���ۿ�������һ����Ϊ��Ū�����ֻˮͰ���ж�ҩ�������ιһЩ��ȣ�ͨ���۲����Ƿ���������жϡ����ҵ��ǣ���ֻ�� minutesToTest ����ʱ����ȷ����ͰҺ�����ж��ġ�
ι��Ĺ������£�
ѡ�����ɻ������ι��
��������С��ͬʱ��������������Ͱ�е�ˮ�����Ҹù��̲���Ҫʱ�䡣
С�����ˮ�󣬱����� minutesToDie ���ӵ���ȴʱ�䡣�����ʱ�����ֻ�ܹ۲죬�����������ι��
���� minutesToDie ���Ӻ����кȵ���ҩ��������ȥ���������������������
�ظ���һ���̣�ֱ��ʱ�����ꡣ
����Ͱ����Ŀ buckets ��minutesToDie �� minutesToTest ������ �ڹ涨ʱ�����ж��ĸ�Ͱ�ж������ ��С ���� ��
ʾ�� 1��
���룺buckets = 1000, minutesToDie = 15, minutesToTest = 60
�����5
ʾ�� 2��
���룺buckets = 4, minutesToDie = 15, minutesToTest = 15
�����2
ʾ�� 3��
���룺buckets = 4, minutesToDie = 15, minutesToTest = 30
�����2
��ʾ��
1 <= buckets <= 1000
1 <= minutesToDie <= minutesToTest <= 100
*/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(base));
    }
};
