#include <iostream>
#include <type_traits>

// Linked List
// n 개의 Node 가 순서대로 연결된 형태의 자료구조입니다.
// head, tail 을 필수로 포함해주세요.

// Node
// 정수형 값과 노드를 가리키는 포인터로 구성되어 있습니다.


class Node {

public:
    int data;
    Node* next;
    Node(int data): data(data), next(nullptr) {}
};

class LinkedList {
    Node* head=nullptr;
    Node* tail=nullptr;
    int counts=0;
public:
    void append(int value) {

        Node* next_node = new Node(value);

        if(head == nullptr) {
            head=next_node;
            tail = next_node;
            return;
        }
        tail->next = next_node;
        tail = next_node;
        counts++;
    }

    void remove(int value) {
        if(isEmpty()) {
            return;
        }

        if (head->data==value) {
            Node* del = head;
            head = head->next;
            delete del;
            counts--;
            if (!head) {
                tail = nullptr;
            }
            return;
        }
        Node* current_node = head;

        while (current_node->next) {
            if (current_node->next->data == value) {
                Node* del = current_node->next;
                current_node->next = del->next;
                if (tail==del) {
                    tail = current_node;
                }
                delete del;
                counts--;

                return;
            }
            current_node = current_node->next;
        }

    }

    bool isEmpty() {
        if(head==nullptr) {
            return true;
        }
        return false;
    }

    int size() {

        return counts;
    }

    void print() {

        Node* current_node = head;

        while(current_node) {
            std::cout << current_node->data << " ";
            current_node = current_node->next;
        }
    }
};

int main() {

    LinkedList linkedList;
    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);
    linkedList.remove(2);
    linkedList.print();

    return 0;
}