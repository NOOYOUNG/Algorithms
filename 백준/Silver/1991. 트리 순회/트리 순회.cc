#include <iostream>

using namespace std;

int nodes[26][2]={{-1,-1}}; //초기화

void preorder(int n){
    if(n==-1) return;
    cout<<(char)(n+'A');
    preorder(nodes[n][0]);
    preorder(nodes[n][1]);
}

void inorder(int n){
    if(n==-1) return;
    inorder(nodes[n][0]);
    cout<<(char)(n+'A');
    inorder(nodes[n][1]);
}

void postorder(int n){
    if(n==-1) return;
    postorder(nodes[n][0]);
    postorder(nodes[n][1]);
    cout<<(char)(n+'A');
}

int main()
{
    int N;
    cin>>N;
    
    for(int i=0; i<N; i++){
        char node, left, right;
        cin>>node>>left>>right;
        int index=node-'A'; //입력이 A~Z이므로 0~26의 수를 얻음

        if(left=='.'){
            nodes[index][0]=-1;
        }
        else{
            nodes[index][0]=left-'A';
        }

        if(right=='.'){
            nodes[index][1]=-1;
        }
        else{
            nodes[index][1]=right-'A';
        }
    }

    preorder(0); //루트 노드를 0으로 설정하고 모든 트리 순회
    cout<<endl;
    inorder(0);
    cout<<endl;
    postorder(0);
    
}