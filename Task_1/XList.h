template <typename T> 
class XList
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
		iterator operator ++ (int) //если это убрать и вызвать it++ то вернётся увеличенное
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
		reverse_iterator operator ++ (int) //если это убрать и вызвать it++ то вернётся увеличенное
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

	void print() const;
	void push_front(T x);
	void push_back(T x);
	void pop_front();
	void pop_back();
	const int size() const;

	T front()
	{
		return m_head->value;
	}

	T back()
	{
		return m_tail->value;
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

template <typename T> 
void XList<T>::print() const
{
	const element* current = m_head;
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

template <typename T>
void XList<T>::push_front(T x)
{
	element* a = new element(x, NULL, m_head);
	if (!empty())
		m_head->prev = a;
	else
		m_tail = a;
	m_head = a;
}

template <typename T>
void XList<T>::push_back(T x)
{
	element* a = new element(x, m_tail, NULL);
	if (!empty())
		m_tail->next = a;
	else
		m_head = a;
	m_tail = a;
}

template <typename T>
void XList<T>::pop_front()
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

template <typename T>
void XList<T>::pop_back()
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

template <typename T>
const int XList<T>::size() const
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