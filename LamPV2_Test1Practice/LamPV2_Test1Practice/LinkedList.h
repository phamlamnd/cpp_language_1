#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
//Date create: 30/10/2018

template <class T>
class LinkedList;

template <class T>
class Node
{
private:
	T m_data;
	Node *m_next;
public:
	Node(T data) :m_data(data), m_next(NULL) { }			//constructor
	~Node() { }												//distructor
	Node(const Node& rhs) = delete;							//prevent copy
	Node&operator=(const Node& rhs) = delete;				//prevent assignment
	T& getData() { return m_data; }							//get data
	Node* getNext() { return m_next; }						//get next node
	friend class LinkedList<T>;								//friend class
};

template <class T>
class LinkedList
{
private:
	Node<T> *m_head;
public:
	LinkedList() {m_head = NULL;}							//init linked list
	~LinkedList();											//distructor
	LinkedList(const LinkedList& rhs) = delete;				//prevent copy
	LinkedList& operator=(const LinkedList& rhs) = delete;	//prevent assignent 
	Node<T>* begin() { return m_head; }						//begin()
	Node<T>* end() { return NULL; }							//end()
	Node<T>* erase(Node<T>* node);							//erase()
	void push_back(T data);									//push_back()
	void sort(bool(*funPointer)(T&,T&));					//sort()
};

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* cur = this->begin();
	while(cur != this->end())
	{
		Node<T>* nex = cur->getNext(); //save next node before delete
		delete cur;
		cur = nex;
	}
	m_head = NULL;
}

template <class T>
void LinkedList<T>::push_back(T data)
{
	Node<T> *cur = new Node<T>(data); //create node
	if (m_head == NULL)	//if list no element
	{
		m_head = cur;
	}
	else//if list have element					
	{
		cur->m_next = m_head; //add head
		m_head = cur;
	}
}

template <class T>
void LinkedList<T>::sort(bool(*funPointer)(T&,T&))
{
	if (m_head == NULL) //if no element
	{
		return;
	}
	Node<T> *cur = m_head;
	for (; cur->m_next != NULL; cur = cur->m_next)
	{
		Node<T> *nex = cur->m_next;
		for (; nex != NULL; nex = nex->m_next)
		{
			if (funPointer(cur->m_data, nex->m_data) == true) //only swap data
			{
				T tmp = cur->m_data;
				cur->m_data = nex->m_data;
				nex->m_data = tmp;
			}
		}
	}
}

template <class T>
Node<T>* LinkedList<T>::erase(Node<T>* node)
{
	Node<T>* cur = this->begin(); //node hien tai
	Node<T>* pre = this->begin(); //node ke tiep
	if (cur == node)			  //Neu node dau tien xoa
	{
		m_head = m_head->getNext();
		delete cur;
		return m_head;
	}
	for(; cur != this->end(); cur = cur->getNext())
	{
		if (cur == node)
		{
			Node<T>* nex = cur->m_next;    //Luu lai node ke tiep  pre->cur->nex
			delete cur;					   //Xoa node hien tai
			pre->m_next = nex;			   //node truoc tro den node sau
			return nex;					   //return next node
		}
		pre = cur; //Giu lai node hien tai cho vong lap sau
	}
	return NULL; //delete fail
}
#endif /*_LINKED_LIST_H_*/