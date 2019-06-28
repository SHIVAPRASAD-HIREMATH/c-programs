#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node * insert(struct Node *root_local, int data)
{
	if(NULL == root_local)
	{
		root_local = (struct Node*)malloc(sizeof(struct Node));
		root_local->data = data;
		root_local->left = NULL;
		root_local->right = NULL;
	}
	else if(data <= root_local->data)
	{
		root_local->left = insert(root_local->left,data);
	}
	else
	{
		root_local->right = insert(root_local->right,data);
	}
	return root_local;
}

//void print(struct Node *root)
//{
//	if(root != NULL)
//	{
//		printf("%d\n",root->data);
//		print(root->left);
//		print(root->right);
//	}
//}

void print_order(struct Node *root)
{
	if(root != NULL)
	{
		print_order(root->left);
		printf("%d\n",root->data);		
		print_order(root->right);
	}
}

int main()
{
	struct Node *root=NULL;
	root = insert(root,5);
	root = insert(root,1);
	root = insert(root,7);
//	print(root);
	print_order(root);
}
