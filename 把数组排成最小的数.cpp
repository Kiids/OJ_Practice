/*
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
ʾ�� 1:
����: [10,2]
���: "102"
ʾ�� 2:
����: [3,30,34,5,9]
���: "3033459"
��ʾ:
0 < nums.length <= 100
˵��:
���������ܷǳ�����������Ҫ����һ���ַ�������������
ƴ�����������ֿ��ܻ���ǰ�� 0�����������Ҫȥ��ǰ�� 0
*/


//�ų���С�����������������x��y�����x + y < y + x,��xӦ������y֮ǰ����֮����x+y>y+x,��yӦ����x֮ǰ
class Solution {
public:
    static bool compare(string x, string y)
    {
        return x + y < y + x;
    }
    string minNumber(vector<int>& nums) {
        vector<string> v;
        for (auto i : nums)
            v.push_back(to_string(i));
        sort(v.begin(), v.end(), compare);
        string ret = "";
        for (auto s : v)
            ret += s;
        return ret;
    }
};
