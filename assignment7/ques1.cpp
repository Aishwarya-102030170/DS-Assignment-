#include <iostream>
using namespace std;
void selectionsort(int n,int arr[]){
for(int i=0;i<n-1;i++){
    int smallestidx=i;
    for(int j=i+1;j<n;j++){
        if(arr[smallestidx]>arr[j]){
            smallestidx=j;
            
        }


        

    }
    swap(arr[smallestidx],arr[i]);
}
}
int print(int n,int arr[]){
    for ( int i = 0; i <n; i++){
        cout << arr[i];
    }
    cout<<endl;
    
        
    }
    


int32_t main(){
     int n =5;
    int arr[]={4,1,5,2,3};
selectionsort(n,arr);
print(n,arr);

    return 0;
}