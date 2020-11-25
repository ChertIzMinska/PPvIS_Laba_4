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
	non_directed_graph(int n)
	{
		nodes = new T[n];
		size = n;
		edges = new bool* [size];
		for (int i = 0; i < size; i++)
		{
			edges[i] = new bool[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int g = 0; g < size; g++)
				edges[i][g] == false;
		}
	}
	non_directed_graph(){}
	int _find_node(T value)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (nodes[i]._get_values() == value)
				return i;
		}
		return -1;
	}
	bool _empty()
	{
		return size == 0;
	}
	bool _is_node(T inform)
	{
		for (int i = 0; i < size; i++)
		{
			if (inform == nodes[i]._get_values())
				return true;
		}
		return false;
	}
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
	int _degree_node(T info)
	{
		int res = 0;
		int number = _find_node(info);
		for (int i = 0; i < size; i++)
			res += edges[number][i];
		return res;
		}
	void _add_node(T info)
	 {
		if (!_is_node(info))
		{
			Node<T>* new_nodes = new Node<T>[size + 1];
			for (int i = 0; i < size; i++)
			{
				new_nodes[i] = nodes[i];
			}
			new_nodes[size] = info;
			bool** new_edges = new bool * [size + 1];
			for (int i = 0; i < size+1;i++)
				new_edges[i] = new bool[size + 1];
			for (int i = 0; i < size + 1; i++)
			{
				for (int g = 0; g < size+1; g++)
				{
					if (g == size || i==size)
					{
						new_edges[i][g] = 0;
						
					}
					else {
						new_edges[i][g] = edges[i][g];
					}
				}
			}
			if (size > 0)
			{
				delete[] nodes;
				for (int i = 0; i < size; i++)
					delete[] edges[i];
				delete[] edges;
			}
			size = size + 1;
			nodes = new_nodes;
			edges = new_edges;

		}
	}
	int _get_number_nodes()
	{
		return size;
	}
	int _get_number_edges()
	{
		int res = 0;
		for (int i=0;i<size;i++)
		{
			for (int g=i;g<size;g++)
			{
				res += edges[i][g];
			}
		}
		return res;
	}
	void _add_edge(T f_node,T s_node)
	{
		if (_is_node(f_node) && _is_node(s_node))
		{
			int n_f = _find_node(f_node);
			int n_s = _find_node(s_node);
			edges[n_f][n_s] = 1;
			edges[n_s][n_f] = 1;

		}


	}
	void _delete_node(T inform)
	{
		if (_is_node(inform))
		{
			int n = _find_node(inform);
			Node<T>* new_nodes = new Node<T>[size - 1];
			bool** new_edges = new bool* [size - 1];
			for (int i = 0; i < size - 1; i++)
				new_edges[i] = new bool[size - 1];
			int g = 0;
			for (int i = 0; i < size; i++)
			{
				if (i == n)
					continue;
				new_nodes[g] = nodes[i];
				g++;
			}
			int z = 0;
			for (int i = 0; i < size; i++)
			{
				g = 0;
				if (i == n)
					continue;
				for (int y= 0; y < size; y++)
				{
					if (y == n)
						continue;
					new_edges[z][g] = edges[i][y];
					g++;
				}
				z++;
			}
			if (size > 0)
			{
				delete[] nodes;
				for (int i = 0; i < size; i++)
					delete[] edges[i];
				delete[] edges;
			}
			nodes = new_nodes;
			edges = new_edges;
			size = size - 1;

		}
	}
	void _delete_edge(T f_node, T s_node)
	{
		if (_is_node(f_node) && _is_node(s_node))
		{
			int n_f = _find_node(f_node);
			int n_s = _find_node(s_node);
			edges[n_f][n_s] = 0;
			edges[n_s][n_f] = 0;

		}
	}
	void _show()
	{
		if (!_empty())
		{
			bool* checked_node = new bool[size];

			checked_node[0] = true;
			cout << nodes[0] << endl;
			for (int i = 0; i < size; i++)
			{
				for (int g = 1; g < size; g++) {
					if (checked_node[g] != true && edges[i][g] == true)
					{
						checked_node[g] = true;
						cout << nodes[g] << "\t";
					}
				}
				cout << endl;
			}
		}
		else { cout << "Graph is empty\n"; }
	}
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