# Linked List

### CTDL của DSLK đơn
``` c++
// du lieu cua DSLK la 1 so nguyen
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
```

### Các thao tác cơ bản trên DSLK đơn 

* Tạo 1 danh sách liên kết đơn rỗng 
* Tạo 1 nút có trường info bằng x
* Thêm một phần tử có khóa x vào danh sách
* Duyệt danh sách 
* Tìm một phần tử có info bằng x
* Hủy một phần tử trong danh sách 
* Sắp xếp danh sách liên kết đơn

### Khởi tạo danh sách liên kết RỖNG 
``` c++ 
void CreateEmptyList(LIST &list) {
    list.pHead = NULL; 
    list.pTail = NULL; 
}
``` 

### Tạo 1 phần tử mới 
``` c++ 
NODE* CreateNode(int x) {
    NODE* p = new NODE; 
    if (p == NULL) exit(1); 
    p->info.num = x; 
    p->pNext = NULL; 
    return p; 
}
```

### Thêm 1 phần tử vào DSLK 
* Nguyên tắc thêm: Khi thêm 1 phần tử vào List thì làm cho pHead và pTail thay đổi. 
* Các vị trí cần thêm vào List: 
    + Thêm vào đầu List 
    + Thêm vào cuối List 
    + Thêm vào sau 1 phần tử Q trong List
``` c++ 
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

// them vao cuoi danh sach 
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

// them vao sau phan tu Q 
void AddAfterQ(LIST &list, NODE* p, NODE* Q) {
    if (Q != NULL) {
        p->pNext = Q->pNext; 
        Q->pNext = p; 
        if (list.pTail == Q) list.pTail = p; 
    }
    else AddHead(list, p); // Q o dau danh sach
}
```

### Tìm 1 phần tử trong DSLK đơn 
``` c++ 
// return NULL: khong tim thay 
NODE* SearchNode(LIST list, int x) {
    NODE* p = list.pHead; 
    while (p != NULL && p->info.num != x) p = p->pNext; 
    return p; 
}
```

### Hủy 1 phần tử trong DSLK đơn 
``` c++ 
// huy phan tu dau trong list 
// return 1: da xoa phan tu 
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

// huy phan tu dung sau phan tu Q
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

// huy phan tu co khoa x
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
```

### Duyệt danh sách 
``` c++ 
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
```

### Hủy toàn bộ danh sách 
``` c++ 
void RemoveList(LIST &list) {
    NODE* p; 
    while (list.pHead != NULL) {
        p = list.pHead; 
        list.pHead = p->pNext; 
        delete p; 
    }
    list.pTail = NULL; 
}
```

### Quá trình thêm từng phần tử vào danh sách 
``` c++ 
int main() {
    // tao 1 danh sach rong 
    LIST list; 
    CreateEmptyList(list); 

    // them 5 vao danh sach 
    AddTail(list, CreateNode(5)); 

    // them 10 vao danh sach 
    AddTail(list, CreateNode(10)); 

    // them 9 vao dau danh sach 
    AddHead(list, CreateNode(9)); 

    // them 3 vao sau 5 trong danh sach 
    AddAfterQ(list, CreateNode(3), SearchNode(list, 5)); 

    PrintList(list); 
}
```