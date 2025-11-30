#include <cstdio>

#define MAX 50

int vertexCount;
int graph[MAX][MAX];
int queueArr[MAX];
int frontIndex = 0;
int rearIndex = 0;
int visited[MAX];

void enqueue(int value){
    queueArr[rearIndex++] = value;
}

int dequeue(){
    return queueArr[frontIndex++];
}

int isQueueEmpty(){
    return frontIndex == rearIndex;
}

void bfs(int startVertex){
    for(int i = 0; i < vertexCount; i++){
        visited[i] = 0;
    }

    enqueue(startVertex);
    visited[startVertex] = 1;

    while(!isQueueEmpty()){
        int current = dequeue();
        printf("%d ", current);

        for(int i = 0; i < vertexCount; i++){
            if(graph[current][i] == 1 && !visited[i]){
                visited[i] = 1;
                enqueue(i);
            }
        }
    }

    printf("\n");
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

    int startVertex;
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    bfs(startVertex);
}
