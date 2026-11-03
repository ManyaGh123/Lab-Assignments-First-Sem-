
#include <iostream>
using namespace std;

class LinkedList {
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

    LinkedList() {
        head = NULL;
    }

    // QUESTION 1(a): INSERTION AT BEGINNING
    void insertBeginning(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;
    }

    // QUESTION 1(b): INSERTION AT END
    void insertEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // QUESTION 1(c): INSERT BEFORE A SPECIFIC VALUE
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

        while (temp->next != NULL &&
               temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Node not found";
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // QUESTION 1(c): INSERT AFTER A SPECIFIC VALUE
    void insertAfter(int key, int val) {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Node not found";
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // QUESTION 1(d): DELETION FROM BEGINNING
    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;
    }

    // QUESTION 1(e): DELETION FROM END
    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    // QUESTION 1(f): DELETE A SPECIFIC NODE
    void deleteSpecific(int key) {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        if (head->data == key) {
            deleteBeginning();
            return;
        }

        Node* temp = head;

        while (temp->next != NULL &&
               temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Node not found";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;

        delete del;
    }

    // QUESTION 1(g): SEARCH AND DISPLAY POSITION
    void search(int key) {
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

    // QUESTION 1(h): DISPLAY ALL NODES
    void display() {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
    }


    // QUESTION 2: COUNT AND DELETE ALL OCCURRENCES
    int countAndDelete(int key) {
        int count = 0;

        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;

            delete temp;
            count++;
        }

        Node* temp = head;

        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data == key) {
                Node* del = temp->next;

                temp->next = del->next;
                delete del;

                count++;
            }
            else {
                temp = temp->next;
            }
        }

        return count;
    }


    // QUESTION 3: FIND MIDDLE OF LINKED LIST
    int middle() {
        if (head == NULL) {
            cout << "List is empty";
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }


    // QUESTION 4: REVERSE LINKED LIST
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

int main() {
    LinkedList l;

    // QUESTION 1
    l.insertBeginning(30);
    l.insertEnd(40);
    l.insertBeginning(20);
    l.insertBefore(30, 35);
    l.insertAfter(40, 50);

    cout << "Linked List: ";
    l.display();

    cout << "\nSearch 35: ";
    l.search(35);

    l.deleteBeginning();
    l.deleteEnd();
    l.deleteSpecific(35);

    cout << "\nAfter deletion: ";
    l.display();


    // QUESTION 2
    LinkedList l2;

    l2.insertEnd(1);
    l2.insertEnd(2);
    l2.insertEnd(1);
    l2.insertEnd(2);
    l2.insertEnd(1);
    l2.insertEnd(3);
    l2.insertEnd(1);

    int count = l2.countAndDelete(1);

    cout << "\nCount: " << count;
    cout << "\nUpdated List: ";
    l2.display();


    // QUESTION 3
    LinkedList l3;

    l3.insertEnd(1);
    l3.insertEnd(2);
    l3.insertEnd(3);
    l3.insertEnd(4);
    l3.insertEnd(5);

    cout << "\nMiddle: " << l3.middle();


    // QUESTION 4
    LinkedList l4;

    l4.insertEnd(1);
    l4.insertEnd(2);
    l4.insertEnd(3);
    l4.insertEnd(4);

    l4.reverse();

    cout << "\nReversed List: ";
    l4.display();

    return 0;
}
