#include <iostream>

using namespace std;

class Queue{
private:
    int data;
    Queue* head;
    Queue* next;
    Queue *prev;
    Queue* tail;

public:
    Queue(const int &value) : data(value), tail(nullptr), head(nullptr), next(nullptr), prev(nullptr) {}
    Queue() : data(0), head(nullptr), next(nullptr), tail(nullptr), prev(nullptr) {}
    ~Queue(){
        clear();
    }
    void push_back(int value){
        Queue *newNode = new Queue(value);
        if(tail){
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else tail = head = newNode;
        cout << "ok" << endl;
    }
    void push_front(int value){
        Queue *newNode = new Queue(value);
        if(head){
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else tail = head = newNode;
        cout << "ok" << endl;
    }
    
    void pop_front() {
        if (!head) {
            cout << "error" << endl;
            return;
        }
        cout << head->data << endl;
        Queue* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "error" << endl;
            return;
        }
        cout << tail->data << endl;
        Queue* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }
    
    void front(){
        if(tail == nullptr){
            cout << "error" << endl;
            return;
        }
        cout << head->data << endl;
    
    }
    void back(){
        if(tail == nullptr){
            cout << "error" << endl;
            return;
        }
        cout << tail->data << endl;
    }
    
    void size() {
        int size = 0;
        Queue* current = head;  // Начинаем с головы
        while (current != nullptr) {
            current = current->next;
            size++;
        }
        cout << size << endl;
    }
    
    void clear(){
        while(head != nullptr){
            Queue* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }


};


int main(){
    Queue head;
    string str;
    do
    {
        cin >> str;
        if(str == "push_front"){
            int n;
            cin >> n;
            head.push_front(n);
        }
        else if(str == "push_back"){
            int n;
            cin >> n;
            head.push_back(n);
        }
        else if(str == "pop_back"){
            head.pop_back();
        }
        else if(str == "pop_front"){
            head.pop_front();
        }
        else if(str == "front"){
            head.front();
        }
        else if(str == "back") head.back();
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
