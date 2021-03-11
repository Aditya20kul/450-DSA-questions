#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void manipulate(int arr[], int sz){
    for(int i = 0; i < sz;i++){
        arr[i]++;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i,j,t,n,cnt=0;
  string str;
  vector<int>vec;
    int arr[5] = {1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    manipulate(arr, 5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
  return 0;
}