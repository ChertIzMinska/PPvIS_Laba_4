#include"Graph_and _Iters.h"
using namespace std;
int main()
{

	non_directed_graph<int> test;
	for (int i = 2; i < 6; i++)
	{
		test._add_node(i);
	}
	non_directed_graph<int>::iterator it = test.begin();
	it._delete_node();
	test._show();
	
}