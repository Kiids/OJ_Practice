// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。
// 示例 1:
// 输入: "()"
// 输出: true
// 示例 2:
// 输入: "()[]{}"
// 输出: true
// 示例 3:
// 输入: "(]"
// 输出: false
// 示例 4:
// 输入: "([)]"
// 输出: false
// 示例 5:
// 输入: "{[]}"
// 输出: true

#progma once
typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; 
	int _capacity;
}Stack;

void StackInit(Stack* s);
void StackDestory(Stack* s);

void StackPush(Stack* s, STDataType x);
void StackPop(Stack* s);
STDataType StackTop(Stack* s);
bool StackEmpty(Stack* s);
int StackSize(Stack* s);

void TestStack();

void StackInit(Stack* s)
{
	assert(s);
	s->_a = NULL;
	s->_top = s->_capacity = 0;
}

void StackDestory(Stack* s)
{
	assert(s);
	if (s->_a != NULL)
	{
		free(s->_a);
		s->_a = NULL;
		s->_top = s->_capacity = 0;
	}
}

void StackPush(Stack* s, STDataType x)
{
	assert(s);
	if (s->_top == s->_capacity)
	{
		s->_capacity = (s->_capacity == 0) ? 2 : 2 * s->_capacity;
		s->_a = (STDataType*)realloc(s->_a, sizeof(STDataType)*s->_capacity);
	}
	s->_a[s->_top] = x;
	s->_top++;
}

void StackPop(Stack* s)
{
	assert(s && s->_top > 0);
	s->_top--;
}

STDataType StackTop(Stack* s)
{
	assert(s && s->_top > 0);
	return s->_a[s->_top - 1];
}

bool StackEmpty(Stack* s)
{
	assert(s);
	return s->_top == 0;
}

int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}

bool isValid(char * s){
    Stack st;
    StackInit(&st);
    
    char* symbol[3] = {"()", "[]", "{}"};
    
    while (*s)
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            StackPush(&st, *s);
        }
        else if (*s == ')' || *s == ']' || *s == '}')
        {
            if (StackEmpty(&st))
                return false;
            
            STDataType top = StackTop(&st);
            
            for (int i = 0; i < 3; ++i)
            {
                if (*s == symbol[i][1])
                {
                    if (top != symbol[i][0])
                    {
                        StackDestory(&st);
                        return false;
                    }
                    else
                    {
                        StackPop(&st);
                        break;
                    }
                }
            }
        }
        ++s;
    }
    return StackEmpty(&st);
}

