// ���дһ��������������������ӡ�����ʹ��+�����������������
// ��������int A��B���뷵��A��B��ֵ
// ����������
// 1,2
// ���أ�3

class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        while (A)
        {
            int t = B;
            B = A ^ B;
            A = A & t;
            A <<= 1;
        }
        return B;
    }
};
// AΪ��λ��B�ǽ�� 

class Solution 
{ 
public: 
	int Add(int num1,int num2) 
	{ 
		while( num2 != 0 )
		{ 
			int sum = num1 ^ num2; //�õ���Ӻ󲻰�����λ������ 
			int carray = (num1 & num2) << 1; //�õ�������ӵĽ�λ 
			num1 = sum; //���������ӣ�ֱ����λΪ0 
			num2 = carray; 
		}
		return num1; 
	} 
};

