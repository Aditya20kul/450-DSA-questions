
/*
    - Program for printing Union and Intersection of two Sorted Arrays.
    - This Program also takes care of duplicates.
    - The program implemented below is not making use of SET.
*/


#include<bits/stdc++.h>
using namespace std;

void printUnion(int arr1[], int arr2[], int len1, int len2)
{

    int first = 0, second = 0;
    vector<int>res;
    int flag=0;
    while(first < len1 && second < len2)
    {
        //cout<<" "<<first<<" "<<second<<"\n";
        if(arr1[first]==arr2[second])
        {
            if(flag==0)
            {
                res.push_back(arr1[first]);
                flag=1;
            }
            else if(res.back() != arr1[first])
            {
               res.push_back(arr1[first]);
            }
            first++;
            second++;
        }
        else if(arr1[first] > arr2[second] )
        {
            if(flag==0)
            {
                res.push_back(arr1[first]);
                flag=1;
            }
            else if(res.back()!=arr2[second])
            {
                res.push_back(arr2[second]);
            }
             second++;
        }
        else
        {
            if(arr1[first] < arr2[second])
            {
                if(flag==0)
                {
                res.push_back(arr1[first]);
                flag=1;
                }
               else if(res.back()!=arr1[first])
                {
                    res.push_back(arr1[first]);
                }
                first++;
            }
        }
    }

    while(first<len1)
    {
        if(res.back()!=arr1[first])
        {
            res.push_back(arr1[first]);
        }
        first++;
    }
    while(second<len2)
    {
        if(res.back()!=arr2[second])
        {
            res.push_back(arr2[second]);
        }
        second++;
    }

    cout<<"Union - ";
    for(auto it : res)
    {
        cout<<it<<" ";
    }

}

void printIntersection(int arr1[], int arr2[], int len1, int len2)
{
    int first = 0, second = 0;
    vector<int>res;
    int flag=0;
    while(first<len1 && second<len2)
    {
        //cout<<first<<" "<<second<<"\n";
        if(arr1[first]==arr2[second])
        {
            //cout<<"equal\n";
            if(flag==0)
            {
                res.push_back(arr1[first]);
                flag=1;
            }
            else if(res.back() != arr1[first])
            {
               res.push_back(arr1[first]);
            }
            first++;
            second++;
        }
        else if(arr1[first] > arr2[second] )
        {
             second++;
        }
        else
        {
            first++;
        }
    }
    cout<<"Intersection - ";
    for(auto it : res)
    {
        cout<<it<<" ";
    }
}

int main()
{
    int arr1[] = {1,2,2,3,4};
    int arr2[] = {2,3,4,4,5};
    //printUnion(arr1, arr2,4, 5);
    printIntersection(arr1, arr2, 5, 5);
    return 0;
}
