/*
����һ���Ǹ��������� A�� A ��һ��������������һ��������ż����
��������������Ա㵱 A[i] Ϊ����ʱ��i Ҳ���������� A[i] Ϊż��ʱ�� i Ҳ��ż����
����Է����κ���������������������Ϊ�𰸡�
ʾ����
���룺[4,2,5,7]
�����[4,5,2,7]
���ͣ�[4,7,2,5]��[2,5,4,7]��[2,7,4,5] Ҳ�ᱻ���ܡ�
��ʾ��
2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int oddIndex = 1;
        for (int i = 0; i < A.size(); i += 2)
        { 
            if (A[i] % 2 == 1)                // ��ż��λ���������� 
            {
                while (A[oddIndex] % 2 != 0)
                    oddIndex += 2;            // ������λ��һ��ż�� 
                swap(A[i], A[oddIndex]);      // �滻 
            }
        }
        return A;
    }
};
