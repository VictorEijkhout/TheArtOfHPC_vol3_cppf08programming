#include <iostream>
#include <cmath>

bool isprime(int number) {
    if (number <= 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    
    int sqrtNum = static_cast<int>(std::sqrt(number));
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (number % i == 0)
            return false;
    }
    
    return true;
}

class primegenerator {
private:
    int primes_found;

public:
    primegenerator() : primes_found(0) {}

    int number_of_primes_found() const {
        return primes_found;
    }

    int nextprime() {
        int number = primes_found + 1;
        while (!isprime(number))
            number++;
        
        primes_found++;
        return number;
    }
};

int main() {
    int nprimes;
    std::cin >> nprimes;

    primegenerator sequence;
    while (sequence.number_of_primes_found() < nprimes) {
        int number = sequence.nextprime();
        std::cout << "Number " << number << " is prime" << '\n';
    }

    return 0;
}
