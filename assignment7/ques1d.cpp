#include<iostream>
#include<vector>
using namespace std;
//merge step
int merge(vector<int>&arr,int st,int mid,int end,int count){
    vector<int>temp;
    int i=st;
    int j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
          temp.push_back(arr[i]);
          i++;  
        }
        else{
            temp.push_back(arr[j]);
            j++;
            count=mid-i+1;
        }
    }
    //after this either of the halves would have been travelled
    //doing this for the remaining halves
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx=0;idx<temp.size();idx++){
        arr[idx+st]=temp[idx]; 
    }
return count;
}

int mergesort(vector<int>&arr,int st,int end,int count){
    if(st<end){
    int mid=st+(end-st)/2;

    //lefthalf
    count+=mergesort(arr,st,mid,0);
    count+=mergesort(arr,mid+1,end,0);
    count+=merge(arr,st,mid,end,0);
    }
    return count;
 }
int main(){
   
vector<int>arr={5,3,6,1};
 int count= mergesort(arr,0,arr.size()-1,0);
for(int val:arr){
    cout<<val<<" ";
}
cout<<endl;
cout<<"no of inversions present: "<<count;
    return 0;
}