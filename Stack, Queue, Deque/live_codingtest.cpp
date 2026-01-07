# include <iostream>
# include <string>
# include <vector>

using namespace std;
const int MAX_SIZE= 1e4;


class Tree {
    struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data): data(data), left(nullptr), right(nullptr) {}
    };

public:
    void preorder(TreeNode* root) {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        cout<< root->data << " ";
        inorder(root->right);
    }

    void postorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        postorder(root->left);
        postorder(root->right);

        cout << root->data << " ";
    }

    void tree_start() {
        TreeNode* node = new TreeNode(1);
        node->left= new TreeNode(2);
        node->right = new TreeNode(3);
    }
};

class Max_Heap {
    vector<int> heap = {0};
public:
    bool is_empty() {
        return heap.size()<=1;
    }

    int get_size() {
        return heap.size()-1;
    }
    void sift_up(int index) {
        while (index>1) {
            if (heap[index] > heap[index/2]) {
                swap(heap[index], heap[index/2]);
                index /= 2;
            } else {
                break;
            }
        }
    }
    void sift_down(int index) {
        int n = heap.size();

        while (1) {
            int left = 2*(index);
            int right = 2*(index) + 1;
            int current_index = index;
            if (left < n && heap[left] > heap[current_index]) {
                current_index = left;
            }
            if (right < n && heap[right] > heap[current_index]) {
                current_index = right;
            }
            if (current_index == index) {
                break;
            }
            swap(heap[index], heap[current_index]);
            index = current_index;
        }
    }
    int top() {
        if (is_empty()) {
            return -1;
        }
        return heap[1];
    }

    void push(int data) {
        heap.push_back(data);
        sift_up(heap.size()-1);
    }

    int pop() {
        if (is_empty()) {
            return -1;
        }
        int num = heap[1];
        heap[1] = heap[heap.size()-1];
        heap.pop_back();
        if (heap.size()>1) {
            sift_down(1);
        }
        return num;
    }
};
class Array_queue {
    int head=0, tail=0, size= 0;
    int arr[MAX_SIZE]= {0};

public:
    bool is_empty() {
        return size==0;
    }

    bool is_full() {
        return size == MAX_SIZE-1;
    }
    int front() {
        if (is_empty()) {
            return -1;
        }
        return arr[head];
    }
    void enqueue(int data) {
        if (is_full()) {
            return;
        }
        arr[tail] = data;
        tail = (tail+1)%MAX_SIZE;
        size++;
    }

    int dequeue() {
        if (is_empty()) {
            return -1;
        }
        int num = arr[head];
        head = (head+1) %MAX_SIZE;

        size--;
        return num;
    }
};

class Linked_queue {
    struct Node {
        int data;
        Node* next;
        Node(int data, Node* next): data(data), next(next) {}
    };
    Node* head;
    Node* tail;
public:
    Linked_queue(): head(nullptr), tail(nullptr){}
    bool is_empty() {
        return head == nullptr;
    }
    int dequeue() {
        if (is_empty()) {
            return -1;
        }

        Node* del = head;
        int num = head->data;
        head = head->next;

        if (head == nullptr) {
            tail=nullptr;
        }
        delete del;
        return num;
    }

    void enqueue(int data) {
        Node* new_node = new Node(data, nullptr);
        if (is_empty()) {
            head = tail = new_node;
            return;
        }
        tail -> next = new_node;
        tail = new_node;
    }
};

class Linked_stack {
    struct Node {
        int data;
        Node* next;
        Node(int data, Node* next): data(data), next(next) {}
    };

    Node* top;
public:
    Linked_stack(): top(nullptr) {}

    bool is_empty() {
        return top == nullptr;
    }

    void push(int data) {
        top = new Node(data, top);
    }

    int pop() {
        if (is_empty()) {
            return -1;
        }
        Node* del = top;
        int num = top->data;
        top = top->next;
        delete del;
        return num;
    }
};


class Array_stack {
    int stack_point;
    int stacks[10000]={0};
public:
    Array_stack(): stack_point(-1), stacks() {}

    bool is_full() {
        return stack_point == MAX_SIZE-1;
    }

    bool is_empty() {
        return stack_point == -1 ;
    }
    void push(int num) {
        if (is_full()) {
            return;
        }
        stacks[++stack_point] = num;
    }

    int pop() {
        if (is_empty()) {
            return -1;
        }
        return stacks[stack_point--];
    }
};

class Arrays {
    public:
        void arrays() {
            // 배열 회전
            int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};

            int temp = arr[0];
            for (int i=0; i<7; i++) {
                arr[i] = arr[i+1];
            }
            arr[7] = temp;

            for (int i=0; i<8; i++) {
                cout << arr[i] << " ";
            }


        }
};

class Array_list {
    private:
        struct Node {
            int data;
            Node* next;
            Node(int v) : data(v), next(nullptr) {}
        };
        Node* head = nullptr;
        Node* tail = nullptr;
        int size=0;


    public:
        Array_list(): head(nullptr), tail(nullptr), size(0) {}

        void add_at_head(int val) {
            Node* next_node = new Node(val);
            next_node->next = head;
            head = next_node;
            if (size ==0) {
                tail= next_node;
            }
            size++;
        }

        void add_at_tail(int val) {
            Node* node = new Node(val);
            if (size==0) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            size++;

        }

        int get_value(int val) {
            Node* current = head;
            int index = 0;
            while (current) {
                if (current->data == val) {
                    cout << index << endl;
                    return index;
                }
                current = current->next;
                index++;
            }
            return -1;
        }

        void add_at_index(int val, int index) {

            if (index==0) {
                add_at_head(val);
                return;
            }
            if (index == size) {
                add_at_tail(val);
                return;
            }
            Node* current = head;
            for (int i=0; i<index-1; i++) {
                current = current->next;
            }
            Node* node = new Node(val);
            node->next = current->next;
            current->next = node;
            size++;
        }

        void delete_at_value(int val) {
            if (head == nullptr) {
                return;
            }

            if (head->data == val) {
                Node* del = head;
                head = head->next;
                if (size ==1) {
                    tail = nullptr;
                }
                delete del;
                size--;
                return;
            }

            Node* current = head;
            while (current->next) {
                if (current->next->data == val) {
                    Node* del = current->next;
                    current->next = del->next;
                    if (del == tail) {
                        tail = current;
                    }
                    delete del;
                    size--;
                    return;
                }
                current = current->next;

            }

        }
};


int main() {

    // 연결리스트 구현
    Array_list array_list; // 객체 생성 + 생성자 자동 호출

    return 0;
}