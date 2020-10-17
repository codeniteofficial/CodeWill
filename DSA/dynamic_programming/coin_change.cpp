// min no  of coin 
// very important different intialization
#include<iostream>
#define int_max 1e9;
using namespace std;
int main(){
    cout<<"enter the size of array and demonititions\n";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"enter the sum\n ";
    int sum;
    cin>>sum;
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++) dp[0][i]=int_max;
    for(int i=1;i<=n;i++) dp[i][0]=0;
    //for(int i=2;i<=sum)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-a[i-1]],dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    if(dp[n][sum]>=1e9) cout<<"not possible\n";
    else cout<<dp[n][sum];

    return 0;
}