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
