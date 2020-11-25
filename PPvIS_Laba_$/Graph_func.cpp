#include "Graph_and _Iters.h"
using namespace std;
template<typename T>
void non_directed_graph<T>::_show() {
	if (!_empty())
	{
		bool* checked_node = new bool[size];


		for (int i = 0; i < size; i++)
		{
			checked_node[i] = true;
			cout << nodes[i] << endl;
			for (int g = 1; g < size; g++) {
				if (checked_node[g] != 1 && edges[i][g] == 1)
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
template<typename T>
void non_directed_graph<T>::_delete_edge(T f_node, T s_node)
{
	if (_is_node(f_node) && _is_node(s_node))
	{
		int n_f = _find_node(f_node);
		int n_s = _find_node(s_node);
		edges[n_f][n_s] = 0;
		edges[n_s][n_f] = 0;

	}
}
template<typename T>
void non_directed_graph<T>::_delete_node(T inform)
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
			for (int y = 0; y < size; y++)
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
template<typename T>
void non_directed_graph<T>::_add_edge(T f_node, T s_node)
{
	if (_is_node(f_node) && _is_node(s_node))
	{
		int n_f = _find_node(f_node);
		int n_s = _find_node(s_node);
		edges[n_f][n_s] = 1;
		edges[n_s][n_f] = 1;

	}


}
template<typename T>
int non_directed_graph<T>::_get_number_edges()
{
	int res = 0;
	for (int i = 0; i < size; i++)
	{
		for (int g = i; g < size; g++)
		{
			res += edges[i][g];
		}
	}
	return res;
}
template<typename T>
int non_directed_graph<T>::_degree_node(T info)
{
	int res = 0;
	int number = _find_node(info);
	for (int i = 0; i < size; i++)
		res += edges[number][i];
	return res;
}
template<typename T>
void non_directed_graph<T>::_add_node(T info)
{
	if (!_is_node(info))
	{
		Node<T>* new_nodes = new Node<T>[size + 1];
		for (int i = 0; i < size; i++)
		{
			new_nodes[i] = nodes[i];
		}
		new_nodes[size] = info;
		bool** new_edges = new bool* [size + 1];
		for (int i = 0; i < size + 1; i++)
			new_edges[i] = new bool[size + 1];
		for (int i = 0; i < size + 1; i++)
		{
			for (int g = 0; g < size + 1; g++)
			{
				if (g == size || i == size)
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
template<typename T>
int non_directed_graph<T>::_find_node(T value)
{
	for (int i = 0; i < this->size; i++)
	{
		if (nodes[i]._get_values() == value)
			return i;
	}
	return -1;
}
template<typename T>
 non_directed_graph<T>::non_directed_graph(int n)
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
 template<typename T>
bool non_directed_graph<T>::_is_node(T inform)
 {
	 for (int i = 0; i < size; i++)
	 {
		 if (inform == nodes[i]._get_values())
			 return true;
	 }
	 return false;
 }