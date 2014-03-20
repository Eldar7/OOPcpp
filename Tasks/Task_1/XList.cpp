#include "XList.h"
/*
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
*/