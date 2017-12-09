#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> st;
    int m,n;
    cin>>m>>n;
    st.push(m);
    st.push(n);
    while (!st.empty()){
        
        n=st.top();
        st.pop();
        if (st.empty()) {
            break;
        }
        m=st.top();
        st.pop();
        if (m!=0 &&n==0){
            st.push(m-1);
            st.push(1);
        }
        if (m!=0 && n!=0 ){
            st.push(m-1);
            st.push(m);
            st.push(n-1);
        }
        if (m==0){
            st.push(n+1);
        }

    }
    cout<<n;
    return 0;
}