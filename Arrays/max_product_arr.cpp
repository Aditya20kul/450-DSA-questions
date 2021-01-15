//https://www.geeksforgeeks.org/maximum-product-subarray/

#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>&vec)
{
    int overall_max = vec[0], max_eh = vec[0], min_eh = vec[0];
    for(int i=1; i<vec.size(); i++)
    {
        int temp = max_eh;
        max_eh = max({vec[i], max_eh*vec[i], min_eh*vec[i]});
        min_eh = min({vec[i], temp*vec[i], min_eh*vec[i]});
        //cout<<max_eh<<" "<<min_eh<<"\n";
        overall_max = max(overall_max, max_eh);
    }

    return overall_max;
}

int main()
{
   int i,j,cnt=0;
   vector<int>vec{-3, 2, -4, 6, 0, -8, 5};
   cout<<maxProduct(vec);
   return 0;
}