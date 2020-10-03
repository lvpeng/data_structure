/// Created by lvpeng on 09/30/2020.
#include<stdio.h>
#include<stdlib.h>
#include"Stack_IMPL.h"


int main(int argc, char const *argv[])
{
  Stack *s = Init_Stack(&s);
  printf("栈底指针地址: %p\n", s);

  //TOFIX 直接调用`PUSH(s,3)`
  s = Push(s,3);
  s = Push(s,4);

  printf("获取栈顶元素: %d\n", getTop(s));

  printf("pop before: %p\n", s);
  s = Pop(s);
  printf("pop after: %p\n", s);

  printf("栈大小: %d\n", Size(s));
  
  Destroy_Stack(s);
  return 0;
}

