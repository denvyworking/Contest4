#include <iostream>

using namespace std;

class Queue{
private:
    int data;
    Queue* head;
    Queue* next;
    Queue* tail;

public:
    Queue(const int &value) : data(value), tail(nullptr), head(nullptr), next(nullptr) {}
    Queue() : data(0), head(nullptr), next(nullptr), tail(nullptr) {}
    ~Queue(){
        clear();
    }
    void push(int value){
        Queue *newNode = new Queue(value);
        if(tail){
            newNode->next = tail;
            tail = newNode;
        }
        else tail = head = newNode;
        cout << "ok" << endl;
    }
    
    void pop(){
        if(tail == nullptr){
            cout << "error" << endl;
            return;
        }
        else if(tail == head){
            cout << head->data << endl;
            Queue *delka = head;
            head = tail = nullptr;
            delete delka;
            return;
        }
        Queue *newNode = tail;
        while(newNode->next != head){
            newNode = newNode->next;
        }
        cout << head->data << endl;
        Queue *delka = head;
        newNode->next = nullptr;
        head = newNode;
        delete delka;
    }
    
    void front(){
        if(tail == nullptr){
            cout << "error" << endl;
            return;
        }
        cout << head->data << endl;
    
    }
    
    void size(){
        int size = 0;
        Queue *newNode = tail;
        while(newNode != nullptr){
            newNode = newNode->next;
            size++;
        }
        cout << size << endl;
    }
    
    void clear(){
        while(tail != nullptr){
            Queue *newNode = tail;
            tail = tail->next;
            delete newNode;
        }
        head = tail;
    }


};


int main(){
    Queue head;
    string str;
    do
    {
        cin >> str;
        if(str == "push"){
            int n;
            cin >> n;
            head.push(n);
        }
        else if(str == "pop"){
            head.pop();
        }
        else if(str == "front"){
            head.front();
        }
        else if(str == "size"){
            head.size();
        }
        else if(str == "clear"){
            head.clear();
            cout << "ok" << endl;
        }
    } while (str != "exit");
    cout << "bye" << endl;
    return 0;
}
