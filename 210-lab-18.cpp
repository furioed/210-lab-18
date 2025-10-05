// COMSC-210 | Lab 18 | Mamadou Sissoko
// IDE used: Visual Studio Code
// Linked list storing movie reviews

#include <iostream>
#include <string>
using namespace std;

// Node structure for review
struct Node {
    double rating;
    string comment;
    Node* next;
};

// Adds review at head of linked list
void addHead(Node*& head, double rating, const string& comment) {
    Node* newNode = new Node{rating, comment, head};
    head = newNode;
}

// Adds review at tail of linked list
void addTail(Node*& head, double rating, const string& comment) {
    Node* newNode = new Node{rating, comment, nullptr};
    if (!head) head = newNode;
    else {
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
}

// Displays all reviews
void display(Node* head) {
    cout << "\nOutputting all reviews:\n";
    int count = 0;
    for (Node* curr = head; curr; curr = curr->next) {
        count++;
        cout << "    > Review #" << count << ": " << curr->rating
             << ": " << curr->comment << endl;
    }
}

int main() {
    Node* head = nullptr;
    int choice;

    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";
    cout << "    Choice: ";
    cin >> choice;
    cin.ignore();

    char again = 'y';

    // User input starts here
    while (tolower(again) == 'y') {
        double rating;
        string comment;

        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();
        cout << "Enter review comments: ";
        getline(cin, comment);

        if (choice == 1) addHead(head, rating, comment);
        else addTail(head, rating, comment);

        cout << "Enter another review? Y/N: ";
        cin >> again;
        cin.ignore();
    }

    display(head);
    return 0;
}
