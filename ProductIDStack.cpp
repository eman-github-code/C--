#include <iostream>
using namespace std;

// --------------------- Product Class ---------------------
class Product {
private:
    int productId;
    int data;
    Product* next;

public:
    Product() {
        productId = 0;
        data = 0;
        next = NULL;
    }

    int getData() {
        return data;
    }

    void setData(int val) {
        data = val;
    }

    Product* getNext() {
        return next;
    }

    void setNext(Product* n) {
        next = n;
    }

    int getProductId() {
        return productId;
    }

    void setProductId(int pid) {
        productId = pid;
    }
};

// --------------------- Stack Class ---------------------
class Stack {
private:
    Product* head;

public:
    Stack() {
        head = NULL;
    }

    void push(int x) {
        Product* temp = new Product();
        temp->setData(x);
        temp->setNext(head);
        head = temp;
    }

    int pop() {
        if (head == NULL) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int value = head->getData();
        Product* temp = head;
        head = head->getNext();
        delete temp;
        return value;
    }

    int top() {
        if (head == NULL) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return head->getData();
    }

    bool isEmpty() {
        return head == NULL;
    }
};

// --------------------- Main Program ---------------------
int main() {
    Stack stack;
    Product product;

    int id;
    cout << "Enter a 4-digit Product ID: ";
    cin >> id;

    // Validate input
    if (id < 1000 || id > 9999) {
        cout << " Invalid ID! Please enter a 4-digit number." << endl;
        return 0;
    }

    product.setProductId(id);
    cout << "\n Product ID set to: " << product.getProductId() << endl;

    // Push digits to stack
    int temp = product.getProductId();
    cout << " Pushing digits to stack:" << endl;
    while (temp > 0) {
        int digit = temp % 10;
        stack.push(digit);
        cout << " Pushed: " << digit << endl;
        temp /= 10;
    }

    // Top of stack
    cout << "\n Top of stack: " << stack.top() << endl;

    // Pop 2 elements
    cout << " Popped: " << stack.pop() << endl;
    cout << " Popped: " << stack.pop() << endl;

    // New top
    cout << " New top of stack: " << stack.top() << endl;

    return 0;
}

