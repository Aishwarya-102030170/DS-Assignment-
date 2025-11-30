#include <cstdio>

#define MAX 50
#define INF 999999

int vertexCount;
int graph[MAX][MAX];
int distanceArr[MAX];
int visited[MAX];

int findMin(){
    int minValue = INF;
    int minIndex = -1;
    for(int i = 0; i < vertexCount; i++){
        if(!visited[i] && distanceArr[i] < minValue){
            minValue = distanceArr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &vertexCount);

    for(int i = 0; i < vertexCount; i++){
        for(int j = 0; j < vertexCount; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    for(int i = 0; i < vertexCount; i++){
        distanceArr[i] = INF;
        visited[i] = 0;
    }

    distanceArr[startVertex] = 0;

    for(int k = 0; k < vertexCount - 1; k++){
        int u = findMin();
        visited[u] = 1;

        for(int v = 0; v < vertexCount; v++){
            if(graph[u][v] && !visited[v] && distanceArr[u] + graph[u][v] < distanceArr[v]){
                distanceArr[v] = distanceArr[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances:\n");
    for(int i = 0; i < vertexCount; i++){
        printf("%d -> %d\n", i, distanceArr[i]);
    }
}
