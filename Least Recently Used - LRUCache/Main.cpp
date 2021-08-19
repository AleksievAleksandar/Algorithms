#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
private:
	size_t size;
public:
	LRUCache(const int capacity) : size(0)
	{
		this->cp = capacity;
		this->head = nullptr;
		this->tail = nullptr;
	}

	~LRUCache()
	{
		while (this->head->next != nullptr)
		{
			Node* temp = this->head->next;
			delete this->head;

			this->head = temp;
		}
		delete this->head;
	}
public:
	virtual void set(int key, int value) override
	{
		if (this->head == nullptr && this->tail == nullptr) //init head and tail for first time
		{
			this->head = new Node(key, value);
			this->tail = this->head;

			this->mp[key] = head;

			this->size++;
		}
		else
		{
			if (this->mp.find(key) == this->mp.end()) //KEY for first time
			{
				Node* newNode = new Node(this->tail, nullptr, key, value);

				if (this->size < this->cp) //include KEY into this->mp
				{
					this->size++;
				}
				else //capacity is full and must remove head (oldest Node)
				{
					Node* newHead = this->head->next;
					
					this->mp.erase(this->head->key); //remove old head form this->mp

					delete this->head;

					this->head = newHead;
					this->head->prev = nullptr;
				}

				this->attachedNewNode(newNode, key);

			}
			else //this KEY already exist into this->mp
			{
				this->mp[key]->value = value;
			}
		}
	}

	virtual int get(int a) override
	{
		auto itr = this->mp.find(a);
		if (itr != this->mp.end())
		{
			return itr->second->value;
		}

		return -1;	
	}
private:
	void attachedNewNode(Node* newNode, const int key)
	{
		if (this->head->next == nullptr)
		{
			this->head->next = newNode;
		}

		this->tail->next = newNode;
		this->tail = newNode;

		this->mp[key] = newNode;
	}

};

int main() {
	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
	}
	return 0;
}
