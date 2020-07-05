/*
�ַ��������ֱ༭����:����һ���ַ���ɾ��һ���ַ������滻һ���ַ��� ���������ַ�������дһ�������ж������Ƿ�ֻ��Ҫһ��(�������)�༭��
ʾ�� 1:
����: 
first = "pale"
second = "ple"
���: True
ʾ�� 2:
����: 
first = "pales"
second = "pal"
���: False
*/

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first == second)
            return true;
            
        int diff = first.size() - second.size();
        if (abs(diff) > 1)
            return false;

        // 1. ���ַ�������ȣ��ҳ���ֻ���1��ǰ����
        // 2. ʶ�������ַ����ĸ��ϳ�����ʹ��˫ָ���ǰ��ɨ�������ַ���
        // 3. (a)���������ͬ��ֻ��һ����ͬ�������һ��ǰ��ɨ��һ��ͣ�ڲ�ͬ��λ�ô���
        // 4. (b)������Ȳ�ͬ��ֻ��һ���ַ������ڽϵĳ��ַ�����˵���Ӻ�ɨ��һ����Խ����ͣ�ڴ�ǰɨ��ͣס��λ�á�
        // 5. (b-1) ͣס�����it1=it2����first = "123a456", second = "123456"
        // 6. (b-2) Խ�������it1>it2��: first = "12344456", second = "1234456"
        string *long_string, *short_string;
        long_string = diff >= 0 ? &first : &second;
        short_string = diff >= 0 ? &second : &first;
        
        auto it1 = long_string -> begin();
        auto it2 = long_string -> end() - 1;

        for (auto c: *short_string)
        {  
            if (*it1 != c )
                break;
            it1++;
        }      
        
        for (int i = short_string->size() - 1; i >= 0; i--, it2--)
            if (*it2 != short_string->at(i))
                break;
                
        return it2 <= it1;
    }
};
