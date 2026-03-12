#include<stdio.h>
#define MAX_N 100
#define NO_EDGE -1

typedef struct{
    int u,v,w;
}Edge;

typedef struct{
    Edge edges[MAX_N];
    int n,m;
}Graph;

void init_graph(Graph *pG, int n){
    pG->n=n;
    pG->m=0;
}

void add_edge(Graph *pG, int u, int v, int w){
    pG->edges[pG->m].u=u;
    pG->edges[pG->m].v=v;
    pG->edges[pG->m].w=w;
    pG->m++;
}

int parent[MAX_N];

int findRoot(int u){
    if(parent[u]==u)
        return u;
    else return findRoot(parent[u]);
}

int Kruscal(Graph *pG, Graph *pT){
    int u,v,w,e;
    for(u=0;u<pG->m;u++)
        for(v=u+1;v<pG->m;v++)
            if(pG->edges[u].w > pG->edges[v].w){
                Edge t = pG->edges[u];
                pG->edges[u]=pG->edges[v];
                pG->edges[v]=t;
            }
    
    init_graph(pT,pG->n);
    for(u=1;u<=pG->n;u++)
        parent[u]=u;
    int sum_w=0;

    for(e=0;e<pG->m;e++){
        u=pG->edges[e].u;
        v=pG->edges[e].v;
        w=pG->edges[e].w;

        int root_u=findRoot(u), root_v=findRoot(v);

        if(root_u!=root_v){
            add_edge(pT,u,v,w);
            parent[root_v]=root_u;
            sum_w +=w;
        }
    }
    return sum_w;
}




int main(){
    Graph G,T;
    int n,m,u,v,w,e;
    FILE *f = fopen("Kruscal_dt_130.txt","r");
//  FILE *f = fopen("Kruscal_dt_163.txt","r");
	fscanf(f,"%d%d",&n,&m);
    init_graph(&G,n);

    for(e=1;e<=m;e++){
        fscanf(f,"%d%d%d", &u, &v,&w);
        	add_edge(&G,u,v,w);
    }

    int sum = Kruscal(&G,&T);
    printf("Cay khung co trong so nho nhat la %d", sum);
    for(e=0;e<T.m;e++)
        printf("\n %d %d %d",T.edges[e].u,T.edges[e].v,T.edges[e].w);
    fclose(f);
    return 0;
}
