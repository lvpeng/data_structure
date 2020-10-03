#include "Stack_ADT.h"

/*
** 初始化
** param: **S Stack型指针的指针, 也就是 &(*S)
** 返回值: 栈顶指针
*/
struct Stack *
Init_Stack(Stack **S)
{
  *S = (Stack *)malloc(sizeof(Stack));//头指针
  (*S)->next = NULL;//头结点的指针域
  return *S;
};

/*
** 入栈
** 初始条件: 栈S已存在
** @param S: Stack型指针
** @param e: 入栈元素
** 返回值: 栈顶指针
** 操作结果: 插入元素e为新的栈顶元素
*/
Stack
*Push(Stack *S, ElementType e)
{
  if (S != NULL)
  {
    //创建新结点
    struct Stack *_sp = (Stack *)malloc(sizeof(Stack));
    if(!_sp) return NULL;
    //** Key Point **
    _sp->data = e;
    _sp->next = S;
    S = _sp;
  }
  return S;
};

/*
** 出栈
** 参数 {
** S: Stack型指针,指向栈顶
** }
** 初始条件: 栈S已存在 且「非空」
** 操作结果: 删除S的栈顶元素，返回结果Status
*/
Stack
*Pop(Stack *S)
{
  if(S == NULL || Size(S) == 0) return S; 
  Stack *tmp = S;
  S = S->next;
  free(tmp);
  
  return S;
};

/*
** 获取栈顶元素
** @param {Stack *S} S
** 初始条件: 栈S已存在 且「非空」
** 操作结果: 返回栈顶元素e
*/
ElementType
getTop(Stack *S)
{
  if (S == NULL)
  {
    return ERROR;
  }
  if (S->next == NULL)
  {
    return OVERFLOW;
  }
  ElementType e = S->data;
  return e;
};
/*
** 栈大小
*/
int
Size(Stack *S)
{
  if (S==NULL) return ERROR;

  int _size = 0;
  while (S->next != NULL)
  {
    S = S->next;
    _size += 1;
  }
  return _size;
}

/*
** 销毁栈
*/
void Destroy_Stack(Stack *S)
{
  Stack *tmp;
  while (S->next)
  {
    tmp = S;
    S = S->next;
    free(tmp);
  }
  free(S);
  S=NULL;
  
  return;
}
