#include <cstdio>

#define MAX 50
#define INF 999999

int vertexCount;
int graph[MAX][MAX];
int visited[MAX];
int keyValue[MAX];
int parentArr[MAX];

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &vertexCount);

    for(int i = 0; i < vertexCount; i++){
        for(int j = 0; j < vertexCount; j++){
            scanf("%d", &graph[i][j]); 
        }
    }

    for(int i = 0; i < vertexCount; i++){
        visited[i] = 0;
        keyValue[i] = INF;
        parentArr[i] = -1;
    }

    keyValue[0] = 0;

    for(int k = 0; k < vertexCount - 1; k++){
        int minValue = INF;
        int minIndex = -1;

        for(int i = 0; i < vertexCount; i++){
            if(!visited[i] && keyValue[i] < minValue){
                minValue = keyValue[i];
                minIndex = i;
            }
        }

        visited[minIndex] = 1;

        for(int v = 0; v < vertexCount; v++){
            if(graph[minIndex][v] && !visited[v] && graph[minIndex][v] < keyValue[v]){
                parentArr[v] = minIndex;
                keyValue[v] = graph[minIndex][v];
            }
        }
    }

    int totalWeight = 0;
    printf("MST edges:\n");
    for(int i = 1; i < vertexCount; i++){
        printf("%d - %d ( %d )\n", parentArr[i], i, graph[i][parentArr[i]]);
        totalWeight += graph[i][parentArr[i]];
    }

    printf("Total MST weight: %d\n", totalWeight);
}
