#include <iostream>
using namespace std;

template<typename T>
class LinkedList
{
	private:
		class Node
		{
			public:
				T value;
				Node* next;

				Node(T value) : value{ value }, next{nullptr} {}
		};

		Node* _first;
		Node* _last;

	public: 
		LinkedList(): _first{nullptr}, _last{nullptr} {}

		~LinkedList()
		{
			if (!IsEmpty()) 
			{
				Node* current = _first->next;
			
				while (current != nullptr)
				{
					delete _first;
					_first = current;
					current = current->next;
				}

				delete _first;
				_first = nullptr;
				_last = nullptr;
			}
		}

		LinkedList& PushBack(T value)
		{
			Node* node = new Node(value);
			
			if (IsEmpty())
			{
				_first = node;
				_last = node;
				return *this;
			}
			_last->next = node;
			_last = node;

			return *this;
		}

		LinkedList& PushForward(T value)
		{
			Node* node = new Node(value);

			if (IsEmpty())
			{
				_first = node;
				_last = node;
				return *this;
			}

			node->next = _first;
			_first = node;

			return *this;
		}

		LinkedList& DeleteBack()
		{
			if (IsEmpty())
			{
				return *this;
			}

			Node* current = _first;
			while (current->next != _last)
			{
				current = current->next;
			}

			delete _last;
			current->next = nullptr;
			_last = current;

			return *this;
		}

		LinkedList& DeleteForward()
		{
			if (IsEmpty())
			{
				return *this;
			}

			Node* current = _first;
			_first = current->next;
			delete current;

			return *this;
		}

		bool IsEmpty() const
		{
			return _first == nullptr;
		}

		friend ostream& operator<<(ostream& out, const LinkedList& list)
		{
			Node* current = list._first;

			while (current != nullptr)
			{
				out << current->value << '\t';
				current = current->next;
			}
			out << endl;

			return out;
		}

		LinkedList& DeleteAll()
		{
			this->~LinkedList();

			return *this;
		}
};

int main()
{
	LinkedList<int> list;
	list.PushBack(3);
	list.DeleteAll();
	list.PushForward(7);
	list.PushBack(5);
	list.PushBack(10);
	list.DeleteBack();

	cout << list;

	return 0;
}