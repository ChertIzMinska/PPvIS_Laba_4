#pragma once
#include<iostream>
#include<vector>
#include "Node.h"
using namespace std;
template<typename T>
class non_directed_graph
{
	Node<T>* nodes;
	int size = 0;
	bool** edges;
public:
	non_directed_graph& operator=(const non_directed_graph& right)
	{
		if (this == &right)
			return *this;
		this->size = right.size;
		this->nodes = right.nodes;
		this->edges = right.edges;
		return *this;
	}
	bool operator ==(const non_directed_graph& right)
	{
		if (this->size != right.size)
			return false;
		for (int i = 0; i < size; i++)
		{
			if (this->nodes[i]._get_values()!= right.nodes[i]._get_values())
				return false;
		}
		for (int i = 0; i < size; i++)
		{
			for (int g = 0; g < size; g++)
			{
				if (this->edges[i][g] != right.edges[i][g])
					return false;
			}
		}
		return true;
	}
	bool operator !=(const non_directed_graph& right)
	{
		return !(*this == right);
	}
	bool operator >(const non_directed_graph& right)
	{
		return this->size > right.size;
	}
	bool operator>=(const non_directed_graph& right)
	{
		return this->size >= right.size;
	}
	bool operator<(const non_directed_graph& right)
	{
		return this->size < right.size;
	}
	bool operator<=(const non_directed_graph& right)
	{
		return this->size <= right.size;
	}
	class iterator;
	class const_iterator;
	iterator begin()
	{
      return nodes;
	}
	const const_iterator cbegin()
	{
		return nodes;
	}
	const const_iterator cend()
	{
		return nodes + size;
	}
	iterator end()
	{
		return nodes + size;
	}
	non_directed_graph(int n);
	non_directed_graph(){}
	int _find_node(T value);
	bool _empty()
	{
		return size == 0;
	}
	bool _is_node(T inform);
	bool _is_edge(T first, T second)
	{
		return edges[_find_node(first)][_find_node(second)]==1;
	}
	void _clear()
	{
		delete[] nodes;
		for (int i = 0; i < size; i++)
			delete[] edges[i];
		delete[] edges;

		size = 0;
		edges = nullptr;
		nodes = nullptr;
	}
	int _degree_node(T info);
	void _add_node(T info);
	int _get_number_nodes()
	{
		return size;
	}
	int _get_number_edges();
	void _add_edge(T f_node, T s_node);
	void _delete_node(T inform);
	void _delete_edge(T f_node, T s_node);
	void _show();
	class iterator
	{
         Node<T>* value;
	public:
		iterator(Node<T>* value)
		{
			this->value = value;
		}
		iterator& operator++()
		{
			*value++;
			return *this;
		}
		iterator & operator--()
		{
			*value--;
			return *this;
		}
		iterator& operator=(Node<T>*right)
		{
			if (this == &right)
				return *this;
			*value = *right.value;
			return *this;
		}
		bool operator==(const iterator& right)
		{
			return  value == right.value;
		}
		bool operator!=(const iterator& right)
		{
			return value != right.value;
		}
		iterator operator*()
		{
			return *this;
		}
		friend ostream& operator<<(ostream& out, const iterator& it)
		{
			out << "Node:" << it.value->_get_values() << endl;
			return out;
		}

	};
	class const_iterator
	{
		 Node<T>* value;
	public:
		const_iterator(Node<T>* value)
		{
			this->value = value;
		}
		const const_iterator& operator++()
		{
			*value++;
			return *this;
		}
		const const_iterator& operator--()
		{
			*value--;
			return *this;
		}
		bool operator==(const const_iterator& right)
		{
			return  value == right.value;
		}
		bool operator!=(const const_iterator& right)
		{
			return value != right.value;
		}
		const Node<T> operator*()
		{
			return *value;
		}
		friend ostream& operator<<(ostream& out, const const_iterator& it)
		{
			out << "Node:" << it.value->_get_values() << endl;
			return out;
		}
	};

};