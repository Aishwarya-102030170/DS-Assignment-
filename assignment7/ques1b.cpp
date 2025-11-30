#include <iostream>
using namespace std;
void isort(int arr[],int n){
    for(int i=1;i<n;i++){
        int sorted=arr[i];
        int j=i-1;
        while(j>=0 && sorted<arr[j]){
arr[j+1]=arr[j];
j--;
        }
    arr[j+1]=sorted;

    }
     
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
cout<<endl;
}
int32_t main(){
int n=5;
int arr[]={4,1,5,2,3};
isort(arr,n);
print(arr,n);
     return 0;

}