#include<stdio.h>
int funcp(int);
int funcp(int, int);
int main(){
    int r= funcp(5);
    print("%d\n", r);
return 0;
}
int funcp(int n){
return funcp(n,1);
}
int func(int n, int x){
    if(n==-1){
        return x;
    }
    return funcp(n-1, n*x);







}
///saber navegar no codigo por uma arvore binaria, qual vai ser a nova configuracao da arvore, pedir para remover um nó