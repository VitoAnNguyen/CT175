#include <stdio.h>
#define length 100
typedef struct{
    int data[length];
    int size;
}List;

void makenull_List(List *L){
    L->size=0;
}

int empty_List(List *L){
    return L->size==0;
}

int element_at(List *L, int i){
    return L->data[i-1];
}

void push_back(List *L, int x){
    if(L->size+1==length){
        return;
    }
    L->data[L->size]=x;
    L->size++;
}

void copy_List(List *L1, List *L2){
    makenull_List(L1);
    if(empty_List(L2)){
        return;
    }
    int i;
    for(i=1;i<=L2->size;i++){
        push_back(L1, element_at(L2,i));
    }
}

#define MAX 100

typedef struct{
    int A[MAX][MAX];
    int n,m;
}Graph;

void init_graph(Graph *G, int n){
    G->n=n;
    G->m=0;
    int u,v;
    for(u=1;u<=n;u++){
        for(v=1;v<=n;v++){
            G->A[u][v]=0;
        }
    }
}

void initGraph(Graph *pG, int n){
    pG->n=n;
    pG->m=0;
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            pG->A[i][j]=0;
        }
    }
}

void addEdge(Graph *pG, int u, int v){
    pG->A[u][v]=1;
    pG->m++;
}

int r[MAX];

void rank(Graph *G){
    int u,v,d[MAX];
    for(u=1;u<=G->n;u++){
        d[u]=0;
        for(v=1;v<=G->n;v++)
            if(G->A[v][u]>0)
                d[u]++;
    }
List L1, L2;
makenull_List(&L1);
for (u=1;u<=G->n;u++)
    if(d[u]==0){
        push_back(&L1,u);
    }
    int k=0,i;
    while(!empty_List(&L1)){
        makenull_List(&L2);
        for(i=1;i<=L1.size;i++){
            u=element_at(&L1,i);
            r[u]=k;

            for(v=1;v<=G->n;v++)
                if(G->A[u][v]>0){
                    d[v]--;
                    if(d[v]==0)
                        push_back(&L2,v);
                }
        }
        copy_List(&L1,&L2);
        k++;
    }
}

int main(){
    Graph G;
    int n,m,u,v,e;
    FILE *f=fopen("D:/dothixephang.txt","r");
    fscanf(f,"%d%d",&n,&m);
    init_graph(&G,n);
    for(e=1;e<=m;e++){
        fscanf(f,"%d%d",&u,&v);
        addEdge(&G,u,v);
    }
    rank(&G);

    printf("Xep hang dinh cua do thi:\n");
    for(u=1;u<=G.n;u++){
        printf("rank[%d] = %d\n",u,r[u]);
    }
    fclose(f);
    return 0;
}
