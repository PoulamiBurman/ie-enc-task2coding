#include <iostream>
int fib(int n){
    if (n==0){
        return 0;
    }
    else{
        return (fib(n-1)+n);
    }
    
}
int main() {
    
    int x,n;
    std::cout << "enter n ";
    std::cin>>n;
    x=fib(n);
    std::cout << "the sum is "<< x;

return 0;
}