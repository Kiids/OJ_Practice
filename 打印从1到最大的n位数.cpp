/*
�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
ʾ�� 1:
����: n = 1
���: [1,2,3,4,5,6,7,8,9]
˵����
�÷���һ�������б��������ӡ
n Ϊ������
*/

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ret;
        if (n == 0)
            return ret;
        
        for (int i = 1; i < pow(10, n); i++)
            ret.push_back(i);

        return ret;
    }
};


// �����ⷨ char��
class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		//����һ�����������ֵ���ַ�����,������һλҪ�洢'\0'�����Ҫ����һ��
		char* number = new char[n + 1];
		//��ʼȫ������Ϊ0
		memset(number, '0', n);
		number[n] = '\0';//��nλ��Ϊ'\0'
		while (!Increment(number))
		{
			PrintNumber(number);
		}
		delete[]number;//ע��Ҫ�ͷ��ڴ�
		return res;
	}
	bool Increment(char* number) {//�βδ���char*ָ��
		bool isOverflow = false;//����Ƿ�Խ��
		int nTakeOver = 0;//�洢��λ
		int nLength = strlen(number);//����Ϊn,����n+1
		for (int i = nLength - 1; i >= 0; i--)
		{
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)
				//����ǵ�һλ����λ
			{
				nSum++;
			}
			if (nSum >= 10)
				//�н�λ
			{
				if (i == 0)
					//��������λ�н�λ��˵�������˸����õ����ֵ��Խ��
				{
					isOverflow = true;
				}
				else//�����λ�н�λ
				{
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';//�Ե�iλ��������
				}
			}
			else//û�н�λ
				//���õ�iλ����
				//��ֱ������ѭ��
			{
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}
	void PrintNumber(char* number)
	//�βδ���char*ָ�룬�˴��ı��β�numberָ���λ�ã�����ʹԭʼ��numberָ����ָλ�øı�
	{
		string s = "";
		bool isBegin0 = true;
		while (*number != '\0')
		{
			if (isBegin0 && *number != '0') isBegin0 = false;
			//����'0'�������
			if (!isBegin0)
			{
				s += *number;
			}
			number++;
		}
		int num = stoi(s);//תΪ����
		res.push_back(num);
	}
};
// �����ⷨstring��
class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		//����һ�����������ֵ���ַ�����
		string number(n, '0');
		//��ʼȫ������Ϊ0
		while (!Increment(number))
		{
			saveNumber(number);
		}
		return res;
	}
	bool Increment(string& number) {
		//ע��Ҫʹ�����ô��ݣ������޷��޸�number
		bool isOverflow = false;//����Ƿ�Խ��
		int nTakeOver = 0;//�洢��λ
		int nLength = number.size();
		for (int i = nLength - 1; i >= 0; i--)
		{
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)
				//����ǵ�һλ����λ
			{
				nSum++;
			}
			if (nSum >= 10)//�н�λ
			{
				if (i == 0)
					//��������λ�н�λ��˵�������˸����õ����ֵ��Խ��
				{
					isOverflow = true;
				}
				else
				{
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';//�Ե�iλ��������
				}
			}
			else//û�н�λ
				//���õ�iλ����
				//��ֱ������ѭ��
			{
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}
	void saveNumber(string number)
		//���ڴ˴����������Ҫ�޸�number����˲���Ҫ������
	{
		string s = "";
		bool isBegin0 = true;
		string::iterator it = number.begin();
		while (it != number.end())
		{
			if (isBegin0 && *it != '0') isBegin0 = false;
			if (!isBegin0)
			{
				s += *it;
			}
			it++;
		}
		int num = stoi(s);
		res.push_back(num);
	}
};
// �ݹ�ⷨ
class Solution
{
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		string number(n, '0');
		for (int i = 0; i <= 9; i++)
		//�Ӹ�λ����λ����ȫ����
		{
			number[0] = i + '0';//���ַ�����ֵ
			permutationNumbers(number, n, 1);//������һλ
		}
		return res;
	}
	//������ȫ����
	void permutationNumbers(string& number, int length, int index) {
		if (index == length) {//�ݹ�߽�
			saveNumber(number);//�洢���
			return;
		}
		else
		{
			for (int i = 0; i <= 9; i++)
			{
				number[index] = '0' + i;//���õ�indexλ���ַ�
				permutationNumbers(number, length, index + 1);
			}
		}
	}
	//�洢���
	//ֻ�ܴ洢ǰ����0������
	void saveNumber(string number) {
		bool isBegin0 = true;
		string tempStr = "";
		string::iterator it = number.begin();
		while (it != number.end())
		{
			if (isBegin0 && *it != '0') isBegin0 = false;
			if (!isBegin0) {
				tempStr += *it;
			}
			it++;
		}
		//�Ӹ�λ����λȫ���У�Ҫע�����ַ�Ϊ0ʱ��tempStrΪ�գ�����ִ��stoi
		if (tempStr != "") {
			int tempNum = stoi(tempStr);
			res.push_back(tempNum);
		}
	}
};
