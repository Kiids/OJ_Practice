/*
����һ�������ַ������ֵ����飬�ҵ���������飬�Ұ������ַ������ֵĸ�����ͬ��
���ظ������飬�����ڶ��������飬������˵���С�ġ������������������飬����һ�������顣
ʾ�� 1:
����: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]
���: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]
ʾ�� 2:
����: ["A","A"]
���: []
��ʾ��
array.length <= 100000
*/

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int num[100005];
	    //����+1����ĸ-1������num,num��1�±꿪ʼ��
	    map<int,int> m;
	    for (int i = 0; i < array.size(); i++)
	    {
		    if (isdigit(array[i][0]))
                num[i + 1] = num[i] + 1;
    		else
                num[i + 1] = num[i] - 1;
    	}
	    int ans = 0;
	    int start = 0;
	    int end = 0;
	    for (int i = 1; i <= array.size(); i++)  //�鿴num
	    {
		    if (num[i] != 0 && m[num[i]] == 0)
                m[num[i]] = i;  //��¼���ֵ�һ�γ��ֵĵط� ���num[i]=0 ��˵���Ǵ�ͷ��һ���ַ���ʼ�ģ�m[0]=0��
		    else  //num[i]֮ǰ�Ѿ����ֹ�������num[i]=0
		    {
			    if (ans < i-m[num[i]])
			    {
    				ans = i - m[num[i]];
				    start = m[num[i]] + 1;  //�Ǵӵ�һ�γ��ֵĺ����Ǹ�λ�ÿ�ʼ��
				    end = i;
			    }
		    }
        }
        //num�Ǵ�1��ʼ��¼�����԰�start��end����ǰŲһŲ
        start--;
        end--;
        vector<string> ret;
        if (start == end)
            return ret;
        for (int i = start; i <= end; i++)
            ret.push_back(array[i]);
        return ret;
    }
};
/*
���Ƚ���һ��num���飬���array[i][0]�����֣���+1���������ĸ��-1�����������ǾͿ��Եõ�һ��ǰ׺�����飬
����[0,1,2,3,1,2,0]��������ͬ������֮�������ĸ�����ָ�����ȵĳ��ȣ���Ϊ+1,-1������
�ͻ���֮ǰ���ֵ�ԭ���Ǹ�һ��������
����map<int,int>��ϣ���¼map[0]��һ�γ��ֵ�λ��
���map[i]==0��num[i]�ֲ�����0����˵������num[i]��һ�γ��ֵ�λ��
���map[i]=0.˵���Ǵ�ͷ��һ���ַ���ʼ�������
Ȼ����i-map[num[i]]����������������Ƚϣ�i�ǵ�ǰnum[i]����λ�ã�map[num[i]]��num[i]��һ�γ��ֵ�λ��
*/
