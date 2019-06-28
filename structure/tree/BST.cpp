                #include<stdio.h>
                #include<stdlib.h>
                
                typedef struct BSTnode
                {
                                char data;
                                struct BSTnode* left;
                                struct BSTnode* right;
                }node;
                
                node* GetNewNode(char data)
                {
                                node* newNode=(node*)malloc(sizeof(node));
                                newNode->data=data;
                                newNode->left=NULL;
                                newNode->right=NULL;
                                return newNode;
                }
                
                node*  Insert(node* root,char data)
                {
                                if(root == NULL)
                                {
                                                root=GetNewNode(data);
                                }              
                                else if(data <= root->data)
                                {
                                                root->left=Insert(root->left,data);
                                }
                                else
                                {
                                                root->right=Insert(root->right,data);
                                }
                                return root;
                }
                node* FindMin(node* temp)
                {
                                if(temp->left == NULL)
                                {
                                                return temp;
                                }
                                else
                                {
                                                FindMin(temp->left);
                                }
                                
                }

                void FindMax(node* temp)
                {
                                if(temp->right == NULL)
                                {
                                                printf("max = %d ",temp->data);
                                }
                                else
                                {
                                                FindMax(temp->right);
                                }
                                
                }
                
                void PrintList(node* root)
                {
                                if(root != NULL)
                                {
                                                PrintList(root->left);
                                                printf("%c ",root->data);
                                                PrintList(root->right);
                                }
                }
                
                int hight(node* root,int level)
                {
                                static int Hight;
                                if(root != NULL)
                                {
                                                hight(root->left,level+1);
                                                hight(root->right,level+1);
                                }
                                if(Hight <= level)
                                {
                                                Hight=level;
                                }
                                return Hight;
                }              
                
                void Preorder(node* root)
                {
                	
			              	 	if(root != NULL)
			                	{
						                		printf("%c ",root->data);
						                		Preorder(root->left);
						                		Preorder(root->right);
								}
				}
				
				node* Delete(node* root,char data)
				{
								if(root == NULL)
								{
												return root;
								}
								else if(data < root->data)
								{
												root->left = Delete(root->left,data);
								}
								else if(data > root->data>data)
								{	
												root->right = Delete(root->right,data);
								}
								else
								{
												if(root->left == NULL && root->right == NULL)
												{
																free(root);
																return NULL;
												}
												else if(root->left == NULL)
												{	
																node* temp = root;
																free(temp);
																root = root->right;
												}
												else if(root->right == NULL)
												{
																node* temp = root;
																free(temp);
																root=root->left;
												}
												else
												{
																node* temp = FindMin(root->right);
																root->data = temp->data;
																root->right = Delete(root->right,temp->data);
												}
								}
				}
				
                int main()
                {
                                node* root = NULL; 
                                root=Insert(root,'f');
                                
                                root=Insert(root,'d');
             
                                root=Insert(root,'j');
             
                                root=Insert(root,'b');

                                root=Insert(root,'e');
                                
                                root=Insert(root,'g');
                                
                                root=Insert(root,'k');
             
                                root=Insert(root,'a');
             
                                root=Insert(root,'c');

                                root=Insert(root,'i');
                                
                                root=Insert(root,'h');
                              //  FindMin(root);
                              //  FindMax(root);
                               // PrintList(root);
                                printf("%d",hight(root,0));
                               // PrintList(root);
                              //  Delete(root,'h');
                              //  printf("\n");
                              //  PrintList(root);
                                return 0;
                }

