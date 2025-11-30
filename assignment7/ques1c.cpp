#include <iostream>
using namespace std;
int32_t main(){

    int n =5;
    int arr[]={4,1,5,2,3};
    for(int i=0;i<n;i++){
        bool isswap =false; 
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isswap=true;
            }
        }
        if(!isswap){
         break;}
        
    
}
 for(int i=0;i<n;i++){
        cout <<arr[i];
         }
      
    return 0;
}
