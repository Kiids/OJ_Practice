// ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
// ��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 1;
        int key = numbers[0];
         
        for (int i = 1; i < numbers.size(); i++)
        {
            if(numbers[i] == key)
                count++;
            else
                count--;
             
            if(count == 0)
            {
                key = numbers[i];
                count = 1;
            }
        }
         
        int c = 0;
        for (int i = 0; i < numbers.size(); i++)
            if(numbers[i] == key)
                c++;
         
        if (c > (numbers.size()/2))
            return key;
        else
            return 0;
    }
};

