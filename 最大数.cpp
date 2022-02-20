/*
����һ��Ǹ����� nums����������ÿ������˳��ÿ�������ɲ�֣�ʹ֮���һ������������
ע�⣺���������ܷǳ�����������Ҫ����һ���ַ���������������
ʾ�� 1��
���룺nums = [10,2]
�����"210"
ʾ�� 2��
���룺nums = [3,30,34,5,9]
�����"9534330"
��ʾ��
1 <= nums.length <= 100
0 <= nums[i] <= 10^9
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        string ret;
        for (int i : nums)
            v.push_back(to_string(i));
        sort(v.begin(), v.end(), [](string& a, string& b){return a + b > b + a;});
        if (v[0] == "0")
            return "0";
        for (string s : v)
            ret += s;
        return ret;
    }
};
