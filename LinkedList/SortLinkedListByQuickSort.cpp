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

void CreateEmptyList(LIST &list) {
    list.pHead = NULL; 
    list.pTail = NULL;
}

void CreateList(LIST &list) {
    int x; 
    while (cin >> x) {
        if (x == -1) return; 
        AddHead(list, CreateNode(x)); 
    }
}

NODE* SeparateHead(LIST &list) {
    NODE* p = list.pHead; 
    if (list.pHead == NULL) return NULL; 
    list.pHead = list.pHead->pNext; 
    if (list.pHead == NULL) list.pTail = NULL; 
    p->pNext = NULL;
    return p; 
}

void Partition(LIST &list, LIST &listLeft, NODE*& pivot, LIST &listRight) {
    NODE* p; 
    if (list.pHead == NULL) return; 
    pivot = SeparateHead(list); 
    while (list.pHead != NULL) {
        p = SeparateHead(list); 
        if (p -> num <= pivot -> num) AddTail(listLeft, p); 
        else AddTail(listRight, p); 
    }
}

void Join(LIST &list, LIST &listLeft, NODE* pivot, LIST &listRight) {
    NODE* p; 
    while (listLeft.pHead != NULL) {
        p = SeparateHead(listLeft); 
        AddTail(list, p); 
    }
    AddTail(list, pivot); 
    while (listRight.pHead != NULL) {
        p = SeparateHead(listRight); 
        AddTail(list, p); 
    }
}

void QuickSort(LIST &list) {
    LIST listLeft, listRight; 
    CreateEmptyList(listLeft); 
    CreateEmptyList(listRight); 

    NODE* pivot; 
    Partition(list, listLeft, pivot, listRight); 

    if (listLeft.pHead != listLeft.pTail) QuickSort(listLeft); 
    if (listRight.pHead != listRight.pTail) QuickSort(listRight); 

    Join(list, listLeft, pivot, listRight); 
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
    QuickSort(list); 
    PrintList(list); 
}