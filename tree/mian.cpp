#include"charg_blanace.h"
#include"treeDepth.h"

void test()
{
	Node t1(1);
	Node t2(2);
	Node t3(3);
	Node t4(4);
	Node t5(5);

	t1.left = &t2;
	t1.right = &t3;
	t1.next = nullptr;
	t2.left = &t4;
	t2.right = &t5;
	t2.next = &t1;
	t3.left = nullptr;
	t3.right = nullptr;
	t3.next = &t1;
	
	cout << chargeBlance(&t1) << endl;

	cout << treeDepth(&t1) << endl;
	cout << treeDepthFor(&t1) << endl;
	cout << minDept(& t1) << endl;

}

int main()
{
	test();
	return 0;
}