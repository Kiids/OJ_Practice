/*
���������� N �ſ�Ƭ��ÿ�ſ�Ƭ������ͱ��涼д��һ�������������뱳���ϵ����п��ܲ�һ������
���ǿ����ȷ�ת�����ſ�Ƭ��Ȼ��ѡ������һ�ſ�Ƭ��
���ѡ�е����ſ�Ƭ��������� X ������һ�ſ�Ƭ����������ֶ���ͬ����ô���������������Ҫ�����֡�
�ĸ�������Щ��Ҫ����������С�������ҵ���Щ���е���Сֵ���أ����û��һ�����ַ���Ҫ��ģ���� 0��
����, fronts[i] �� backs[i] �ֱ����� i �ſ�Ƭ������ͱ�������֡�
�������ͨ����ת��Ƭ�����������뱳���ϵ�������ô��������������ͱ�ɱ����������������ͱ�����������
ʾ����
���룺fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
�����2
���ͣ��������Ƿ�ת�ڶ��ſ�Ƭ����ô�������������� [1,3,4,4,7] �� ������������ [1,2,4,1,3]��
��������ѡ��ڶ��ſ�Ƭ����Ϊ���ڸÿ�Ƭ�ı�������� 2��2 �����⿨Ƭ�������������ͬ������ 2 ����������Ҫ�����֡�
��ʾ��
1 <= fronts.length == backs.length <= 1000
1 <= fronts[i] <= 2000
1 <= backs[i] <= 2000
*/

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> cannotNums;
        for (int i = 0; i < fronts.size(); i++)
            if (fronts[i] == backs[i])
                cannotNums.insert(fronts[i]);
        int ret = INT_MAX;
        for (int i = 0; i < fronts.size(); i++)
        {
            if (cannotNums.count(fronts[i]) == 0)
                ret = min(ret, fronts[i]);
            if (cannotNums.count(backs[i]) == 0)
                ret = min(ret, backs[i]);
        }
        return ret == INT_MAX ? 0 : ret;
    }
};
