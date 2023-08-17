#include <iostream>
using std::cout;

bool isprime(int n) {
    for (int i = 2; i <=n/2; i++)
        if (n % i == 0)
            return false;
    return true; 
};

class prime_generator {
    public:
        prime_generator() = default;
        int nextprime() {
            while (!isprime(last_tested))
                last_tested++;
            return last_tested++;
        };
    private:
        int last_tested{2};
};

int main() {
    prime_generator primes;
    for ( int i = 0; i < 100; i++)
        cout << primes.nextprime() << '\n';
    return 0;
}