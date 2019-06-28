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



void print_order(struct Node *root)
{
	if(root != NULL)
	{
		print_order(root->left);
		printf("%d\n",root->data);		
		print_order(root->right);
	}
}

int find_min_rec(struct Node *root)
{
	int min;
	if(root!=NULL)
	{
		if(root->left!=NULL)
		{
			min = find_min_rec(root->left);
		}
		else
		{
			min = root->data;
		}		 
	}
	return min;
}

int find_max_rec(struct Node *root)
{
	int max;
	if(root!=NULL)
	{
		if(root->right!=NULL)
		{
			max = find_max_rec(root->right);
		}
		else
		{
			max = root->data;
		}		 
	}
	return max;
}

int find_min(struct Node *root)
{
	int min;
	if(root == NULL)
	{
		printf("Tree is empty\n");
		min = -1;
	}
	else
	{
		while(root->left!=NULL)
		{
			root=root->left;		 
		}
		min = root->data;
	}
	return min;
}

int find_height(struct Node *root,int count)
{
	static height=0;
	if(height<=count)
	{
		height=count;
	}
	if(root != NULL)
	{
		find_height(root->left,count+1);	
		find_height(root->right,count+1);
	}
	return height;
}

int main()
{
	struct Node *root=NULL;
	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,12);
	root = insert(root,8);
	root = insert(root,3);
	root = insert(root,9);
	root = insert(root,13);
	root = insert(root,17);
	root = insert(root,20);
	print_order(root);
	printf("\n------------------\n");
	printf("min by recur = %d\n", find_min_rec(root));
	printf("max by recur= %d\n", find_max_rec(root));
	printf("min by loop= %d\n", find_min(root));
	printf("height = %d\n", find_height(root,0));
}
