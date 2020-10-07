#include <iostream>
#include <string>

template<typename T>
class DLL 
{
	struct Node 
	{
		T data;//fixme
		Node* next;
		Node* prev;
	};

	int Dll_size;
	Node* Sentinel;
	Node* Tail_node;

public:

	DLL() : Dll_size(0)
	{
		Sentinel = new Node();
		Sentinel->data = NULL;
		Tail_node = Sentinel;
	}
	
	bool empty() const
	{
		if (Dll_size <= 0) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	void push_front(const T& d) //FIXME 
	{
		Tail_node->next = new Node();

		Tail_node->next->data = d;
		Tail_node->next->prev = Tail_node;
		Tail_node->next->next = Sentinel;

		Tail_node = Tail_node->next;

		Sentinel->prev = Tail_node;
		Dll_size++;
	}

	void push_back(const T& d)//FIXME 
	{
		if (Dll_size <= 0)
		{
			push_front(d);
		}
		else 
		{
			Node* next_node = Sentinel->next;

			Sentinel->next = new Node();

			Sentinel->next->data = d;
			Sentinel->next->prev = Sentinel;
			Sentinel->next->next = next_node;

			next_node->prev = Sentinel->next;
		}

		Sentinel->prev = Tail_node;
		Dll_size++;
	}

	void insert_after(Node* ins, const T& d)//FIXME
	{
		if (ins != nullptr) 
		{
			if (ins == Tail_node) 
			{
				push_back(d);
			}
			else
			{
				Node* next_node = ins->next;

				ins->next = new Node();
				ins->next->data = d;
				ins->next->next = next_node;
				ins->next->prev = ins;

				next_node->prev = ins->next;
			}

			Sentinel->prev = Tail_node;
			Dll_size++;
		}
	}

	void insert_before(Node* ins, const T& d)//FIXME 
	{
		if (ins != nullptr)
		{
			Node* prev_node = ins->prev;

			ins->prev = new Node();

			ins->prev->data = d;
			ins->prev->next = ins;
			ins->prev->prev = prev_node;
			prev_node->next = ins->prev;

			Sentinel->prev = Tail_node;
			Dll_size++;
		}
	}

	Node* find_first(const T& d) const //FIXME
	{
		Node* iter= Sentinel->next;

		for (int i = 0; i < Dll_size; i++) 
		{
			if (iter->data == d) 
			{
				return iter;
			}
			else if (i == Dll_size - 1) 
			{
				return nullptr;
			}

			iter = iter->next;
		}
	}

	Node* find_last(const T& d) const //FIXME
	{
		Node* iter = Tail_node;

		while (iter->data != NULL) 
		{
			if (iter->data == d) 
			{
				return iter;
			}
			else if (iter->prev->data == NULL) 
			{
				return nullptr;
			}

			iter = iter->prev;
		}
	}

	void print_fvd(std::ostream& str = std::cout) const
	{
		Node* iter = Sentinel->next;
		
		while (iter->data != NULL) 
		{
			str << iter->data << ' ';
			iter = iter->next;
		}

		str << std::endl;
	}

	void print_rev(std::ostream& str = std::cout) const 
	{
		Node* iter = Tail_node;

		while (iter->data != NULL) 
		{
			str << iter->data << ' ';
			iter = iter->prev;
		}

		str << std::endl;
	}

	void delete_node(const Node* del_node) 
	{
		del_node->prev->next = del_node->next;
		del_node->next->prev = del_node->prev;

		if (del_node == Tail_node) 
		{
			Tail_node = del_node->prev;
		}

		Sentinel->prev = Tail_node;
		delete del_node;
	}

	void reverse()
	{
		Node* first_node, * last_node;

		first_node = Sentinel->next;
		last_node = Tail_node;

		while (first_node != last_node)
		{
			first_node->prev = Tail_node;
			Tail_node->next = first_node;

			first_node = first_node->next;
			first_node->prev = Sentinel;
			Sentinel->next = first_node;

			Tail_node = Tail_node->next;
			Tail_node->next = Sentinel;
			Sentinel->prev = Tail_node;
		}
	}

	void clear()
	{
		Node* iter = Sentinel->next;
		Node* iter_next = iter->next;

		while (iter->data != NULL) 
		{
			delete_node(iter);
			iter = iter_next;
			iter_next = iter->next;
		}

		Dll_size = 0;
	}

	~DLL() 
	{
		clear();
		delete Sentinel;
	}
};

int main() 
{
	using namespace std;

	DLL<int>* dll = new DLL<int>();

	dll->push_back(2);
	dll->push_back(1);
	dll->push_front(3);
	dll->push_front(4);
	dll->push_front(2);

	cout << "Printing list:" << endl;
	dll->print_fvd();
	dll->print_rev();

	cout << "Deleting 2s from the begining and the end:" << endl;
	dll->delete_node(dll->find_first(2));
	dll->delete_node(dll->find_last(2));
	dll->print_fvd();
	dll->print_rev();
	
	cout << "Inserting 88 after 3" << endl;
	dll->insert_after(dll->find_first(3), 88);

	dll->print_fvd();
	dll->print_rev();

	cout << "Reversing:" << endl;
	dll->reverse();
	dll->print_rev();

	cout << "empty: " << dll->empty() << endl;

	cout << "Clearing: " << endl;
	dll->clear();

	cout << "Adding 33: " << endl;
	dll->push_front(33);
	dll->print_fvd();

	cout << "Deleting list:" << endl;
	delete dll;
	cout << dll << endl;

	return 0;
}