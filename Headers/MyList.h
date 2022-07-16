#include <iostream>
#include <string>


template<class  T>
class Node
{
    public:

    T val;
    Node* next;
    Node() // конструктор по умолчанию
    {
        val = 0;
        next = nullptr;
    };
    Node(T _val) : val(_val), next(nullptr) {}

};

template<class T>
class Iter
{
    public:

    Node<T>* now;
    Iter(): now() {};
    Iter(Node<T>* _ptr) {
        if (_ptr->next != nullptr) now = _ptr;
    }
    Iter& operator++() {
        now = now->next;
        return *this;
    }
    Iter<T> operator++(int)
    {
        Node<T>* ab=now;
        now = now->next;
        Iter<T> it(ab);
        return it;
    }
    T& operator*() {
        return now->val;
    }
    bool operator!=(const Iter<T>& itl) {
        return now != itl.now;
    }
    bool operator==(const Iter<T>& itl) {
        return now== itl.now;
    }

};

template<class  T>
class MyList
{
    Node<T>* first;
    Node<T>* last;
    public:
    MyList() : first(), last() {}
    bool is_empty() {
        return first == nullptr;
    }
    void push_back(T _val) 
    {
        Node<T>* p = new Node<T>(_val);
        if (is_empty()) 
        {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }
    void push_front(T _val) 
    {
        Node<T>* p = new Node<T>(_val);
        if (is_empty()) {
        first = p;
        last = p;
        return;
        }
        p->next = first;
        first = p;
    }
    void push_after(T _val, Iter<T> it)
    {
        Node<T>* p = new Node<T>(_val);
        if (is_empty())
        {
            first = p;
            last = p;
            return;
        }
        p->next = it->now->next;
        it->now->next = *p;
    }
    T take(Iter<T> it) {
        return it.now->val;
    }
    T take_back() {
        return last->val;
    }
    T take_front() {
        return first->val;
    }
    void remove_after(Iter<T> it){
        Iter<T> its = it.now->next;
        it.now->next = its.now->next;
        delete its.now;
    }
    void remove_first(){
        first = first->next;
    }
    void remove_last(){
        last->val = NULL;
    }
    Iter<T> begin(){
        return first;
    }
    Iter<T> end(){
        return last;
    }
};

template<class T>
std::ostream& operator<<(std::ostream& o, MyList<T>& l)
{
    Iter<T> it = l.begin();
    Iter<T> endIt = l.end();
    for (; it != endIt; it++) {
        T a = *it;
        o << *it << std::endl;
    }
    return o;
}