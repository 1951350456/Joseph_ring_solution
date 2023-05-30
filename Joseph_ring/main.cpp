#include <bits/stdc++.h>
using namespace std;
//单循环节点
struct c_node {
    int data;
    c_node *next;
    c_node(){
        data;
        next = NULL;
    }
};
//不带头节点无尾指针单循环链表
class c_list0
{
public:
    c_node *head;
    c_list0(){head = new c_node;head->next = NULL;}
    c_list0(int n){
        head = new c_node;
        head = NULL;
        if(n <= 0) return;
        cout << "请输入各节点数据： " << endl;
        c_node *d = head;
        c_node *m = new c_node;
        cin >> m->data;
        head = m;
        delete d;
        c_node *ptr = head;
        for (int i = 1; i < n; i++) {
            c_node *c = new c_node;
            cin >> c->data;
            ptr->next = c;
            ptr = ptr->next;
        }
        ptr->next = head;
    }
    ~c_list0(){
        if(!head)return;
        c_node *p = head->next;
        while(p!=head){
            c_node *ptr = p;
            p = p->next;
            delete ptr;
        }
        delete p;
    }
    //复制构造函数
    c_list0(const c_list0 &m){
        head = new c_node;
        head->data =m.head->data;
        c_node *ptr1 =head;
        c_node *ptr2 = m.head->next;
        while(ptr2!=head){
            c_node *ptr = new c_node;
            ptr->data = ptr2->data;
            ptr1->next = ptr;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = head;
    }
    //在尾部加入节点
    void add_node(int data){
        c_node *ptr = head->next;
        while(ptr->next!=head){
            ptr = ptr->next;
        }
        c_node *p = new c_node;
        p->data = data;
        ptr->next = p;
        ptr = ptr->next;
        ptr->next = head;
    }
    //依次访问各节点并输出数据
    void Print(){
        if(!head)return;
        c_node *ptr = head;
        cout<<ptr->data<<" ";
        ptr = ptr->next;
        while(ptr != head){
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};
//创建约瑟夫环
c_list0 Joseph_ring(int n){
    c_list0 ring;
    int c = 1;
    c_node *ptr = ring.head;
    ptr->data = c;
    c++;
    for(; c <= n; c++){
        c_node *p = new c_node;
        p->data = c;
        ptr->next = p;
        ptr = ptr->next;
    }
    ptr->next = ring.head;
    return ring;
}
//约瑟夫环求解
int *Joseph(int n,int interval){
    int *result = new int[n-interval+1];
    int count = n;
    c_list0 ring = Joseph_ring(n);
    c_node *ptr1 = ring.head;
    for(int i = 0; i < n-1; i++){
        ptr1 = ptr1->next;
    }
    c_node *ptr2 = ring.head;
    while(count>=interval){
        for(int j = 0; j < 2; j++){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        result[n-count] = ptr2->data;
        c_node *p = ptr2;
        ptr2 = ptr2->next;
        ptr1->next = ptr2;
        delete p;
        ring.head = ptr2;
        count--;
    }
    return result;
}
int main(){
    int *result = Joseph(41,3);
    int bucket[42] = {0};
    for(int i = 0;i<39;i++){
        bucket[result[i]]++;
    }
    for(int i = 1;i<42;i++){
        if(!bucket[i]){
            cout<<i<<" ";
        }
    }
}