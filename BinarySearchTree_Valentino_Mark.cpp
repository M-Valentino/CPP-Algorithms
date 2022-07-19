// Mark Valentino CSCE 350
#include <list>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int nodeValue;
	struct Node *leftChild, *rightChild;
};

// Root node of BST that links to other nodes.
Node* rootNode = NULL;
// If 0, -> program forces user to enter nodes. If 1, -> program knows to set root node.
int nodeCount = 0;
// Holds all values of nodes in the order the user added them to the tree. Used in rebuilding tree.
vector<int> valuesOfChildren;

// Creates a leaf node or the root node which can later become a parent node.
Node* createNode(int nodeValue) {
	Node* nodeWithNoChildren = new Node;
	nodeWithNoChildren->nodeValue = nodeValue;
	nodeWithNoChildren->leftChild = NULL;
	nodeWithNoChildren->rightChild = NULL;
	return nodeWithNoChildren;
}

// pushback is true only when user wants to grow the tree.
void insertNode(Node* parent, int newNodeValue, bool pushback) {
	Node* newNode = createNode(newNodeValue);

    // Sets root node of BST
    if (nodeCount == 1) {
        rootNode = newNode;
        if (pushback == true) {
                valuesOfChildren.push_back(newNodeValue);
            }
        return;
    } 
    // Case where a node with a duplicate value is atempted to be added.
    if (newNodeValue == parent->nodeValue) {
        cout << "Can't add duplicate values." << endl;
        // nodeCount is incremented by default in enterNodesToAdd() without
        // comfirmation that the node has been added.
        nodeCount--;
    }
    // Attemps to insert node on left.
    else if (newNodeValue < parent->nodeValue) {
        if (parent->leftChild == NULL) { 
            parent->leftChild = newNode;
            if (pushback == true) {
                valuesOfChildren.push_back(newNodeValue);
            }
        } else {
            insertNode(parent->leftChild, newNodeValue, pushback);
        }
    }
    // if newNodeValue > parent->nodeValue. Attemps to insert node on right.
    else {
        if (parent->rightChild == NULL) { 
            parent->rightChild = newNode;
            if (pushback == true) {
                valuesOfChildren.push_back(newNodeValue);
            }
        } else {
            insertNode(parent->rightChild, newNodeValue, pushback);
        }
    }
}

// Gives a user interface to insertNode()
void enterNodesToAdd() {
    string userInput;
    int number;

    cout << "Type the numbers you wish to add to the binary search tree and hit enter for each number." << endl;
    cout << "Enter \'m\' when finished to go to the main menu, or enter \'q\' to exit the program." << endl;
    while (1) {
        cin >> userInput;
        if (userInput == "m" || userInput == "M") {
            break;
        }
        else if (userInput == "q" || userInput == "Q") {
            exit(0);
        } 
        try {
            number = std::stoi(userInput);
        } catch (std::invalid_argument& e) {
            cout << "Invalid input." << endl;
            // Allows user to try again at inputing a number.
            continue;
        }

        nodeCount++;
        insertNode(rootNode, number, true);
    }

    if (nodeCount == 0) {
        cout << "No nodes in tree." << endl;
    }
}

void searchForNode(Node* parent, int valueToSearch) {
    if (valueToSearch == parent->nodeValue) {
        cout << valueToSearch << " = " << valueToSearch << ", ";
        cout << "The value: " << valueToSearch << " was found." << endl;
    }
    // Looks at left child of node.
    else if (valueToSearch < parent->nodeValue) {
        if (parent->leftChild == NULL) { 
            cout << "Could not find: " << valueToSearch << endl;
        } else {
            cout << valueToSearch << " < " << parent->nodeValue << ", ";
            searchForNode(parent->leftChild, valueToSearch);
        }
    }
    // if valueToSearch > parent->nodeValue. Looks at right child of node.
    else {
        if (parent->rightChild == NULL) { 
            cout << "Could not find: " << valueToSearch << endl;
        } else {
            cout << valueToSearch << " > " << parent->nodeValue << ", ";
            searchForNode(parent->rightChild, valueToSearch);
        }
    }
}

// Gives a user interface to searchForNode()
void enterNodesToSearch() {
    string userInput;
    int number;
    while(1) {
        cout << "Enter a value to search or enter 'm' to go back to the menu" << endl;
        cin >> userInput;
        if (userInput == "m" || userInput == "M") {
            break;
        }
        try {
            number = std::stoi(userInput);
        } catch (std::invalid_argument& e) {
            cout << "Invalid input." << endl;
            // Allows user to try again at inputing a number.
            continue;
        }
        searchForNode(rootNode, number);
    }
}

// Displays all node values in BST sorted.
void inorderTraversal(Node* parent) {
    if (parent != NULL) {
		inorderTraversal(parent->leftChild);
		cout << parent->nodeValue << " ";
		inorderTraversal(parent->rightChild);
	}
}

/**
 * This function works by first erasing the node value from valuesOfChildren and
 * then rebuilding the BST from valuesOfChildren. It calls insertNode() with the
 * pushback parameter set to false since no more nodes are being added to the BST.
 */
void deleteNode(int valueToDelete) {
    for (int i = 0; i < valuesOfChildren.size(); i++) {
        if (valuesOfChildren[i] == valueToDelete) {
            valuesOfChildren.erase(valuesOfChildren.begin() + i);
            nodeCount--;
            break;
        }
    }
    rootNode->leftChild = NULL;
    rootNode->rightChild = NULL;

    if (nodeCount != 0) {

        nodeCount = 0;
        for (int i = 0; i < valuesOfChildren.size(); i++) {
            nodeCount++;
            insertNode(rootNode, valuesOfChildren[i], false);
        }
    } else {
        delete rootNode;
    }
}

// Gives a user interface to deleteNode()
void enterNodesToDelete() {
    string userInput;
    int number;
    while(1) {
        cout << "Enter a node value to delete or enter 'm' to go back to the menu" << endl;
        cin >> userInput;
        if (userInput == "m" || userInput == "M") {
            break;
        }
        try {
            number = std::stoi(userInput);
        } catch (std::invalid_argument& e) {
            cout << "Invalid input." << endl;
            // Allows user to try again at inputing a number.
            continue;
        }
        deleteNode(number);
        // Makes user go back to menu if all nodes are deleted.
        if (nodeCount == 0) {
            cout << "All nodes deleted.\n" << endl;
            break;
        }
    }
}

void executeMenuOption(int option) {
    // Adds a new line after menu and user entered option to make the program easier to follow.
    cout << endl;

    switch(option) {
        case 0:
            exit(0);
        case 1:
            enterNodesToAdd();
            break;
        case 2: 
            enterNodesToSearch();
            break;
        case 3:
            enterNodesToDelete();
            break;
        case 4:
            cout << "In order traversal of tree:" << endl;
            inorderTraversal(rootNode);
            // Above function does not have "endl" so it is added here.
            cout << endl;
            cout << "Node Count: " << nodeCount << endl;
            break;
        default:
            cout << "Invalid option." << endl;
    }
}

void printMenu() {
    cout << "\n--- Menu ---" << endl;
    cout << "Enter '1' to add more nodes." << endl;
    cout << "Enter '2' to search for a node" << endl;
    cout << "Enter '3' to delete a node." << endl;
    cout << "Enter '4' to display all nodes." << endl;
    cout << "Enter '0' to quit." << endl;
}

int main(int argc, char *argv[]) {
    string userInput;
    int option;

    while (1) {
        // Search function crashes the program if all nodes are removed so user must add more nodes.
        if (nodeCount == 0) {
            enterNodesToAdd();
        }

        printMenu();
        cin >> userInput;
        try {
            option = std::stoi(userInput);
            } catch (std::invalid_argument& e) {
                cout << "Invalid input." << endl;
                // Allows user to try again at inputing a number.
                continue;
            }
        executeMenuOption(option);
    }

	return 0;
}
