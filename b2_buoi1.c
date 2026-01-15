#include<stdio.h>
#define max 100
#define max_e 100

typedef struct{
    int A[max_e][max_e];
    int n,m;
}Graph;

void init_Graph(Graph *G, int n){
    int i,j;
    G->n=n;
    for(i=1;i<=G->n;i++){
        for(j=1;j<=G->n;j++){
            G->A[i][j]=0;
        }
    }
}

void add_Edge(Graph *G,int x,int y){
    G->A[x][y]=1;
    G->A[y][x]=1;
}

int adjacent(Graph G, int x, int y){
    return G.A[x][y]==1;
}
int degree(Graph *G, int x){
	int i;
	int deg=0;
	for(i=1;i<=G->n;i++){
		if(G->A[x][i]==1)
			deg++;	
	}
	return deg;
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
		printf("Degree(%d): %d\n", i, degree(&G,i ));
	}
	printf("--------------------------------------\n");
	int a;
	for(a=1;a<=G.n;a++)
		for(j = 1; j <=G.n; j++){
			if(adjacent(G,a,j)==1){
				printf("%d ke %d \n",a,j);
			}
			else{
				printf("%d khong ke %d \n",a,j);
			}
		}
		/*printf("---------------------\n");
			for(i=1;i<=G.n;i++){
				printf("Neighbours cua %d la: ", i);
				neighbours(&G, i);
				printf("\n");
			}*/
		return 0;
}
