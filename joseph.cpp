/*************************************************************************
	> File Name: joseph.cpp
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年12月26日 星期三 16时21分56秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct NewNode {
    int data;
    int password;
    NewNode *next;
} Node;

class joseph {

public:
    //joseph();
    void init();
    Node *GetNewNode(int data, int password);
    void insert(int n);
    void erase(int m);

private:
    Node *tail;
    int length;
};

void joseph::init() {
    tail = new Node;
    length = 0;
    tail->next = NULL;
    return ;
}

Node *joseph::GetNewNode(int data, int password) {
    Node *p = new Node;
    p->data = data;
    p->password = password;
    p->next = NULL;
    return p;
}

void joseph::insert(int n) {
    if(n == 0) {
        cout << "输入错误,请输入正确的n值";
        return ;
    }
    int m;
    Node *p, *q;
    cout << "请输入" << n << "个人的密码" << endl;
    length = n;
    //创建头结点
    cout << "第1个人的密码 : ";
    cin >> m;
    tail->data = 1;
    tail->password = m;
    tail->next = tail;
    for(int i = 2; i <= n; i++) {
        cout << "第" << i <<  "个人的密码 : ";
        cin >> m;
        p = GetNewNode(i, m);
        p->next = tail->next;
        tail->next = p;
        tail = p;
    }
    return ;
}

void joseph::erase(int m) {
    Node *p = tail, *q;
    while(length--) {
        while(--m) {
            p = p->next;
        }
        q = p->next;
        m = q->password;
        cout << q->data << " ";
        p->next = q->next;
        delete q;
    }
    cout << endl;
    return ;
}

int main() {
    int n, m;
    joseph jos;
    cout << "请输入 m 和 n" << endl;
    cin >> m >> n;
    
    jos.init();
    jos.insert(n);
    jos.erase(m);

    return 0;
}
