// ʵ�ֺ��� ToLowerCase()���ú�������һ���ַ������� str���������ַ����еĴ�д��ĸת����Сд��ĸ��֮�󷵻��µ��ַ�����
// ʾ�� 1��
// ����: "Hello"
// ���: "hello"
// ʾ�� 2��
// ����: "here"
// ���: "here"
// ʾ��?3��
// ����: "LOVELY"
// ���: "lovely"

char * toLowerCase(char * str){
    char* ret = str;
	while (*str != '\0')
	{
		if (*str <= 'Z' && *str >= 'A')
			*str += 32;

		str++;
	}
	return ret;
}

