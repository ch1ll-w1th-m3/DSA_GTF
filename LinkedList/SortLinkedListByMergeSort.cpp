#include <bits/stdc++.h>
using namespace std; 

struct NODE {
    int num; 
    NODE* pNext; 
}; 

struct LIST {
    NODE* pHead; 
    NODE* pTail; 
};

void CreateEmptyList(LIST &list) {
    list.pHead = NULL; 
    list.pTail = NULL; 
}

NODE* CreateNode(int x) {
    NODE* p = new NODE; 
    if (p == NULL) exit(1); 
    p->num = x; 
    p->pNext = NULL;
    return p; 
}

void AddHead(LIST &list, NODE* p) {
    if (list.pHead == NULL) {
        list.pHead = p; 
        list.pTail = list.pHead;
    }
    else {
        p->pNext = list.pHead; 
        list.pHead = p; 
    }
}

void AddTail(LIST &list, NODE* p) {
    if (list.pHead == NULL) {
        list.pHead = p; 
        list.pTail = list.pHead; 
    }
    else {
        list.pTail->pNext = p; 
        list.pTail = p; 
    }
}

void CreateList(LIST &list) {
    int x;
    while (cin >> x) {
        if (x == -1) return; 
        AddTail(list, CreateNode(x)); 
    }
}

NODE* SeparateHead(LIST &list) {
    NODE* p = list.pHead; 
    if (list.pHead == NULL) return NULL; 
    list.pHead = list.pHead->pNext; 
    if (list.pHead == NULL) list.pTail = list.pHead; 
    p->pNext = NULL; 
    return p; 
}

void MergeSplit(LIST &list, LIST &listLeft, LIST &listRight) {
    NODE* p; 
    CreateEmptyList(listLeft); 
    CreateEmptyList(listRight); 
    while (list.pHead != NULL) {
        p = SeparateHead(list); 
        AddTail(listLeft, p); 
        if (list.pHead != NULL) {
            p = SeparateHead(list); 
            AddTail(listRight, p); 
        }
    }
}

void Merge(LIST &list, LIST &listLeft, LIST &listRight) {
    CreateEmptyList(list);
    NODE* p; 
    while (listLeft.pHead != NULL && listRight.pHead != NULL) {
        if (listLeft.pHead->num <= listRight.pHead->num) p = SeparateHead(listLeft); 
        else p = SeparateHead(listRight); 
        AddTail(list, p); 
    }
    while (listLeft.pHead != NULL) {
        p = SeparateHead(listLeft); 
        AddTail(list, p); 
    }
    while (listRight.pHead != NULL) {
        p = SeparateHead(listRight); 
        AddTail(list, p); 
    }
}

void MergeSort(LIST &list) {
    if (list.pHead == list.pTail) return; 
    LIST listLeft, listRight; 
    MergeSplit(list, listLeft, listRight); 
    MergeSort(listLeft); 
    MergeSort(listRight); 
    Merge(list, listLeft, listRight); 
}

void PrintList(LIST list) {
    NODE* p; 
    if (list.pHead == NULL) {
        cout << "Empty List."; 
        return; 
    }
    p = list.pHead;
    while (p != NULL) {
        cout << p->num << ' ';
        p = p->pNext; 
    }
}

int main() {
    LIST list; 
    CreateEmptyList(list); 
    CreateList(list); 
    MergeSort(list); 
    PrintList(list); 
}