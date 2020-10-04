#include "Stack_ADT.h"

/*
** 初始化
** param: **S Stack型指针的指针, 也就是 &(*S)
** 返回值: 栈顶指针
*/
StackList
*Init_Stack()
{
  StackList *s = (StackList *)malloc(sizeof(StackList));
  s->top=NULL;
  s->size=0;
  return s;
};

/*
** 入栈
** 初始条件: 栈S已存在
** @param S: Stack型指针
** @param e: 入栈元素
** 返回值: 栈顶指针
** 操作结果: 插入元素e为新的栈顶元素
*/
Status
Push(StackList *S, ElementType e)
{
  if (S != NULL)
  {
    //创建新结点
    Stack sp = (Stack)malloc(sizeof(Stack));
    if(!sp) return ERROR;
    //** Key Point **
    sp->data = e;
    sp->next = S->top;//头指针
    S->top = sp;
    S->size +=1;
  }
  return OK;
};

/*
** 出栈
** 参数 {
** S: Stack型指针,指向栈顶
** }
** 初始条件: 栈S已存在 且「非空」
** 操作结果: 删除S的栈顶元素，返回结果Status
*/
Status
Pop(StackList *S)
{
  if(S == NULL) return ERROR;
  if(S->size==0) return OVERFLOW;

  Stack tmp = S->top;
  S->top = S->top->next;
  S->size -=1;
  free(tmp);
  
  return OK;
};

/*
** 获取栈顶元素
** @param {Stack *S} S
** 初始条件: 栈S已存在 且「非空」
** 操作结果: 返回栈顶元素e
*/
ElementType
getTop(StackList *S)
{
  if (S == NULL)
  {
    return ERROR;
  }
  if (S->top == NULL)
  {
    return OVERFLOW;
  }
  ElementType e = S->top->data;
  return e;
};
/*
** 栈大小
*/
int
Size(StackList *S)
{
  if (S==NULL) return ERROR;

  int _size = 0;

  while (S->top != NULL)
  {
    S->top = S->top->next;
    _size += 1;
  }
  return _size;
}

/*
** 销毁栈
*/
void
Destroy_Stack(StackList *S)
{
  Stack tmp;
  while (S->top)
  {
    tmp = S->top;
    S->top = S->top->next;
    free(tmp);
  }
  free(S);
  S=NULL;

  return;
}
