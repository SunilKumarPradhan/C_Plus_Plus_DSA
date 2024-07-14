#include <bits/stdc++.h>
using namespace std;
/*
void PrevGeaterEle(int arr[] , int n){
    for (int i =0; i<n;i++){
        int j; //iss tarah declare karna important hai
        for(j=i-1;j>=0;j--){
            if(arr[j]>arr[i]){
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j==-1) cout<<-1<<" ";
    }
}
*/

void PrevGeaterEle(int arr[] , int n){
    stack<int> st;
    st.push(arr[0]);

    for(int i=0; i<n;i++){
        while(st.empty()==false && st.top()<=arr[i]){
            st.pop();
        }
        int pg = (st.empty()) ? -1:st.top();
        cout<<pg<<" ";
        st.push(arr[i]);
    }
}

int main() {
    int arr[]={18,12,13,14,11,16};
    int n=sizeof(arr)/sizeof(arr[0]);
    PrevGeaterEle(arr, n);
    return 0;
}
