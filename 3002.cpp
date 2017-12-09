#include<iostream>
using namespace std;
#include<vector>

int main(){
    int n,tmp;
    vector<int>a,result;
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>tmp;
        a.push_back(tmp);
        //cout<<'!'<<a.size()<<'!';
    }
    
    for (int i=0;i<n-1;++i){
        for (int j=0;j<(n-1-i);++j){
            if (a[j]>a[j+1]){
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
    //cout<<a.capacity();
    result.push_back(a[0]);
    //cout<<a.capacity();
    for (int i=1;i<a.size();++i){
        if(a[i]==a[i-1]) continue;
        else result.push_back(a[i]);
    }

    cout<<result.size ()<<endl;
    cout<<result[0];
    for (int i=1;i<result.size();++i){
        cout<<' '<<result[i];
    }
    return 0;
}

