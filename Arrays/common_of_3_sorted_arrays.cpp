#include<bits/stdc++.h>
using namespace std;

vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            int p1=0, p2=0, p3=0;
            unordered_set<int>st;
            vector<int>res;
            while(p1<n1 && p2<n2 && p3<n3)
            {
                if(a[p1]==b[p2] && b[p2]==c[p3])
                {
                    //res.push_back(a[p1]);
                    if(res.empty())
                    {
                        res.push_back(a[p1]);
                    }
                    else if(a[p1] != res.back())
                    {
                        res.push_back(a[p1]);
                    }
                    p1++;
                    p2++;
                    p3++;
                }
                else if(a[p1]<b[p2] && a[p1]<c[p3])
                {
                    p1++;
                }
                else if(b[p2]<a[p1] && b[p2]<c[p3])
                {
                    p2++;
                }
                else if(c[p3]<a[p1] && c[p3]<b[p2])
                {
                    p3++;
                }
                
            }
            // for(auto it : st)
            // {
            //     res.push_back(it);
            // }
            // sort(res.begin(), res.end());
            return res;
        }

int main() {
    int arr1[] ={1, 5, 10, 20, 40, 80}, arr2[] ={6, 7, 20, 80, 100}, arr3[] ={3, 4, 15, 20, 30, 70, 80, 120};
    vector<int>res;
    res = commonElements(arr1, arr2, arr3, 6, 5, 8 );
    for(auto it: res )
    {
        cout<<it<<" ";
    }
}