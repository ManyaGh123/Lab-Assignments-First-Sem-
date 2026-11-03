
#include <iostream>
using namespace std;

class CircularList {
public:
    struct Node {
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
    };

    Node* head;

    CircularList() {
        head = NULL;
    }

    // QUESTION 1(a): INSERT AT BEGINNING
    void insertBeginning(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // QUESTION 1(a): INSERT AT END
    void insertEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    // QUESTION 1(a): INSERT AFTER A SPECIFIC NODE
    void insertAfter(int key, int val) {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        Node* temp = head;

        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);

                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }

            temp = temp->next;
        } while (temp != head);

        cout << "Node not found";
    }

    // QUESTION 1(a): INSERT BEFORE A SPECIFIC NODE
    void insertBefore(int key, int val) {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        if (head->data == key) {
            insertBeginning(val);
            return;
        }

        Node* temp = head;

        while (temp->next != head &&
               temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == head) {
            cout << "Node not found";
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // QUESTION 1(b): DELETE A SPECIFIC NODE
    void deleteSpecific(int key) {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        do {
            if (temp->data == key) {
                if (temp == head) {
                    if (head->next == head) {
                        delete head;
                        head = NULL;
                        return;
                    }

                    Node* last = head;

                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;
                }
                else {
                    prev->next = temp->next;
                }

                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;

        } while (temp != head);

        cout << "Node not found";
    }

    // QUESTION 1(c): SEARCH
    void search(int key) {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        Node* temp = head;
        int pos = 1;

        do {
            if (temp->data == key) {
                cout << "Position: " << pos;
                return;
            }

            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Node not found";
    }

    // QUESTION 2: DISPLAY WITH HEAD AGAIN AT END
    void display() {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << head->data;
    }

    // QUESTION 3(ii): SIZE OF CIRCULAR LIST
    int size() {
        if (head == NULL)
            return 0;

        int count = 0;
        Node* temp = head;

        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    // QUESTION 5: CHECK IF LINKED LIST IS CIRCULAR
    bool isCircular() {
        if (head == NULL)
            return false;

        Node* temp = head->next;

        while (temp != NULL && temp != head)
            temp = temp->next;

        return temp == head;
    }
};


class DoublyList {
public:
    struct Node {
        char data;
        Node* prev;
        Node* next;

        Node(char val) {
            data = val;
            prev = NULL;
            next = NULL;
        }
    };

    Node* head;

    DoublyList() {
        head = NULL;
    }

    // QUESTION 1(a): INSERT AT BEGINNING
    void insertBeginning(char val) {
        Node* newNode = new Node(val);

        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
    }

    // QUESTION 1(a): INSERT AT END
    void insertEnd(char val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // QUESTION 1(a): INSERT AFTER A SPECIFIC NODE
    void insertAfter(char key, char val) {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node not found";
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    // QUESTION 1(a): INSERT BEFORE A SPECIFIC NODE
    void insertBefore(char key, char val) {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node not found";
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = temp;
        newNode->prev = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = newNode;
        else
            head = newNode;

        temp->prev = newNode;
    }

    // QUESTION 1(b): DELETE A SPECIFIC NODE
    void deleteSpecific(char key) {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node not found";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
    }

    // QUESTION 1(c): SEARCH
    void search(char key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Position: " << pos;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Node not found";
    }

    // QUESTION 3(i): SIZE OF DOUBLY LINKED LIST
    int size() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // QUESTION 4: CHECK PALINDROME
    bool isPalindrome() {
        if (head == NULL)
            return true;

        Node* left = head;
        Node* right = head;

        while (right->next != NULL)
            right = right->next;

        while (left != right && left->prev != right) {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }

        return true;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    // QUESTION 1: CIRCULAR LINKED LIST
    CircularList c;

    c.insertBeginning(20);
    c.insertEnd(100);
    c.insertEnd(40);
    c.insertEnd(80);
    c.insertEnd(60);

    cout << "Circular List: ";
    c.display();

    cout << "\nSize: " << c.size();

    cout << "\nSearch 40: ";
    c.search(40);

    c.insertAfter(40, 50);
    c.insertBefore(80, 70);

    cout << "\nAfter insertion: ";
    c.display();

    c.deleteSpecific(60);

    cout << "\nAfter deletion: ";
    c.display();

    cout << "\nIs Circular: "
         << (c.isCircular() ? "True" : "False");


    // QUESTION 3(i) AND 4: DOUBLY LINKED LIST
    DoublyList d;

    d.insertEnd('R');
    d.insertEnd('A');
    d.insertEnd('D');
    d.insertEnd('A');
    d.insertEnd('R');

    cout << "\nDoubly List: ";
    d.display();

    cout << "\nSize: " << d.size();

    cout << "\nIs Palindrome: "
         << (d.isPalindrome() ? "True" : "False");

}
