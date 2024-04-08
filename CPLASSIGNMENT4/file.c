#include <stdio.h>

int EvenOrOdd(int a) {
    int ans ;
    if(a%2==0){
        ans = 1;
    }
    else{
    ans = 0;
    }
    return ans;
    
}

int main() {
    // 
    int x =5;
    x = EvenOrOdd(x);
        return 0;
}
