#include <cstdio>

#define MAX 20

int vertexCount;
int graph[MAX][MAX];

void addEdge(int fromVertex, int toVertex){
    graph[fromVertex][toVertex] = 1;
    graph[toVertex][fromVertex] = 1;
}

int degreeOfVertex(int vertex){
    int count = 0;
    for(int i = 0; i < vertexCount; i++){
        if(graph[vertex][i] == 1) count++;
    }
    return count;
}

void printAdjacentVertices(int vertex){
    for(int i = 0; i < vertexCount; i++){
        if(graph[vertex][i] == 1) printf("%d ", i);
    }
    printf("\n");
}

int numberOfEdges(){
    int count = 0;
    for(int i = 0; i < vertexCount; i++){
        for(int j = i + 1; j < vertexCount; j++){
            if(graph[i][j] == 1) count++;
        }
    }
    return count;
}

int main(){
    int edgeCount;
    int fromVertex;
    int toVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &vertexCount);

    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);

    for(int i = 0; i < vertexCount; i++){
        for(int j = 0; j < vertexCount; j++){
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < edgeCount; i++){
        scanf("%d %d", &fromVertex, &toVertex);
        addEdge(fromVertex, toVertex);
    }

    int choice;
    while(1){
        printf("1 degree 2 adjacent 3 edges 4 exit\n");
        scanf("%d", &choice);

        if(choice == 1){
            scanf("%d", &fromVertex);
            printf("%d\n", degreeOfVertex(fromVertex));
        } 
        else if(choice == 2){
            scanf("%d", &fromVertex);
            printAdjacentVertices(fromVertex);
        } 
        else if(choice == 3){
            printf("%d\n", numberOfEdges());
        } 
        else break;
    }
}
