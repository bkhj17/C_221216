#pragma once

template <typename T>
struct DoublyNode;

template <typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList() {};
	~DoublyLinkedList() { if (head) delete head; head = nullptr; tail = nullptr; }

	bool Empty() { return head == nullptr; }

	void PushBack(T data);
	void PushFront(T data);

	void Insert(DoublyNode<T>* prevNode, int data);
	void PushSort(T data, bool (*compare)(T&, T&));

	void PopBack();
	void PopFront();

	DoublyNode<T>* GetFront() { return head; }
	DoublyNode<T>* GetBack() { return tail; }

	DoublyNode<T>* Find(int i);
	void Erase(int pos);
	void Clear();


	void PrintData();
	int GetSize() { return size; }

	void Reverse();
private:
	int size = 0;
	DoublyNode<T>* head = nullptr, * tail = nullptr;
};

template<typename T>
inline void DoublyLinkedList<T>::PushBack(T data)
{
	auto node = new DoublyNode<T>(data);
	if (head == nullptr) {
		head = node;
	}
	else {
		tail->next = node;
		node->prev = tail;
	}
	tail = node;

	size++;
}

template<typename T>
inline void DoublyLinkedList<T>::PushFront(T data)
{
	DoublyNode<T>* node = new DoublyNode<T>(data);
	if (Empty()) {
		tail = node;
	}
	else {
		node->next = head;
		head->prev = node;
	}

	head = node;
	size++;
}

template<typename T>
inline void DoublyLinkedList<T>::Insert(DoublyNode<T>* prevNode, int data)
{
	if (prevNode == nullptr) {
		PushBack(data);
		return;
	}

	DoublyNode<T>* newNode = new DoublyNode<T>(data);
	newNode->prev = prevNode;
	newNode->next = prevNode->next;
	prevNode->next = newNode;

	if (newNode->next == nullptr)
		tail = newNode;

	size++;
}

template<typename T>
inline void DoublyLinkedList<T>::PushSort(T data, bool (*compare)(T&, T&))
{
	//compare : false�� ��������
	if (Empty()) {
		PushBack(data);
		return;
	}

	if (compare(data, head->data)) {
		PushFront(data);
		return;
	}

	DoublyNode<T>* prevNode = head;

	while (prevNode != nullptr && compare(data, prevNode->data)) {
		prevNode = prevNode->next;
	}

	Insert(prevNode, data);
}

template<typename T>
inline void DoublyLinkedList<T>::PopBack()
{
	if (Empty())
		return;

	auto target = tail;
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		tail = target->prev;
		tail->next = nullptr;
		target->prev = nullptr;
	}

	delete target;
	size--;
}

template<typename T>
inline void DoublyLinkedList<T>::PopFront()
{
	if (Empty())
		return;

	auto node = head;
	head = head->next;
	if (head != nullptr) {
		head->prev = nullptr;
	}
	else {
		tail = nullptr;
	}
	node->next = nullptr;
	size--;

	T result = node->data;
	delete node;
}

template<typename T>
inline void DoublyLinkedList<T>::Erase(int pos)
{
	auto* node = Find(pos);
	if (node == nullptr)
		return;

	if (node->prev != nullptr) {
		node->prev->next = node->next;
	}
	else {
		head = node->next;
	}
	if (node->next != nullptr) {
		node->next->prev = node->prev;
	}
	else {
		tail = node->prev;
	}

	node->prev = nullptr;
	node->next = nullptr;
	size--;
	delete node;
}

template<typename T>
inline void DoublyLinkedList<T>::Clear()
{
	while (size > 0) {
		PopBack();
	}
}

template <typename T>
inline void DoublyLinkedList<T>::PrintData()
{
	if (Empty()) {
		cout << "Empty\n" << endl;
		return;
	}

	for (auto* node = head; node != nullptr; node = node->next) {
		cout << node->data << " ";
	}
	cout << "\n";
}

template<typename T>
inline void DoublyLinkedList<T>::Reverse()
{
	auto h = head;
	auto t = tail;
	for (auto node = head; node != nullptr; node = node->prev) {
		auto tmp = node->prev;
		node->prev = node->next;
		node->next = tmp;
	}

	head = t;
	tail = h;
}

template <typename T>
inline DoublyNode<T>* DoublyLinkedList<T>::Find(int i)
{
	if (i < 0 || i >= size)
		return nullptr;

	DoublyNode<T>* cur = nullptr;
	if (i < size / 2) {
		int cnt = 0;
		cur = head;
		while (cnt++ < i && cur->next != nullptr) {
			cur = cur->next;
		}
	}
	else {
		int cnt = size - 1;
		cur = tail;
		while (cnt-- > i && cur->prev != nullptr) {
			cur = cur->prev;
		}
	}

	return cur;
}