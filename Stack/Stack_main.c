/// Created by lvpeng on 09/30/2020.
#include<stdio.h>
#include<stdlib.h>
#include"Stack_IMPL.h"


int main(int argc, char const *argv[])
{
  StackList *s = Init_Stack();
  printf("stacklist pointer: %p\n", s);
  printf("stack top pointer: %p\n", s->top);
  Push(s,3);
  printf("stack top pointer: %p\n", s->top);
  Push(s,4);
  printf("stack top pointer: %p\n", s->top);
  
  printf("stack top elem: %d\n", getTop(s));

  printf("pop before: %p\n", s->top);
  Pop(s);
  printf("pop  after: %p\n", s->top);

  printf("stack size: %d\n", Size(s));
  
  Destroy_Stack(s);
  return 0;
}

