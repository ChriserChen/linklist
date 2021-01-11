#include <iostream>

using namespace std;

//节点
struct Node {
    int number;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node(Node *prev, int number, Node *next) : prev(prev), number(number), next(next) {}

};

//链表
struct LinkList {
    int length = 0;
    Node *first = nullptr;
    Node *last = nullptr;
};


//增加元素
void add(LinkList *list, int number) {
    Node *l = list->last;
    Node *newNode = new Node(l, number, nullptr);
    list->last = newNode;
    if (l == nullptr)
        list->first = newNode;
    else
        l->next = newNode;
    list->length = list->length + 1;
}

//删除元素
void remove(LinkList *list, int number) {
    Node *x = list->first;
    if (number == -1) {
        cout << "元素不存在" << endl;
        return;
    }
    for (; x != nullptr; x = x->next) {
        if (number == x->number) {
            Node *next = x->next;
            Node *prev = x->prev;

            if (prev == nullptr) {
                list->first = next;
            } else {
                prev->next = next;
                x->prev = nullptr;
            }

            if (next == nullptr) {
                list->last = prev;
            } else {
                next->prev = prev;
                x->next = nullptr;
            }
            x->number = NULL;
            list->length = list->length - 1;
            return;
        }
    }
    cout << "元素不存在" << endl;
}


//打印
void print(LinkList *list) {
    Node *tmp = list->first;
    for (int i = 0; i < list->length; ++i) {
        cout << tmp->number << " ";
        if (tmp->next == nullptr) {
            break;
        }
        tmp = tmp->next;
    }
}


int main() {
    cout << "输入数字空格分割，-1结束:" << endl;
    auto *linkList = new LinkList();
    int number;
    while (cin >> number) {
        if (number == -1) {
            break;
        }
        add(linkList, number);
    }

    cout << "输入要删除的数:" << endl;
    int removeNumber;
    cin >> removeNumber;

    remove(linkList, removeNumber);

    print(linkList);
    return 0;
}


