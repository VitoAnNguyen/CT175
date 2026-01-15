#include<stdio.h>
#define max 100

typedef struct{
	int x,y;
}Edge;

typedef struct{
	int n,m;
	Edge edges[max];
}Graph;

void init_Graph(Graph *G, int n){
	G->n=n;
	G->m=0;
}

void add_Edge(Graph *G, int x, int y){
	G->edges[G->m].x=x;
	G->edges[G->m].y=y;
	G->m++;	
}

int adjacent(Graph *G, int x, int y){
	for(int i=0;i<G->m;i++){
		if((G->edges[i].x==x && G->edges[i].y==y)|| (G->edges[i].x==y && G->edges[i].y==x)){
		    return 1;
		}	
	}
	return 0;	
}

int degree(Graph *G, int x){
	int e, deg=0;
	for(e=0;e<G->m;e++){
		if(G->edges[e].x==x)deg++;
		if(G->edges[e].y==x)deg++;
	}
	return deg;
}

void neighbours(Graph *G, int u){
	int v;
	for(v=1; v<G->n; v++){
		if(adjacent(G,u,v)!=0){
			printf("%d ",v);
			printf("\n");
		}
	}
}

int main(){
	Graph G;
	int x,y,e;
	int u,v;
	freopen("dothi.txt", "r", stdin);
	scanf("%d %d", &x,&y);
	init_Graph(&G,x);
	for(e=1;e<=y;e++){
		scanf("%d%d",&u,&v);
		add_Edge(&G,u,v);
	}
	int i,j;
	for (i=1;i<=G.n;i++){
		printf("Degree(%d): %d\n", i, degree(&G, i));
	}
	printf("--------------------------------------\n");
	int a;
	for(a=1;a<=G.n;a++)
		for(j = 1; j <=G.n; j++){
			if(adjacent(&G,a,j)==1){
				printf("%d ke %d \n",a,j);
			}
			else{
				printf("%d khong ke %d \n",a,j);
			}
		}
		printf("---------------------\n");
			for(i=1;i<=G.n;i++){
				printf("Neighbours cua %d la: ", i);
				neighbours(&G, i);
				printf("\n");
			}
		return 0;	
	}
