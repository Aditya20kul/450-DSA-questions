// https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class kStacks{

    int *arr;
    int *next;
    int *top;
    int nextFree, n, k;

    public:
        kStacks(int n, int k){
            arr = new int[n];
            next = new int[n];
            top = new int[k];
            nextFree = 0;
            for(int i = 0; i < k; i++){
                top[i] = -1;
            }
            for(int i=0; i<n-1; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
            nextFree = 0;
        }

        void push(int item, int sn){
            if(isFull()){
                cout<<"Stack Overflow\n";
                return;
            }
            int i = nextFree;
            nextFree = next[i];
            next[i] = top[sn];
            top[sn] = i;
            arr[i] = item;
        }

        int pop(int sn){
            if(isEmpty(sn)){
                cout << "\nStack Underflow\n";
                return INT_MAX;
            }
            int item;
            int i = top[sn];
            top[sn] = next[i];
            next[i] = nextFree;
            nextFree = i;
            item = arr[i];
            return item;
        }

        bool isEmpty(int sn){ 
            if(top[sn] == -1){
                return true;
            }
            return false;
        }

        bool isFull(){
            return (nextFree == -1);
        }

};

int main()
{
  kStacks ks(6, 3);
  ks.push(100, 0);
  ks.push(200, 0);
  ks.push(300, 0);
  cout<<ks.pop(0);


  return 0;
}