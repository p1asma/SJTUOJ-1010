#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int a;
    int **m;
    int num=1;
    cin>>a;
    m=new int *[a];
    for (int i=0;i<a;++i)
        m[i]=new int[a];
    if (a %2==1) m[a/2][a/2]=a*a;
    for (int i=0;i<a/2;++i){
        for (int j=i;j<=a-i-2;++j){
            m[i][j]=num;
            ++num;
        }
        
        for (int j=i;j<=a-2-i;++j){
            m[j][a-i-1]=num;
            ++num;
        }
    
        for (int j=a-i-1;j>=i+1;--j){
            m[a-i-1][j]=num;
            ++num;
        }
        
        for (int j=a-i-1;j>=i+1;--j){
            m[j][i]=num;
            ++num;
        }
        
    }
    for (int i=0;i<a;++i){
        for (int j=0;j<a;++j)
            cout<<setw(6)<<m[i][j]<<' ';
        cout<<'\n';
    }
}