#include <cstdio>

#define MAX 50

struct Edge {
    int fromVertex;
    int toVertex;
    int weight;
};

int vertexCount, edgeCount;
Edge edges[MAX];
int parentArr[MAX];

int findParent(int v){
    if(parentArr[v] == v) return v;
    return parentArr[v] = findParent(parentArr[v]);
}

void unionSet(int a, int b){
    a = findParent(a);
    b = findParent(b);
    parentArr[b] = a;
}

void sortEdges(){
    for(int i = 0; i < edgeCount - 1; i++){
        for(int j = 0; j < edgeCount - i - 1; j++){
            if(edges[j].weight > edges[j+1].weight){
                Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &vertexCount);

    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);

    for(int i = 0; i < edgeCount; i++){
        scanf("%d %d %d", &edges[i].fromVertex, &edges[i].toVertex, &edges[i].weight);
    }

    for(int i = 0; i < vertexCount; i++){
        parentArr[i] = i;
    }

    sortEdges();

    int mstWeight = 0;
    printf("MST edges:\n");

    for(int i = 0; i < edgeCount; i++){
        int p1 = findParent(edges[i].fromVertex);
        int p2 = findParent(edges[i].toVertex);

        if(p1 != p2){
            printf("%d - %d ( %d )\n", edges[i].fromVertex, edges[i].toVertex, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSet(p1, p2);
        }
    }

    printf("Total MST weight: %d\n", mstWeight);
}
