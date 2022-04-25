#include <iostream>
#include <unordered_map>

#define endl '\n'

using namespace std;

class TreeNode
{
public:
	char leftNode;
	char rightNode;

	TreeNode() {}
	TreeNode(char l, char r) : leftNode(l), rightNode(r)
	{

	}
};
unordered_map<char, TreeNode> treeHash;

void preOrder(char node)
{
	if (node == '.') return;

	cout << node;
	preOrder(treeHash[node].leftNode);
	preOrder(treeHash[node].rightNode);
}
void inOrder(char node)
{
	if (node == '.') return;

	inOrder(treeHash[node].leftNode);
	cout << node;
	inOrder(treeHash[node].rightNode);
}
void postOrder(char node)
{
	if (node == '.') return;

	postOrder(treeHash[node].leftNode);
	postOrder(treeHash[node].rightNode);
	cout << node;
}
int main()
{
	int N; // 이진트리 노드의 개수
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		char a, l, r;
		cin >> a >> l >> r;
		TreeNode temp = TreeNode(l, r);
		treeHash.insert({ a, temp });
	}

	preOrder('A');
	cout << endl;
	inOrder('A');
	cout << endl;
	postOrder('A');
	cout << endl;
}