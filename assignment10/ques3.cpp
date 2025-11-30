#include <cstdio>

#define MAX 50

int vertexCount;
int graph[MAX][MAX];
int visited[MAX];

void dfs(int currentVertex){
    visited[currentVertex] = 1;
    printf("%d ", currentVertex);

    for(int i = 0; i < vertexCount; i++){
        if(graph[currentVertex][i] == 1 && !visited[i]){
            dfs(i);
        }
    }
}

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &vertexCount);

    for(int i = 0; i < vertexCount; i++){
        for(int j = 0; j < vertexCount; j++){
            graph[i][j] = 0;
        }
    }

    int edgeCount;
    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);

    int fromVertex, toVertex;
    for(int i = 0; i < edgeCount; i++){
        scanf("%d %d", &fromVertex, &toVertex);
        graph[fromVertex][toVertex] = 1;
        graph[toVertex][fromVertex] = 1;
    }

    for(int i = 0; i < vertexCount; i++){
        visited[i] = 0;
    }

    int startVertex;
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    dfs(startVertex);
    printf("\n");
}
