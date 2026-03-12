#include<stdio.h>
#define MAX_N 100
#define NO_EDGE -1
typedef struct{
    int A[MAX_N][MAX_N];
    int n,m, k;
}Graph;

void init_graph(Graph *pG, int n){
    pG->n=n;
    pG->m=0;
    int u,v;
    for(u=1;u<=n;u++){
        for(v=1;v<=n;v++){
            pG->A[u][v]=NO_EDGE;
        }
    }
}

void add_edge(Graph *pG, int u, int v, int w){
    pG->A[u][v]=w;
    pG->A[v][u]=w;
    pG->m++;
}

#define oo 999999999
int pi[MAX_N], p[MAX_N], mark[MAX_N];

int Prim(Graph *pG, Graph *pT, int x){
    int u,v,i;
    int a,b;
	printf("nhap u,v (con duong dang sua) : ");
	scanf("%d%d",&a,&b);
    for(u=1;u<=pG->n;u++){
        mark[u]=0;
        pi[u]=oo;
        p[u]=-1;
    }
    pi[x]=0;

    for(i=1;i<=pG->n;i++){
        int min_dist=oo;
        for(v=1;v<=pG->n;v++)
            if(mark[v]==0 && pi[v]<min_dist){
                min_dist=pi[v];
                u=v;
            }
        mark[u]=1;

        for(v=1;v<=pG->n;v++)
            if(pG->A[u][v]!=NO_EDGE && mark[v]==0 && !((u==a&&v==b)||(u==b&&v==a)))
                if(pG->A[u][v]<pi[v]){
                    pi[v]=pG->A[u][v];
                    p[v]=u;
                }
    } 
	
    init_graph(pT,pG->n);
    int sum_w=0;
   
    for(u=1;u<=pG->n;u++)
        if(p[u]!=-1){
        		add_edge(pT, p[u],u,pG->A[p[u]][u]);
            	sum_w += pG->A[p[u]][u];
        }
    return sum_w;
}

int main(){
    Graph G,T;
    int n,m,u,v,w,e,k,a,b;
    FILE *f = fopen("Kruscal_dt_130.txt","r");
//  FILE *f = fopen("Kruscal_dt_163.txt","r");
	printf("nhap k: ");
	scanf("%d",&k);
	fscanf(f,"%d%d",&n,&m);
    init_graph(&G,n);
    for(e=1;e<=m;e++){
        fscanf(f,"%d%d%d", &u, &v,&w);
        if(w>=k)
        	add_edge(&G,u,v,w);
    }

    int sum = Prim(&G,&T,1);
    printf("Cay khung co trong so nho nhat la %d", sum);
    for(u=1;u<=T.n;u++)
    	for(v=u+1;v<=T.n;v++)
        	if(T.A[u][v]!=NO_EDGE)
            	printf("\n %d %d", u,v,T.A[u][v]);

    fclose(f);
    return 0;
}
