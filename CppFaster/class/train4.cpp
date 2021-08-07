#include <iostream>
using namespace std;

struct LinkNode {
    int data;
    LinkNode* next;
};

class List {
protected:
    List() = default;
public:
    virtual ~List() {}
    virtual void mystore(int data) = 0;
    virtual int retrieve(int n) = 0;
};

class myqueue : public List{
public:
    myqueue() = default;
    myqueue(int d) { mystore(d); }
    void mystore(int data) {
        LinkNode* q = new LinkNode;
        q->data = data;
        q->next = nullptr;
        if (queue == nullptr) {
            queue = q;
            head = q;
        } else {
            queue->next = q;
            queue = queue->next;
        }
    }
    int retrieve(int n) {
        LinkNode* phead = head;
        int count = 1;
        while (phead != nullptr && count != n) {
            phead = phead->next;
            count++;
        }
        if (phead != nullptr)   return phead->data;
        return -1;
    }
    ~myqueue() {
        LinkNode* phead = head;
        while (phead != nullptr) {
            LinkNode* temp = phead;
            phead = phead->next;
            delete temp;
        }
        queue = head = nullptr;
    }
    void print() {
        LinkNode* p = head;
        while (p != nullptr) {
            cout << p->data << endl;
            p = p->next;
        }
    }
private:
    LinkNode* queue = nullptr;
    LinkNode* head = nullptr;
};

class mystack : public List{
public:
    mystack() = default;
    mystack(int d) { mystore(d); }
    void mystore(int data) {
        LinkNode* q = new LinkNode;
        q->data = data;
        q->next = nullptr;
        if (stack == nullptr) {
            stack = q;
        } else {
            q->next = stack;
            stack = q;
        }
    }
    int retrieve(int n) {
        LinkNode* slow = stack;
        LinkNode* fast = stack;
        for (int i=0; i<n; i++)
            fast = fast->next;
        if (fast == nullptr) {
            return slow->data;
        }
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
    ~mystack() {
        LinkNode* head = stack;
        while (head != nullptr) {
            LinkNode* temp = head;
            head = head->next;
            delete temp;
        }
        stack = nullptr;
    }
private:
    LinkNode* stack = nullptr;
};

int main()
{
    myqueue m(1);
    m.mystore(2);
    m.mystore(3);
    // m.print();
    cout << m.retrieve(3);
    cout << endl;

    mystack s(1);
    s.mystore(2);
    s.mystore(3);
    cout << s.retrieve(1);
}