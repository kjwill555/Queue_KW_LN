#include "LinkedList.cpp"
#include <vector>

using namespace std;

int main() {
    Node<int> one(1);
    Node<int> two(2);
    Node<int> three(3);
    Node<int> four(4);
    Node<int> five(5);
    
    Node<int> hundred(100);
    
    LinkedList<int> list;
    list.pushFront(five);
    list.pushFront(four);
    list.pushFront(three);
    list.pushFront(two);
    list.pushFront(one);
    list.printList();
    cout << endl;
    list.insertAt(hundred, 3);
    list.printList();
    cout << endl;
    list.clearList();
    list.printList();
    
    Queue <int> i_queue;
    i_queue.enque(one);
    i_queue.enque(two);
    i_queue.enque(three);
    i_queue.deque(three);
    i_queue.printQueue();
    cout<<endl;
    
    Node<string> name1("John");
    Node<string> name2("Adrian");
    Node<string> name3("James");
    Node<string> name4("Laura");
    
    Queue <string> s_queue;
    Queue <int> i_queue;
    i_queue.enque(name1);
    i_queue.enque(name2);
    i_queue.enque(name3);
    i_queue.deque(name1);
    i_queue.printQueue();
    i_queue.clearList();
    
    
    
    return 0;
}
