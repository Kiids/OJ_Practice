// ����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�
// ʾ�� :
// ����: [1,2,1,3,2,5]
// ���: [3,5]
// ע�⣺
// ��������˳�򲢲���Ҫ��������������ӣ� [5, 3] Ҳ����ȷ�𰸡�
// ����㷨Ӧ�þ�������ʱ�临�Ӷȡ����ܷ��ʹ�ó����ռ临�Ӷ���ʵ�֣�

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = nums[0];
        int b = 0;
        int c = 0;
        int n = 1;
        vector<int> ret(2, 0);
        for(int i = 1; i < nums.size(); i++){
            a ^=nums[i];     
        }
        while(true){
            if((a & n )== n ){
               //�ҵ�Ϊ 1 ��λ��
                break;
            }
            n *= 2;
        }
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & n ) == n)
                b ^= nums[i];
            else
                c ^=nums[i];
        }
        
        ret[0] = b;
        ret[1] = c;
        return ret;
    }
};

