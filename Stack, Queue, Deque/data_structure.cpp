# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

/**
 * 스택큐
 */
struct Stack_Node {
    int data;
    Stack_Node* next;
    Stack_Node(int data) : data(data), next(nullptr) {}
};
Stack_Node* head = nullptr;

bool stack_empty() {
    return head==nullptr;
}

int stack_pop() {
    if (head==nullptr) {
        return -1;
    }
    int num = head->data;
    Stack_Node* deletes = head;
    head = head->next;
    delete deletes;
    return num;
}

void stack_push(int num) {
    Stack_Node* next_node = new Stack_Node(num);
    next_node->next = head;
    head = next_node;
}

int stack_front() {
    if (head==nullptr) {
        return -1;
    }
    return head->data;
}


/**
 * 원형큐
 */
int head_idx = 0;
int tail_idx = 0;
vector<int> que(1e4,0);
int size = 0;
bool is_empty_queue() {
    return size==0;
}

bool is_full_queue() {
    return size==1e4;
}
bool arr_enqueue(int x){
    if (is_full_queue()) {
        return false;
    }
    que[tail_idx] = x;
    tail_idx = (tail_idx+1)%10000;
    size++;
    return true;
}
int arr_dequeue() {
    if (is_empty_queue()) {
        return -1;
    }
    int num = que[head_idx];
    head_idx = (head_idx+1)%10000;
    size--;
    return num;
}
int front() {
    if (is_empty_queue()) {
        return -1;
    }

    return que[head_idx];
}


/**
 * 연결리스트 큐
 */
struct Queue {
    int value;
    Queue* next;
    Queue(int value): value(value), next(nullptr) {}
};
Queue* fronts=nullptr;
Queue* tail = nullptr;


bool queue_empty() {
    return fronts==nullptr;
}
int queue_front() {
    if (queue_empty()) {
        return -1;
    }

    return fronts->value;
}

void queue_enqueue(int value) {
    Queue* next_node = new Queue(value);
    if (queue_empty()) {
        fronts = tail = next_node;
        return;
    }
    tail->next = next_node;
    tail=next_node;
}

int queue_dequeue() {
    if (queue_empty()) {
        return -1;
    }
    int data = fronts->value;
    Queue* deletes = fronts;
    fronts = deletes->next;
    delete deletes;
    if (fronts==nullptr) {
        tail = nullptr;
    }
    return data;
}

/**
 * 트리
 */

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value): value(value), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* current) {
    if (current==nullptr) {
        return;
    }
    cout << current->value;
    preorder(current->left);
    preorder(current->right);
}
void inorder(TreeNode* current) {
    if (current==nullptr) {
        return;
    }

    preorder(current->left);
    cout << current->value;
    preorder(current->right);
}

void postorder(TreeNode* current) {
    if (current==nullptr) {
        return;
    }
    preorder(current->left);
    preorder(current->right);
    cout << current->value;
}

void treeNode() {
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->right->left = new TreeNode(5);

}
/**
 * 힙
 */
vector<int> heaps(1, 0);
int get_size_heap() {
    return heaps.size()-1;
}
int front_heap() {
    if (get_size_heap() == 0) {
        return -1;
    }
    return heaps.size()-1;
}
void sift_up_heap(int index) {

    while (index>1) {
        if (heaps[index] > heaps[index/2]) {
            swap(heaps[index], heaps[index/2]);
            index /=2;
        } else {
            break;
        }
    }
}

void sift_down_heap(int index) {
    int size = heaps.size();
    while (1) {
        int left_index = index *2;
        int right_index = index*2 + 1;
        int current_index = index;

        if (left_index <size && heaps[current_index] < heaps[left_index]) {
            current_index = left_index;
        }
        if (right_index < size &&heaps[current_index] < heaps[right_index]) {
            current_index = right_index;
        }
        if (current_index == index) {
            break;
        }
        swap(heaps[current_index],heaps[index] );
        index = current_index;
    }
}

int pop_heap() {
    if (get_size_heap() == 0) {
        return -1;
    }
    int num = heaps[1];
    heaps[1] = heaps[heaps.size()-1];
    sift_down_heap(1);
    return num;
}

void push_heap(int num) {
    heaps.push_back(num);
    sift_up_heap(heaps.size()-1);
}

/**
 * 연결리스트
 */
struct Node {
    int data;
    Node* next;

    Node(int data): data(data), next(nullptr) {}
};
Node* head = nullptr;
Node* tail = nullptr;
int size =0;

int get(int value) {
    int index = 0;
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}
void addAtHead(int val) {
    Node* current = new Node(val); // 포인터는 stack, new는 힙 메모리

    if (head == nullptr) {
        head = tail = current;
        return;
    }
    current ->next = head;
    head= current;
    size++;
}
void addAtTail(int val) {
    Node* current = new Node(val);
    if (tail == nullptr) {
        head = tail = current;
        return;
    }

    tail->next= current;
    tail = current;
    size++;
}
void addAtIndex(int index, int val) {

    if (size <index) {
        return;
    }
    if (index==0) {
        addAtHead(val);
        return;
    }
    if (index==size) { // ⚠️size-1 아님 주의
        addAtTail(val);
        return;
    }
    Node* new_node = new Node(val);
    Node* current = head;
    for (int i=0; i<index-1; i++) {
        current = current->next;
    }

    new_node->next= current->next;
    current->next=new_node;
    size++;
}
void deleteAtIndex(int index) {

    if (index>=size) {
        return;
    }

    if (index==0) { // ⚠️여기 틀렸었음 주의!!
        Node* deletes = head;
        head = deletes->next;
        delete(deletes);
        size--;
        if (size==0) {
            tail = nullptr;
        }
        return;
    }

    Node* current = head;
    while (--index) {
        current = current->next;
    }
    Node* deletes = current->next;
    current->next= deletes->next;
    if (deletes == tail) {
        tail = current;
    }
    delete(deletes);
    size--;
}

int main() {


}