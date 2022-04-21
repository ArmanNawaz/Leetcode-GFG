```
struct LinkedList {
int val;
struct LinkedList* next;
LinkedList(int value, struct LinkedList* nextptr = nullptr) {
int val = value;
struct LinkedList* next = nextptr;
}
};
​
class MyHashSet {
public:
LinkedList* ll;
MyHashSet() {
ll = new LinkedList(-1);
}
void add(int key) {
auto temp = ll;
while(temp -> next != nullptr)
temp = temp -> next;
temp -> next = new LinkedList(key);
}
void remove(int key) {
auto temp = ll -> next;