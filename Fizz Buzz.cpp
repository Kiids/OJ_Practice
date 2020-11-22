/*
дһ����������� 1 �� n ���ֵ��ַ�����ʾ��
1. ��� n ��3�ı����������Fizz����
2. ��� n ��5�ı����������Buzz����
3.��� n ͬʱ��3��5�ı�������� ��FizzBuzz����
ʾ����
n = 15,
����:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        int i = 1;
        while (i <= n)
        {
            if (i % 15 == 0)
                ret.push_back("FizzBuzz");
            else if (i % 5 == 0)
                ret.push_back("Buzz");
            else if (i % 3 == 0)
                ret.push_back("Fizz");
            else
                ret.push_back(to_string(i));
            i++;   
        }
        return ret;
    }
};

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 2; i < n; i += 3)
            res[i] = "Fizz";
        for (int i = 4; i < n; i += 5)
            res[i] += "Buzz";
        for (int i = 1; i <= n; i++)
            if (res[i-1].empty())
            	res[i-1] = to_string(i);
        return res;
    }
};
