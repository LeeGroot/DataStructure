#include<stdio.h>
#include<stdlib.h>
struct PolyNode{
	int coef;
	int expon;
	struct PolyNode *link;
};

typedef struct PolyNode *Polynomial;

Polynomial polyAdd(Polynomial p1,Polynomial p2);
Polynomial readPoly();
void moveNext(Polynomial *p);
void insert(int coef,int expon,Polynomial *rear);
void printPoly(Polynomial *p);

void main(){
	Polynomial p1,p2,p3;
	p1 = readPoly();
	p2 = readPoly();
	p3 = polyAdd(p1,p2);
	printPoly(&p3);
}

void insert(int coef,int expon,Polynomial *rear){
	Polynomial t = (Polynomial)malloc(sizeof(struct PolyNode));
	t->coef = coef;
	t->expon = expon;
	t->link = NULL;
	(*rear)->link = t;
	*rear = t;

}

Polynomial readPoly(){
	int n,c,e;
	Polynomial p,rear;
	p = (Polynomial)malloc(sizeof(struct  PolyNode));
	p->link = NULL;
	rear = p;
	printf("请输入多项式的项数：");
	scanf("%d",&n);
	printf("\n");

	while(n){
		printf("请输入第%d项的系数、指数：",n);
		scanf("%d %d",&c,&e);
		insert(c,e,&rear);
		n--;
	}

	return p;
}

Polynomial polyAdd(Polynomial p1,Polynomial p2){
	Polynomial p,rear;
	p=(Polynomial)malloc(sizeof(struct PolyNode));
	p->link = NULL;
	rear = p;
	moveNext(&p1);
        moveNext(&p2);
	while(p1&&p2){
		if(p1->expon==p2->expon){
			if(p1->coef + p2->coef){
				insert(p1->coef + p2->coef,p1->expon,&rear);
				moveNext(&p1);
                                moveNext(&p2);
			}else{
				moveNext(&p1);
				moveNext(&p2);
			}
		}else if(p1->expon > p2->expon){
			insert(p1->coef,p1->expon,&rear);
			moveNext(&p1);
		}else{
			insert(p2->coef,p2->expon,&rear);
			moveNext(&p2);
		}
	}
	if(!p1){
		rear->link = p2;
	}
	if(!p2){
		rear->link = p1;
	}
	return p;
}

void moveNext(Polynomial *p){
	Polynomial t=(Polynomial)malloc(sizeof(struct PolyNode));
	t = *p;
        *p = t->link;
        free(t);

}

void printPoly(Polynomial *p){
	moveNext(p);
	while((*p)){
                printf("%d %d+",(*p)->coef,(*p)->expon);
		moveNext(p);
        }
        printf("\n");
}
