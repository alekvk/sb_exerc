#include <iostream>

void evendigits(long long int n, unsigned& ans) {

    if (n == 0) return;
    if ((n % 10) % 2 == 0) ++ans;
    evendigits(n/10, ans);
}


int main() {

    long long int n;
    unsigned ans = 0;

    std::cout<<"Enter an integer: ";
    std::cin>>n;

    evendigits(n, ans);

    std::cout<<"ans = "<<ans;
     
    return 0;
}
