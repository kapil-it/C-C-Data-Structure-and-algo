// Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// custom data type for tree building
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

// Below function accepts string and a pointer variable as
// an argument
// and draw the tree. Returns the root of the tree
//Node* constructtree(string s, int* start)
//{
//	// Assuming there is/are no negative
//	// character/characters in the string
//	if (s.size() == 0 || *start >= s.size())
//		return NULL;
//
//	// constructing a number from the continuous digits
//	int num = 0;
//	while (*start < s.size() && s[*start] != '('
//		&& s[*start] != ')') {
//		int num_here = (int)(s[*start] - '0');
//		num = num * 10 + num_here;
//		*start = *start + 1;
//	}
//
//	// creating a node from the constructed number from
//	// above loop
//	struct Node* root = new Node(num);
//
//	// check if start has reached the end of the string
//	if (*start >= s.size())
//		return root;
//
//	// As soon as we see first right parenthesis from the
//	// current node we start to construct the tree in the
//	// left
//	if (*start < s.size() && s[*start] == '(') {
//		*start = *start + 1;
//		root->left = constructtree(s, start);
//	}
//	if (*start < s.size() && s[*start] == ')')
//		*start = *start + 1;
//
//	// As soon as we see second right parenthesis from the
//	// current node we start to construct the tree in the
//	// right
//	if (*start < s.size() && s[*start] == '(') {
//		*start = *start + 1;
//		root->right = constructtree(s, start);
//	}
//	if (*start < s.size() && s[*start] == ')')
//		*start = *start + 1;
//	return root;
//}
//void preorder(Node* root)
//{
//	if (root == NULL)
//		return;
//	cout << root->data << " ";
//	preorder(root->left);
//	preorder(root->right);
//}
class node
{
public:
    int data;
    struct node* left;
    struct node* right;
};
int f=1;

int Slove(node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	if(root->left == NULL && root->right == NULL)
	{
		return root->data;
	}
	if(f==0)
	{
		return 0;
	}
	int back = root->data;

	int a= Slove(root->left);
	int b = Slove(root->right);
	cout<<"data="<<root->data<<endl;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"*********"<<endl;
	if(root->data != a+b)
	{
		f=0;
	}
	return (a+b);
}
bool IsSumTree(node* root)
{
	Slove(root);
	return f;
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(
        sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main()
{
	//string s = "4(2(3)(1))(6(5))";
	//// cin>>s;
	//int start = 0;
	//Node* root = constructtree(s, &start);
	//preorder(root);


	struct node *root = newNode(22);
    root->left = newNode(9);
    root->right = newNode(13);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
	root->right->left = newNode(11);
	root->right->right = newNode(2);

	cout<<"res="<<IsSumTree(root)<<endl;
	return 0;
}
//This code is contributed by Chaitanya Sharma.


