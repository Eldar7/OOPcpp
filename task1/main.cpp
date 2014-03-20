#include <iostream>

template <typename T> class XList
{
private:
	struct element
	{
		T value;
		element *next;
		element *prev;
		element (T i_value, element* i_prev, element* i_next)
		{
			value = i_value;
			next = i_next;
			prev = i_prev;
		}
	};
	
	element *m_head;
	element *m_tail;
public:
	class iterator
	{
	public:
		iterator()
		{
			element_ptr = NULL;
		}
		iterator(element* ptr)
		{
			element_ptr = ptr;
		}
		T operator * ()
		{
			return element_ptr->value;
		}
		iterator operator ++ ()
		{
			element_ptr = element_ptr->next;
			return iterator(*this);
		}
		iterator operator ++ (int) //если это убрать и вызвать it++ то вернЄтс€ увеличенное
		{
			iterator temp(*this);
			element_ptr = element_ptr->next;
			return temp;			
		}
		bool operator == (iterator const& i)
		{
			return element_ptr == i.element_ptr;
		}
		bool operator != (iterator const& i)
		{
			return !(*this == i);
		}
	protected:
		element* element_ptr;
	};
	
	class reverse_iterator : public iterator
	{
	public:
		reverse_iterator()
		{
			element_ptr = NULL;
		}
		reverse_iterator(element* ptr)
		{
			element_ptr = ptr;
		}
		reverse_iterator operator ++ ()
		{
			element_ptr = element_ptr->prev;
			return reverse_iterator(*this);
		}
		reverse_iterator operator ++ (int) //если это убрать и вызвать it++ то вернЄтс€ увеличенное
		{
			iterator temp(*this);
			element_ptr = element_ptr->prev;
			return temp;			
		}
	};

	XList()
	{
		m_head = NULL;
		m_tail = NULL;
	}
	XList(T x)
	{
		element* a = new element(x, NULL, NULL);
		m_head = a;
		m_tail = a;
	}

	void print() const //метод дл€ которого this это const
	{
		const element* current = m_head; //указатель на константу, то есть пол€ current не мен€ютс€
		if (!empty())
		{
			std::cout<<"XList: ";
			do 
			{
				std::cout<<current->value<<", ";
				current = current->next;
			}
			while(current!=NULL);
			std::cout<<std::endl;
		}
		else
			std::cout<<"XList is empty"<<std::endl;
	}

	void push_front(T x)
	{
		element* a = new element(x, NULL, m_head);
		if (!empty())
			m_head->prev = a;
		else
			m_tail = a;
		m_head = a;
	}

	void push_back(T x)
	{
		element* a = new element(x, m_tail, NULL);
		if (!empty())
			m_tail->next = a;
		else
			m_head = a;
		m_tail = a;
	}

	void pop_front()
	{
		if (!empty())
		{
			element* temp = m_head;
			if ((m_head->next)!=NULL)
			{
				m_head = m_head->next;
				m_head->prev = NULL;
			}
			else
			{
				m_head = NULL;
				m_tail = NULL;
			}
			delete temp;
		}
	}

	void pop_back()
	{
		if (!empty())
		{
			element* temp = m_tail;
			if ((m_tail->prev)!=NULL)
			{
				m_tail = m_tail->prev;
				m_tail->next = NULL;
			}
			else
			{
				m_head = NULL;
				m_tail = NULL;
			}
			delete temp;
		}
	}

	T front()
	{
		return m_head->value;
	}

	T back()
	{
		return m_tail->value;
	}

	const int size() const
	{
		int count = 0;
		if (!empty())
		{
			count++;
			element* current = m_head;
			while (current->next!=NULL)
			{
				count++;
				current = current->next;
			}
		}
		return count;
	}

	const bool empty() const
	{
		return m_head==NULL;
	}

	void clear()
	{
		while(!empty())
			pop_back();
	}
	
	iterator begin()
	{
		return iterator(m_head);
	}
	iterator end()
	{
		return iterator(NULL);
	}
	reverse_iterator rbegin()
	{
		return reverse_iterator(m_tail);
	}
	reverse_iterator rend()
	{
		return reverse_iterator(NULL);
	}
};

int main()
{
	XList<int> list;
	XList<int>::iterator it;
	XList<int>::reverse_iterator rit;
	
	list.push_back(11);
	list.push_front(8);
	list.push_back(12);
	list.push_back(13);
	list.push_back(14);

	list.print();
	std::cout<<list.size()<<std::endl;
	//list.clear();

	it = list.begin();
	std::cout<<*(++it)<<std::endl;

	for (it = list.begin(); it != list.end(); ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;

	for (rit = list.rbegin(); rit != list.rend(); ++rit)
		std::cout<<*rit<<" ";
	std::cout<<std::endl;

	it = list.end();

	return 0;
}