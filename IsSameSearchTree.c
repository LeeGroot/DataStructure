#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode *Tree;
struct TreeNode {
  int v;
  Tree Left,Right;
  int flag;
};

Tree MakeTree(int n);
Tree NewNode(int v);
Tree Insert(Tree T,int v);
int Judge(Tree T,int n);
int check(Tree T,int v);
void ResetFlag(Tree T);
void FreeTree(Tree T);
void main(){
  int N,L,i;
  Tree T;
  printf("搜索树的长度：");
  scanf("%d",&N);

  while(N){
    printf("要比较序列的个数：");
    scanf("%d",&L);
    T = MakeTree(N);
    for(i = 0;i<L;i++){
      if(Judge(T,N)) printf("Yes\n");
      else printf("No\n");
      ResetFlag(T);
    }
    FreeTree(T);
    printf("搜索树的长度：");
    scanf("%d",&N);
  }
}

Tree MakeTree(int n){
  Tree T;
  int i,v;
  scanf("%d",&v);
  T = NewNode(v);
  for(i = 1;i<n;i++){
    scanf("%d",&v);
    T = Insert(T,v);
  }
  return T;
}

Tree NewNode(int v){
  Tree T = (Tree)malloc(sizeof(struct TreeNode));
  T->flag = 0;
  T->Left = NULL;
  T->Right = NULL;
  T->v = v;
  return T;
}

Tree Insert(Tree T,int v){
  if(!T) T = NewNode(v);
  else{
    if(v>T->v) 
      T->Right = Insert(T->Right,v);
    else 
      T->Left = Insert(T->Left,v);
  }
  return T;
}

int Judge(Tree T,int n){
  int i,v,flag;
  flag = 0;
  scanf("%d",&v);
  if(v != T->v) flag = 1;
  else T->flag = 1;

  for(i = 1;i<n;i++){
    scanf("%d",&v);
    if((!check(T,v))&&(!flag)) flag = 1;
  }

  return !flag;

}

int check(Tree T,int v){
  if(T->flag){
    if(v>T->v) return check(T->Right,v);
    else if(v<T->v) return check(T->Left,v);
    else return 0;
  }else{
    
    if(v == T->v){
      T->flag = 1;
      return 1;
    }
    else 
      return 0;
  }
}

void ResetFlag(Tree T){
  if(T->Left) ResetFlag(T->Left);
  if(T->Right) ResetFlag(T->Right);
  T->flag = 0;
}

void FreeTree(Tree T){
  if(T->Left) FreeTree(T->Left);
  if(T->Right) FreeTree(T->Right);
  free(T);
}

