/// Created by lvpeng on 09/30/2020.
#include<stdio.h>
#include<stdlib.h>
#include"Stack_IMPL.h"


int main(int argc, char const *argv[])
{
  Stack *s = Init_Stack(&s);
  printf("s addr: %p\n", s);

  //TOFIX 直接调用`PUSH(s,3)`
  s = Push(s,3);
  printf("s addr: %p\n", s);

  printf("%d\n", Size(s));
  
  s = Push(s,4);
  Pop(s);
  printf("%d\n", Size(s));
  return 0;
}

