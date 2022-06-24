// Mark Valentino CSCE 350
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    int numberOfLockers = 1;
    int numberOfPasses = 0;
    char continueLoop = 'y';
    // This value is incremented and is reset  to 0 at the end of the while loop.
    int numberOfOpenDoors = 0;
    
    while (continueLoop == 'y') {
        cout << "How many locker doors should there be?" << endl;
        cin >> numberOfLockers;
        cout << "How many passes should there be?" << endl;
        cin >> numberOfPasses;

        // To make the algorithm easier to code, lockers[] will be treated as if it starts from index 1.
        // lockers[0] will be ignored. 
        int lockers[numberOfLockers + 1];

        // Sets all lockers to be closed before passes start. 0 means closed and 1 means open.
        for (int i = 1; i <= numberOfLockers; i++) {
            lockers[i] = 0;
        }

        for (int i = 1; i <= numberOfPasses; i++) {
            for (int j = 1; j <= numberOfLockers; j++) {
                // This toggles every ith locker on the ith pass.
                if (j % i == 0) {
                    lockers[j] = abs(lockers[j] - 1);
                }
            }  
        }

        cout << "Locker numbers: ";
        for (int i = 1; i <= numberOfLockers; i++) {
            // If locker is open.
            if (lockers[i] == 1) {
                cout << i << " ";
                numberOfOpenDoors++;
            }
        }
        cout << "are open." << endl << "Locker numbers: ";

        for (int i = 1; i <= numberOfLockers; i++) {
            // If locker is closed.
            if (lockers[i] == 0) {
                cout << i << " ";
            }
        }
        cout << "are closed.\nThere are " << numberOfOpenDoors << " total open locker door(s).\n"
            "Enter \'y\' to continue or otherwise quit the program." << endl;
        cin >> continueLoop;

        numberOfOpenDoors = 0;
    }

    return 0;
}