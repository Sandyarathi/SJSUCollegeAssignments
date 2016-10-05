#define	SIZE1 13
#define	SIZE2 11

#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int list1[SIZE1] = {34, 77, 26, 51, 39, 8, 12, 67, 4, 98, 123, 10, 42};
int list2[SIZE2] = {34, 77, 26, 51, 30, 39, 8, 31, 12, 67, 98};

int main()
{
	cout << "testDeleteAllLeaves by Das,Sandyarathi." << endl << endl;

	bSearchTreeType<int> tree1, tree2;

	for (int i = 0; i < SIZE1; ++i) {
		tree1.insert(list1[i]);
	}

	for (int i = 0; i < SIZE2; ++i) {
		tree2.insert(list2[i]);
	}

	cout << "Tree1:" << endl;
	cout << "\t\tHeight = " << tree1.treeHeight() << endl;
	cout << "\t\tinorder traversal = ";
	tree1.inorderTraversal();
	cout << endl;

	cout << "\t ***after deleteAllLeaves***" << endl;
	tree1.deleteAllLeaves();

	cout << "\t\tHeight = " << tree1.treeHeight() << endl;
	cout << "\t\tinorder traversal = ";
	tree1.inorderTraversal();
	cout << endl;

	cout << "Tree2:" << endl;
	cout << "\t\tHeight = " << tree2.treeHeight() << endl;
	cout << "\t\tinorder traversal = "; 
	tree2.inorderTraversal();
	cout << endl;

	cout << "\t ***after deleteAllLeaves***" << endl;
	tree2.deleteAllLeaves();

	cout << "\t\tHeight = " << tree2.treeHeight() << endl;
	cout << "\t\tinorder traversal = ";
	tree2.inorderTraversal();
	cout << endl;

	return 0;
}
