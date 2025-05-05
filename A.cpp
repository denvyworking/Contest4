#include <iostream>

using namespace std;

struct Stack{
    int data;
    Stack * next;
    Stack(const int& value) : data(value), next(nullptr) {}
};

void push(int value, Stack*& head){
    Stack *newNode = new Stack(value);
    if(head){
        newNode->next = head;
        head = newNode;
    }
    else head = newNode;
    cout << "ok" << endl;
}

void pop(Stack *&head){
    if(head == nullptr){
        cout << "error" << endl;
        return;
    }
    Stack *newNode = head;
    cout << newNode->data << endl;
    head = head->next;
    delete newNode;
}

void back(Stack *&head){
    if(head == nullptr){
        cout << "error" << endl;
        return;
    }
    cout << head->data << endl;

}

void size(Stack *head){
    int size = 0;
    Stack *newNode = head;
    while(newNode != nullptr){
        newNode = newNode->next;
        size++;
    }
    cout << size << endl;
}

void clear(Stack *&head){
    while(head != nullptr){
        Stack *newNode = head;
        head = head->next;
        delete newNode;
    }
    cout << "ok" << endl;
}




int main(){
    Stack *head = nullptr;
    string str;
    do
    {
        cin >> str;
        if(str == "push"){
            int n;
            cin >> n;
            push(n , head);
        }
        else if(str == "pop"){
            pop(head);
        }
        else if(str == "back"){
            back(head);
        }
        else if(str == "size"){
            size(head);
        }
        else if(str == "clear"){
            clear(head);
        }
    } while (str != "exit");
    cout << "bye" << endl;
    return 0;
}
