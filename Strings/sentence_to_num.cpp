// https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/

#include<bits/stdc++.h>
using namespace std;
 
string printSequence(string arr[], string ip) 
{ 
    string ans = ""; 
    int n = ip.length(); 
    for (int i=0; i<n; i++) 
    { 
        if (ip[i] == ' ') 
            ans = ans + "0"; 
  
        else
        { 
            int pos = ip[i]-'A'; 
            ans = ans + arr[pos]; 
        } 
    } 
    return ans; 
} 

int main() 
{ 
    string mp[] = {"2","22","222", 
                    "3","33","333", 
                    "4","44","444", 
                    "5","55","555", 
                    "6","66","666", 
                    "7","77","777","7777", 
                    "8","88","888", 
                    "9","99","999","9999"
                   }; 
  
    string input;
    getline(cin,input);
    transform(input.begin(), input.end(), input.begin(), ::toupper); 
    cout << printSequence(mp, input); 
    return 0; 
} 