#include<iostream>
#include<cstring>
using namespace std;
int main(){
    cout<<"enter the string\n";
    string s1,s2;
    cin>>s1;
    cout<<"enter the string s2\n";
    cin>>s2;
    int n1=s1.size();
    int n2=s2.size();

    int dp[n1+1][n2+1];
    for(int i=0;i<=n1;i++) dp[i][0]=0;
    for(int i=1;i<=n2;i++) dp[0][i]=0;
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n1][n2];

    return 0;
}