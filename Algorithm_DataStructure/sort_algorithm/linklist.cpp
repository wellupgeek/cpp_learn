#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

template <typename T>
struct LinkNode {
    T data;
    LinkNode* next;
    LinkNode() : data(0), next(nullptr) {}
    LinkNode(T d) : data(d), next(nullptr) {}
    LinkNode(T d, LinkNode* l) : data(d), next(l) {}
};

template <typename T>
LinkNode<T>* getLinkNode(LinkNode<T>* head, int pos) {
    int n = 0;
    while (head != nullptr && n != pos) {
        head = head->next;
        n++;
    }
    return head;
}

template <typename T>
void merge(LinkNode<T>* head, int l, int mid, int r) {
    LinkNode<T>* p = head;
    T* phead = new T[r-l+1];
    int count = 0;
    LinkNode<T>* pl = getLinkNode(head, l);
    LinkNode<T>* pr = getLinkNode(head, mid+1);
    LinkNode<T>* pltemp = pl;
    int i = l, j = mid + 1, k=0;
    while (i <= mid && j <= r && pl != nullptr && pr != nullptr) {
        if (pl->data < pr->data){
            phead[k++] = pl->data;
            pl = pl->next;
            i++;
        }
        else {
            phead[k++] = pr->data;
            pr = pr->next;
            j++;
        }
    }
    while (i <= mid && pl != nullptr) {
        phead[k++] = pl->data;
        pl = pl->next;
        i++;
    }
    while (j <= r && pr != nullptr) {
        phead[k++] = pr->data;
        pr = pr->next;
        j++;
    }
    for (int i=0; i<k && pltemp != nullptr; ++i) {
        pltemp->data = phead[i];
        pltemp = pltemp->next;
    }
    delete[] phead;
}

template <typename T>
int getLinkLength(LinkNode<T>* head) {
    LinkNode<T>* phead = head;
    int count = 0;
    while (phead != nullptr) {
        count++;
        phead = phead->next;
    }
    return count;
}

template <typename T>
void mergeSort(LinkNode<T>* head, int n) {
    for (int sz=1; sz<=n; sz*=2) {
        for (int i=0; i+sz<n; i+=sz*2) {
            merge(head, i, i+sz-1, min(i+2*sz-1, n-1));
        }
    }
}

template <typename T>
LinkNode<T>* generateList(int n, int rangeL, int rangeR) {
    LinkNode<T>* head = new LinkNode<T>();
    LinkNode<T>* temp = head;
    srand(time(NULL));
    for (int i=0; i<n; ++i) {
        LinkNode<T>* tnode = new LinkNode<T>();
        tnode->data = rand() % (rangeR - rangeL + 1) + rangeL;
        temp->next = tnode;
        temp = temp->next;
    }
    temp->next = nullptr;
    return head->next;
}

template <typename T>
bool isSorted2(LinkNode<T>* head, int n) {
    LinkNode<T>* slow = head;
    LinkNode<T>* fast = head->next;
    while (slow != nullptr && fast != nullptr) {
        if (slow->data > fast->data)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

template <typename T>
void testSort2(LinkNode<T>* head, int n, void(*sort)(LinkNode<T>*, int)) {
    clock_t startTime = clock();
    sort(head, n);
    clock_t endTime = clock();
    LinkNode<T>* temp = head;
    assert(isSorted2(head, n));
    std::cout << "use time : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << "\n";
    return ;
}

int main() {
    int n = 100000;
    LinkNode<int>* head = generateList<int>(n, 0, n);
    LinkNode<int>* t = head;
    int len = getLinkLength(head);
    testSort2(head, len, mergeSort);
}