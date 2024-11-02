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

		LinkedList& Push(T value)
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
};

int main()
{
	LinkedList<int> list;
	list.Push(3);
	list.Push(5);
	cout << list;

	return 0;
}