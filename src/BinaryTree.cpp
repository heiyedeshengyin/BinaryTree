/*	Copyright 2019 heiyedeshengyin All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef BINARYTREE
#define BINARYTREE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//===========二叉树的结点===========
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

//===========二叉树===========
template <typename T>
class BinaryTree
{
private:
	TreeNode<T> *root;	//二叉树的根结点
public:
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
};

//===========函数的具体实现===========
/*
	无参构造函数
*/
template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

//------------------------------------------------------
/*
	有参构造函数
	T x:二叉树根结点的值
*/
template <typename T>
BinaryTree<T>::BinaryTree(T x)
{
	root = new TreeNode<T>(x);
}

//------------------------------------------------------
/*
	销毁一个二叉树
	TreeNode<T>* &root:二叉树的根结点

	@Return void
*/
template <typename T>
void distoryBiTree(TreeNode<T>* &root)
{
	if (root)
	{
		TreeNode<T> *left;
		TreeNode<T> *right;
		left = root->left;
		right = root->right;
		delete root;
		if (left)
			distoryBiTree(left);
		if (right)
			distoryBiTree(right);
	}
}

//------------------------------------------------------
/*
	析构函数
*/
template <typename T>
BinaryTree<T>::~BinaryTree()
{
	distoryBiTree(root);
}

//------------------------------------------------------
/*
	按流程创建一个二叉树
	TreeNode<T>* &root:二叉树的根结点

	@Return void
*/
template <typename T>
void creat_BiTree(TreeNode<T>* &root)
{
	if (root)
	{
		cout << "是否创建" << root->data << "结点的左结点(1为是 0为否):";
		int al;
		cin >> al;
		if (al == 1)
		{
			T a;
			TreeNode<T> *Node;
			cout << "请输入" << root->data << "结点的左结点的值:";
			cin >> a;
			Node = new TreeNode<T>(a);
			root->left = Node;
			creat_BiTree(root->left);
		}

		cout << "是否创建" << root->data << "结点的右结点(1为是 0为否):";
		int ar;
		cin >> ar;
		if (ar == 1)
		{
			T a;
			TreeNode<T> *Node;
			cout << "请输入" << root->data << "结点的右结点的值:";
			cin >> a;
			Node = new TreeNode<T>(a);
			root->right = Node;
			creat_BiTree(root->right);
		}
	}
	else
	{
		cout << "根结点未初始化,请输入根结点的值:";
		T a;
		cin >> a;
		root = new TreeNode<T>(a);
		creat_BiTree(root);
	}
}

//------------------------------------------------------
/*
	按流程创建一个二叉树

	@Return void
*/
template <typename T>
void BinaryTree<T>::creatBiTree()
{
	creat_BiTree(root);
}

//------------------------------------------------------
/*
	先序遍历
	TreeNode<T>* &root:二叉树的根结点
	vector<T> &v:存储遍历结果的数组

	@Return void
*/
template <typename T>
void Per(TreeNode<T>* &root, vector<T> &v)
{
	if (root)
	{
		v.push_back(root->data);
		Per(root->left, v);
		Per(root->right, v);
	}
}
//------------------------------------------------------
/*
	先序遍历,并把遍历结果返回到一个数组上

	@Return vector<T>
*/
template <typename T>
vector<T> BinaryTree<T>::PerOrderTraverse()
{
	vector<T> v;
	Per(root, v);
	return v;
}

//------------------------------------------------------
/*
	中序遍历
	TreeNode<T>* &root:二叉树的根结点
	vector<T> &v:存储遍历结果的数组

	@Return void
*/
template <typename T>
void In(TreeNode<T>* &root, vector<T> &v)
{
	if (root)
	{
		In(root->left, v);
		v.push_back(root->data);
		In(root->right, v);
	}
}

//------------------------------------------------------
/*
	中序遍历,并把遍历结果返回到一个数组上

	@Return vector<T>
*/
template <typename T>
vector<T> BinaryTree<T>::InOrderTraverse()
{
	vector<T> v;
	In(root, v);
	return v;
}

//------------------------------------------------------
/*
	后序遍历
	TreeNode<T>* &root:二叉树的根结点
	vector<T> &v:存储遍历结果的数组

	@Return void
*/
template <typename T>
void Post(TreeNode<T>* &root, vector<T> &v)
{
	if (root)
	{
		Post(root->left, v);
		Post(root->right, v);
		v.push_back(root->data);
	}
}

//------------------------------------------------------
/*
	后序遍历,并把遍历结果返回到一个数组上

	@Return vector<T>
*/
template <typename T>
vector<T> BinaryTree<T>::PostOrderTraverse()
{
	vector<T> v;
	Post(root, v);
	return v;
}

//------------------------------------------------------
/*
	层序遍历,并把遍历结果返回到一个数组上

	@Return vector<T>
*/
template <typename T>
vector<T> BinaryTree<T>::LevelOrderTraverse()
{
	vector<T> v;
	if (!root)
		return v;

	queue<TreeNode<T>*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode<T>* Node;
		Node = q.front();
		v.push_back(Node->data);
		q.pop();
		if (Node->left)
			q.push(Node->left);
		if (Node->right)
			q.push(Node->right);
	}
	return v;
}

//------------------------------------------------------
/*
	返回二叉树的高度
	TreeNode<T>* &root:二叉树的根结点

	@Return int
*/
template <typename T>
int height(TreeNode<T>* &root)
{
	if (root)
		return 1 + max(height(root->left), height(root->right));
	else
		return 0;
}

//------------------------------------------------------
/*
	返回二叉树的高度

	@Return int
*/
template <typename T>
int BinaryTree<T>::getHeight()
{
	return height(root);
}

//------------------------------------------------------
/*
	返回二叉树中结点的个数
	TreeNode<T>* &root:二叉树的根结点

	@Return int
*/
template <typename T>
int size(TreeNode<T>* &root)
{
	if (root)
		return 1 + size(root->left) + size(root->right);
	else
		return 0;
}

//------------------------------------------------------
/*
	返回二叉树中结点的个数

	@Return int
*/
template <typename T>
int BinaryTree<T>::getSize()
{
	return size(root);
}

#endif // !BINARYTREE
