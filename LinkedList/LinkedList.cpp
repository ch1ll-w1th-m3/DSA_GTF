#include <bits/stdc++.h>
using namespace std; 

struct Data {
    int num; 
};

struct NODE {
    Data info; 
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
    p->info.num = x; 
    p->pNext = NULL; 
    return p; 
}

// them vao dau danh sach 
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

void AddAfterQ(LIST &list, NODE* p, NODE* Q) {
    if (Q != NULL) {
        p->pNext = Q->pNext; 
        Q->pNext = p; 
        if (list.pTail == Q) list.pTail = p; 
    }
    else AddHead(list, p); 
}

NODE* SearchNode(LIST list, int x) {
    NODE* p = list.pHead; 
    while (p != NULL && p->info.num != x) p = p->pNext; 
    return p; 
}

bool RemoveHead(LIST &list, int &x) {
    NODE* p; 
    if (list.pHead != NULL) {
        x = list.pHead->info.num; 
        p = list.pHead; 
        list.pHead = list.pHead->pNext; 
        if (list.pHead == NULL) list.pTail == NULL; 
        delete p; 
        return 1; 
    }
    return 0; 
}

bool RemoveAfterQ(LIST &list, NODE *Q) {
    NODE* p; 
    if (Q != NULL) {
        p = Q->pNext; 
        if (p != NULL) {
            if (p == list.pTail) list.pTail = Q; 
            Q->pNext = p->pNext; 
            delete p; 
        }
        return 1; 
    }
    return 0; 
}

bool RemoveX(LIST &list, int x) {
    NODE *Q, *p; 
    Q = NULL; 
    p = list.pHead; 
    while (p != NULL && p->info.num != x) {
        Q = p; 
        p = p->pNext; 
    }

    if (p == NULL) return 0; // khong tim thay x trong list
    if (Q != NULL) RemoveAfterQ(list, Q); 
    else RemoveHead(list, x); 
    return 1; 
}

void PrintList(LIST list) {
    NODE* p; 
    if (list.pHead == NULL) cout << "DSLK rong."; 
    else {
        p = list.pHead; 
        while (p) {
            cout << p->info.num << ' '; 
            p = p->pNext; 
        }
    }
}

void RemoveList(LIST &list) {
    NODE* p; 
    while (list.pHead != NULL) {
        p = list.pHead; 
        list.pHead = p->pNext; 
        delete p; 
    }
    list.pTail = NULL; 
}

int main() {
    LIST list; 
    CreateEmptyList(list); 
    AddTail(list, CreateNode(5)); 
    AddTail(list, CreateNode(10)); 
    AddHead(list, CreateNode(9)); 
    AddAfterQ(list, CreateNode(3), SearchNode(list, 5)); 
    PrintList(list); 
}
