#include <stdio.h>
#include <stdlib.h>

int f91(int n){
  if(n>=101){
    return n - 10;
  }else{
    return f91(f91(n+11));
  }
}

int main(){
  int n;
  scanf("%d", &n);
  while(n){
    printf("f91(%d)=%d\n",n,f91(n));
    scanf("%d", &n);
  }
  return 0;
}
