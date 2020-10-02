/// Created by lvpeng on 09/28/2020.
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define ElementType int
#define Status int
/*
** 声明链栈抽象数据
*/
typedef struct Stack
{
  ElementType data;
  struct Stack *next;
} Stack, *StackList;

/*
** 构造一个空栈
*/
struct Stack *
Init_Stack(Stack **S);

/*
** 入栈
*/
Stack
*Push(Stack *S, ElementType e);

/*
** 出栈
*/
Status
Pop(Stack *S);

/*
** 获取栈顶元素
*/
ElementType
getTop(Stack *S);

/*
** 栈大小
*/
int
Size(Stack *S);

/*
** 销毁
** 参数 {
** *S: Stack型指针的
** }
*/
void
Destroy_Stack(Stack *S);