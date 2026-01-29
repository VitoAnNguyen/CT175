#include<stdio.h>
#define Max_Length 20

typedef struct{
	int u,v;
}edge;

typedef struct{
	int n,m;
	edge data[Max_Length];
}graph;

typedef struct{
	int size;
	int data[Max_Length];
}List;

void makeNull(List *pL){
	pL->size=0;
}

int elementAt(List *pL, int x){
	return pL->data[x];
}

void pushList(List *pL, int x){
	pL->data[pL->size]=x;
	pL->size++;
}

void initGraph(graph *pG,int n){
	pG->n=n;
	pG->m=0;
	printf("do thi G duoc khoi tao so voi so dinh n=%d va so m=%d\n", pG->n,pG->m);
}

void addEdge(graph *pG, int u, int v){
	for(int i=0;i<pG->m;i++){
		if((pG->data[i].u==u && pG->data[i].v==v) ||(pG->data[i].u==v && pG->data[i].v==u)){
			printf("Canh da co trong do thi!");
			return;
		}
	}
	pG->data[pG->m].u=u;
	pG->data[pG->m].v=v;
	pG->m++;
	printf("do thi da them vao canh %d %d\n",pG->data[pG->m-1].u,pG->data[pG->m-1].v);
}

int adjacent(graph *pG, int u, int v){
	for(int i=0;i<pG->m;i++){
		if((pG->data[i].u==u && pG->data[i].v==v) ||(pG->data[i].u==v && pG->data[i].v==u)){
			return 1;
		}
	}
	return 0;
}

void degree(graph *pG, int x){
	int count=0;
	for(int i=0;i<=pG->m;i++){
		if(adjacent(pG,x,i)){
			count++;
		}
	}
	printf("bac cua canh %d la:%d \n",x,count);
}

List neighbors(graph *pG, int x){
	List listVertex;
	makeNull(&listVertex);
	for(int i=1;i<=pG->n;i++){
		if(adjacent(pG,x,i)==1){
			pushList(&listVertex,i);
		}
	}
	return listVertex;
}

//stack

typedef struct{
	int data[100];
	int size;
}Stack;

void makenullStack(Stack *pS){
	pS->size=0;
}

void push(Stack *pS, int x){
	pS->data[pS->size]=x;
	pS->size++;
}

void pop(Stack *pS){
	pS->size--;
}

int top(Stack S){
	return S.data[S.size-1];
}

int empty(Stack S){
	return S.size==0;
}

//Queue
typedef struct{
	int data[100];
	int front,rear;
}Queue;

void makenullQuene(Queue *pQ){
	pQ->front=0;
	pQ->rear=-1;
}

void pushQ(Queue *pQ, int x){
	pQ->rear++;
	pQ->data[pQ->rear]=x;
}

int topQ(Queue Q){
	return Q.data[Q.front];
}

void popQ(Queue *pQ){
	pQ->front++;
}

int emptyQ(Queue Q){
	return Q.front>Q.rear;
}

void dept_first_search(graph *pG){
	printf("\nDuyet DFS:\n");
	Stack S;
	int mark[100];
	makenullStack(&S);//tao danh sach rong, tao bien mark de danh dau
	for(int i=1;i<=pG->n;i++){
        mark[i]=0;
	}//duyet tung phan tu nut (tu 1 toi n)

	for(int i=1;i<=pG->n;i++){
        if(mark[i]==0){ //neu nut chua danh dau
            push(&S,i); //them nut do vao stack
            while(!empty(S)){ //khi danh sach ko rong (1)
                int x=top(S); //cho x la dau stack
                pop(&S); //xoa x do di
                if(mark[x]!=0)continue; //neu da danh dau lap lai vong lap while(1)
                printf("Duyet %d\n",x);
                mark[x]=1; //da duyet x xong, danh =1
                List L=neighbors(pG,x); //lay cac nut lan can
                for(int i=0;i<L.size;i++){  //duyet tung phan tu danh sach de chuan bi
                    int e=elementAt(&L,i);//gia tri phan tu cac List tai vi tri
                    push(&S,e); //day cac phan tu vao stack
                }
            }
            printf("\n");
        }
	}
}

void breath_first_search(graph *pG){
    printf("\nDuyet BFS:\n");
    Queue Q;
    int mark[100];
    makenullQuene(&Q);

    int i,j;
    for(i=1;i<=pG->n;i++){
        mark[i]=0;
    }

    for(j=1;j<=pG->n;j++){
        if(mark[j]==0){
            pushQ(&Q,j);
            printf("Duyet %d\n",j);
            mark[j]=1;
            while(!emptyQ(Q)){
                int x=topQ(Q);
                popQ(&Q);
                List L=neighbors(pG,x);
                for(i=0;i<L.size;i++){
                    int e=elementAt(&L,i);
                    if(mark[e]==0){
                        printf("Duyet %d\n",e);
                        mark[e]=1;
                        pushQ(&Q,e);
                    }
                }
            }
            printf("\n");
        }
    }
}

int main(int argc, char const *argv[]){
    freopen("dothi.txt","r",stdin);
    int n, m, u,v,i,j;
    scanf("%d%d",&n,&m);
    graph G;
    initGraph(&G,n);
    for(i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        addEdge(&G,u,v);
    }
    for(i=1;i<=n;i++){
        degree(&G,i);
    }
    for(i=1;i<=n;i++){
        List L=neighbors(&G,i);
        printf("neighbor(%d): ",i);
        for(j=0;j<L.size;j++){
            printf("%d ",elementAt(&L,j));
        }
        printf("\n");
    }
    dept_first_search(&G);
    breath_first_search(&G);
    return 0;
}


