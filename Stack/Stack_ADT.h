/// Created by lvpeng on 09/28/2020.
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define ElementType int
#define Status int
/*
** 声明链栈抽象数据
*/
typedef struct _node
{
  ElementType data;
  struct _node *next;
} node, *Stack;

typedef struct
{
  int size;
  Stack top;//头结点指针
} StackList;

/*
** 构造一个空栈
*/
StackList
*Init_Stack();

/*
** 入栈
*/
Status
Push(StackList *S, ElementType e);

/*
** 出栈
*/
Status
Pop(StackList *S);

/*
** 获取栈顶元素
*/
ElementType
getTop(StackList *S);

/*
** 栈大小
*/
int
Size(StackList *S);

/*
** 销毁
*/
void
Destroy_Stack(StackList *S);