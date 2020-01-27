// �����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
// ʾ�� 1:
// ����: num1 = "2", num2 = "3"
// ���: "6"
// ʾ�� 2:
// ����: num1 = "123", num2 = "456"
// ���: "56088"
// ˵����
// num1 �� num2 �ĳ���С��110��
// num1 �� num2 ֻ�������� 0-9��
// num1 �� num2 �������㿪ͷ������������ 0 ����
// ����ʹ���κα�׼��Ĵ������ͣ����� BigInteger����ֱ�ӽ�����ת��Ϊ����������

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        
        string res;
        int n1 = num1.size(), n2 = num2.size();
        int k = n1 + n2 - 2, carry = 0;
        vector<int> v(n1 + n2, 0);
        
        for (int i = 0; i < n1; ++i) 
            for (int j = 0; j < n2; ++j)  // ��λ��˲�����
                v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
        
        for (int i = 0; i < n1 + n2; ++i)  // ��λ����
        {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10;
        }
        
        int i = n1 + n2 - 1;
        while (v[i] == 0) 
            --i;
        if (i < 0) 
            return "0";
        while (i >= 0) 
            res.push_back(v[i--] + '0');
        
        return res;
    }
};

