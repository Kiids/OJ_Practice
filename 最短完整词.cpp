/*
��������б�words���е�һ�����ʰ������գ�licensePlate�������е���ĸ����ô���ǳ�֮Ϊ�����ʡ��������������У���̵ĵ������ǳ�֮Ϊ��������ʡ�
������ƥ�������е���ĸʱ�����ִ�Сд�����������е� "P" ��Ȼ����ƥ�䵥���е� "p" ��ĸ��
���Ǳ�֤һ������һ����������ʡ����ж�����ʶ�������������ʵ�ƥ������ʱȡ�����б����ǰ��һ����
�����п��ܰ��������ͬ���ַ�������˵���������� "PP"������ "pair" �޷�ƥ�䣬���� "supper" ����ƥ�䡣
ʾ�� 1��
���룺licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
�����"steps"
˵�������������Ӧ�ð��� "s"��"p"��"s" �Լ� "t"������ "step" ��ֻ����һ�� "s" ������������������ͬʱ��ƥ����������Ǻ��������еĴ�Сд��
ʾ�� 2��
���룺licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
�����"pest"
˵�������� 3 ��������ĸ "s" ��������̳��ȵ������ʣ������Ƿ������ȳ��ֵ������ʡ�
ע��:
���գ�licensePlate���ĳ���������[1, 7]�С�
���գ�licensePlate������������֡��ո񡢻�����ĸ����д��Сд����
�����б�words������������ [10, 1000] �С�
ÿһ������ words[i] ����Сд�����ҳ��������� [1, 15] �С�
*/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> v(26, 0);
        for (char& c : licensePlate)
            if (isalpha(c))
                v[tolower(c) - 'a']++;

        string ret = "";
        int n = INT_MAX;
        for (string& w : words)
        {
            vector<int> vec = v;
            for (char& c : w) 
                vec[tolower(c) - 'a']--;

            int i = 0;
            for (i = 0; i < 26; i++)
                if (vec[i] > 0)
                    break;
            if (i == 26 && w.size() < n)
            {
                ret = w;
                n = w.size();
            }
        }
        return ret;
    }
};
