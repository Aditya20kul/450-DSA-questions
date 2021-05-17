#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int removeDuplicates(vector<int>& nums) {
    //unordered_set<int>st;
        int cnt=1;
        int ele = nums[0];
        int tempcnt=1;
        //st.insert(nums[0]);
        int cnt1=0;
        for(int i=1; i<nums.size(); i++){
            cout<<"i : "<<i<<"\n";
            if(nums[i]==ele && tempcnt>=2){
                cnt1++;
                int tempele = nums[i];
                for(int j=i+1; j<nums.size(); j++){
                    nums[j-1] = nums[j];
                }
                nums[nums.size()-1]=tempele;
                i--;
            }
            else{
                if(nums[i]==ele && tempcnt<2){
                    tempcnt++;
                    ele = nums[i];
                    cnt++;
                }
                else{
                    //tempcnt=0;
                    ele=nums[i];
                    tempcnt=1;
                    cnt++;
                }
                
            }
            cout<<"Cnt - "<<cnt<<" TempCnt - "<<tempcnt<<" i - "<<i<<"\n";
        }
        return cnt-cnt1;
    }

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i,j,t,n,cnt=0;
  string str;
  vector<int>vec={0,0,1,1,1,1,2,3,3};
  int ans = removeDuplicates(vec);
  for(int i=0;i<ans;i++)
    cout<<vec[i]<<" ";
  return 0;
}