#pragma once
using namespace std;
template<typename T>
class Node
{
	T values;
public:
	Node() {};
	Node(T info)
	{
		values = info;
	}
	T _get_values()
	{
		return values;
	}
	void _set_values(T values)
	{
		this->values = values;
	}
	Node& operator=(Node const *right)
	{
		if (this = right)
			return *this;
		values = right->values;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Node<T>& it)
	{
		out << "Node:" << it.values << endl;
		return out;
	}
};