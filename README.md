# BinaryTree

### 简介
二叉树,基本的数据结构  
二叉树中每个结点的度数不超过2  

### 数据结构
二叉树的结点的数据结构
```cpp
template <typename T>
struct TreeNode
{
	T data;	//结点中存储的数据
	TreeNode<T> *left;	//结点的左孩子
	TreeNode<T> *right;	//结点的右孩子
	//结点的构造函数
	TreeNode(T x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};
```
二叉树的数据结构
```cpp
template <typename T>
class BinaryTree
{
	TreeNode<T> *root;	//二叉树的根结点
};
```

### 函数列表
BinaryTree();	//无参构造函数  
BinaryTree(T x);	//有参构造函数  
~BinaryTree();	//析构函数  
void creatBiTree();	//按流程创建二叉树  
vector<T> PerOrderTraverse();	//先序遍历  
vector<T> InOrderTraverse();	//中序遍历  
vector<T> PostOrderTraverse();	//后序遍历  
vector<T> LevelOrderTraverse();	//层序遍历  
int getHeight();	//获取二叉树的高度  
int getSize();	//获取二叉树的结点个数  

### 使用说明
把src/BinaryTree.cpp添加到你的头文件中  
以下为示例代码
```cpp
#include"BinaryTree.h"

int main()
{
	BinaryTree<int> tree;
	tree.creatBiTree();

	vector<int> v1 = tree.PerOrderTraverse();
	for (int i : v1)
		cout << i << " ";
	cout << endl;

	vector<int> v2 = tree.InOrderTraverse();
	for (int i : v2)
		cout << i << " ";
	cout << endl;

	vector<int> v3 = tree.PostOrderTraverse();
	for (int i : v3)
		cout << i << " ";
	cout << endl;

	vector<int> v4 = tree.LevelOrderTraverse();
	for (int i : v4)
		cout << i << " ";
	cout << endl;

	cout << tree.getHeight() << endl;
	cout << tree.getSize() << endl;

	return 0;
}
```
