/*
����һ���������� A�����������Ч��ɽ������ͷ��� true�����򷵻� false��
�����ǻع�һ�£���� A ����������������ô����һ��ɽ�����飺
A.length >= 3
�� 0 < i < A.length - 1 �����£����� i ʹ�ã�
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
ʾ�� 1��
���룺[2,1]
�����false
ʾ�� 2��
���룺[3,5,5]
�����false
ʾ�� 3��
���룺[0,3,2,1]
�����true
��ʾ��
0 <= A.length <= 10000
0 <= A[i] <= 10000 
*/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3 || is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend()))
            return false;
		int i = 0;
		for ( ; i < A.size() - 1 && A[i] < A[i + 1]; i++);
		for ( ; i < A.size() - 1 && A[i] > A[i + 1]; i++);
		return i == A.size() - 1;
    }
};
//�����������Ԫ�ظ��������������ߵ���������ݼ���ֱ�ӷ���false���ɡ�
//��һ��iָ���ǰ�����������һ��ѭ���˳�ʱ��˵���ҵ�ɽ�������������ڵ�����ȡ�
//�ڶ���ѭ���������Ƿ�Ϊ�ݼ���һֱ�ݼ��ͻ�������˽�β����true��������;�˳�����false��
