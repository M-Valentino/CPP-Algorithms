// Mark Valentino CSCE 350
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {

    // Inputted number to be prime factorized.
    int n;
    cout << "What number do you want the prime factorization for?" << endl;
    cin >> n;
    if (n <= 1) {
        cout << "This number cannot be factored" << endl;
        return 0;
    }
    // This holds all numbers <= n that possibly might be prime.
    int numbers[n];
    
    // Puts all candidates <= n for being prime in numbers[]
    for (int p = 2; p <= n; p++) {
        numbers[p] = p;
    }

    int j;
    // Sets non prime numbers in numbers[] to 0.
    for (int p = 2; p <= sqrt(n); p++) {
        if (numbers[p] != 0) {
           j = p*p;
        }
        while (j <= n) {
            numbers[j] = 0;
            j +=p;
        }
    }
    
    // This holds all primes <= n with no duplicate numbers.
    vector<int> primesLessThanN;
    // Copies all primes, but not 0 values to primesLessThanN.
    for (int p = 2; p <= n; p++) {
        if (numbers[p] != 0) {
            primesLessThanN.push_back(numbers[p]);
        }
    }

    // This variable keeps getting divided by prime numbers until the prime factorization is found.
    int tempNum = n;
    // This holds the numbers of the prime factorization with duplicates.
    vector<int> primeFactors;
    // Finds the prime factorization.
    for (int i = 0; i < primesLessThanN.size(); i++) {
        while (tempNum % primesLessThanN.at(i) == 0) {
            tempNum = tempNum / primesLessThanN.at(i);
            primeFactors.push_back(primesLessThanN.at(i));
        }
    }

    // Prints out the prime factorization.
    cout << "The prime factorization is: ";
    for (int i = 0; i < primeFactors.size(); i++) {
        cout << primeFactors.at(i);
        if (i < primeFactors.size() - 1) {
            cout << "x";
        }
    }
    cout << endl;
  
    return 0;
}