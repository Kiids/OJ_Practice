// ��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢����
// �������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������

#include <stdio.h>
#include <malloc.h>
 
typedef struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}Node;
 
Node* CreateTree(char* a, int* i)
{
    if (a[*i] == '#')
        return NULL;
     
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = a[*i];
    ++(*i);
     
    node->left = CreateTree(a, i);
    ++(*i);
     
    node->right = CreateTree(a, i);
     
    return node;
}
 
void inOrder(Node* root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%c ", root->val);
    inOrder(root->right);
}
 
int main()
{
    char str[100];
    scanf("%s", str);
    int i = 0;
    Node* Tree = CreateTree(str, &i);
    inOrder(Tree);
    return 0;
}

