// Mark Valentino CSCE 350
#include <iostream>
#include <vector>
using namespace std;

int hoarePartition(vector<int> &list, int leftBound, int rightBound) {
    int pivot = list[leftBound];
    int i = leftBound;
    // Originally set beyond the max index of list but is decremented by 1 before
    // list[j] is accessed.
    int j = rightBound + 1; 

    do {
        do {
            i++;
        // Equivalent to while (!(list[i] >= p))
        } while (list[i] < pivot);

        do {
            j--;
        // Equivalent to while (!(list[j] <= p))
        } while (list[j] > pivot);

        swap(list[i], list[j]);
    // Equivalent to while (!(i >= j))
    } while (i < j);

    swap(list[i], list[j]);
    swap(list[leftBound], list[j]);

    return j;
}

void quickSort(vector<int> &list, int leftBound, int rightBound) {
    if (leftBound < rightBound) {
        int splitPosition = hoarePartition(list, leftBound, rightBound);
        quickSort(list, leftBound, splitPosition - 1);
        quickSort(list, splitPosition + 1, rightBound);
    }
}

int main(int argc, char *argv[]) {
    // Holds all numbers to be sorted.
    vector<int> list;
    // Holds anything user enters in on the terminal.
    string userInput;
    // Number to be added to vector for sorting.
    int number;

    cout << "Type the numbers you wish to sort and hit enter for each number." << endl;
    cout << "Enter \'s\' when finished." << endl;
    while (1) {
        cin >> userInput;
        if (userInput == "s" || userInput == "S") {
            break;
        }
        try {
            number = std::stoi(userInput);
        } catch (std::invalid_argument& e) {
            cout << "Invalid input." << endl;
            // Allows user to try again at inputing a number or inputting 's'/'S' to stop.
            continue;
        }
        list.push_back(number);
    }

    // Sorts using left-most element of the dynamic array 
    quickSort(list, 0, list.size() - 1);

    // If user enters 1 or 0 numbers
    if (list.size() < 2) {
        cout << "Nothing to be sorted." << endl;
        return 0;
    }

    cout << "Your inputted numbers sorted:\n";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
  
    return 0;
}