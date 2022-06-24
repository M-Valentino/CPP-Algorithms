#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    int numberOfLockers = 1;
    int numberOfPasses = 0;
    cout << "How many locker doors should there be?\n";
    cin >> numberOfLockers;
    cout << "How many passes should there be?\n";
    cin >> numberOfPasses;
    int lockers[numberOfLockers];

    // Sets all lockers to be closed before passes start. 0 means closed and 1 means open.
    for (int i = 0; i < numberOfLockers; i++) {
        lockers[i] = 0;
    }

    for (int i = 0; i < numberOfPasses; i++) {
        for (int j = 0; j < numberOfLockers; j++) {
            // Locker numbers start at 1 unlike the array index of lockers.
            if ((i + 1) % j == 0) {
                lockers[j] = abs(lockers[j] - 1);
            }
        }  
    }

    cout << "Locker numbers: ";
    for (int i = 0; i < numberOfLockers; i++) {
        if (lockers[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    cout << "are open.\n";

    cout << "Locker numbers: ";
    for (int i = 0; i < numberOfLockers; i++) {
        if (lockers[i] == 0) {
            cout << i + 1 << " ";
        }
    }
    cout << "are closed.";

    return 0;
}