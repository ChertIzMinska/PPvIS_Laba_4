#include"Graph_and _Iters.h"
#include "Graph_func.cpp"
using namespace std;
int main()
{

	non_directed_graph<int> test;
	for (int i = 2; i < 6; i++)
	{
		test._add_node(i);
	}
	test._show();
	
}