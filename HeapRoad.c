#include<stdio.h>
/*堆中的路径:
 将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标‘i’,打印从H[i]到根节点的路径
 */
#define MaxN 1001
#define MinH -10001

int H[MaxN],size;
void Create(){
  size = 0;
  H[0] = MinH;
}

void Insert(int x){
  int i;
  for(i=++size;H[i/2]>x;i /= 2){
    H[i] = H[i/2];
  }
  H[i] = x;
}

int main(){
  int n,m,x,i,j;
  //n:堆中元素个数
  //m:查询次数
  //j:查询下标
  scanf("%d %d",&n,&m);
  Create();
  for(i=0;i<n;i++){
    scanf("%d",&x);
    Insert(x);
  }

  for(i=0;i<m;i++){
    scanf("%d",&j);
    printf("%d ",H[j]);
    while(j>1){
      j /= 2;
      printf("%d ",H[j]);
    }

    printf("\n");

  }

  return 0;
}
