// HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
// ��������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,
// ����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
// ����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
// ��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max;
        int sum = 0;
         
        if (!array.empty())
           max = array[0];
         
        for (int i = 0; i < array.size(); i++)
        {
            sum = array[i];
            for (int j = i + 1; j < array.size(); j++)
            {
                if (sum > max)
                    max = sum;
                 
                sum += array[j];
            }
            if (sum > max)
                max = sum;
        }
        return max;
    }
};
