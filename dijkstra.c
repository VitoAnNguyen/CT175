#include<stdio.h>
#define INF 999999
#define MAX 100

typedef struct{
    int L[MAX][MAX];
    int n,m;
}Graph;

void initGraph(Graph *pG, int n){
    pG->n=n;
    pG->m=0;
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            pG->L[i][j]=INF;
        }
    }
}

void addEdge(Graph *pG, int u, int v, int w){
    pG->L[u][v]=w;
    pG->m++;
}

#define NO_EDGE -1
int mark[MAX];
int pi[MAX];
int p[MAX];

void dijkstra(Graph *pG, int s){
    int i,j,e;
    for(i=1;i<=pG->n;i++){
        pi[i]=INF;
        mark[i]=0;
    }
    pi[s]=0;
    p[s]=-1;
    for(e=1;e<pG->n;e++){
        int min_pi=INF;
        for(j=1;j<=pG->n;j++){
            if(mark[j]==0 && pi[j]<min_pi){
                min_pi=pi[j];
                i=j;
            }
        }

        mark[i]=1;
        for(j=1;j<=pG->n;j++){
            if(pG->L[i][j]!=NO_EDGE && mark[j]==0){
                if(pi[i]+pG->L[i][j]<pi[j]){
                    pi[j]=pi[i]+pG->L[i][j];
                    p[j]=i;
                }
            }
        }
    }
}

void track(int i){
    int path[MAX];
    path[0]=i;
    int count=1;
    int j=i;
    while(p[j]!=-1){
        path[count]=p[j];
        count++;
        j=p[j];
    }
    for(int j=count-1;j>0;j--){
        printf("%d->",path[j]);
    }
        printf("%d: %d\n", i, pi[i]);
}

int main(){
    freopen("D:/dothidijkstra.txt","r",stdin);
    int n,m;
    scanf("%d %d",&n,&m);
    Graph G;
    initGraph(&G,n);
    int i;
    for(i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        addEdge(&G,u,v,w);
    }
    dijkstra(&G,1);
    for(i=1;i<=G.n;i++){
        printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
        track(i);
    }
}
