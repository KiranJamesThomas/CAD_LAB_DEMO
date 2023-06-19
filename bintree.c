#include<stdio.h>
#include<stdlib.h>

struct bin_tree
{
    int data;
    struct bin_tree *right, *left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp=NULL;
    if(!(*tree))
    {
        temp=(node *)malloc(sizeof(node));
        temp->left=temp->right=NULL;
        temp->data=val;
        *tree=temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left,val);
    }
    if(val > (*tree)->data)
    {
        insert(&(*tree)->right,val);
    }
}

void print_preorder(node * tree)
{
    if(tree)
    {
        printf("%d\n", tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

void print_inorder(node * tree)
{
    if(tree)
    {
        print_inorder(tree->left);
        printf("%d\n", tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
    if(tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n", tree->data);
    }

}

void deltree(node * tree)
{
    if(tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }
    else if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

void main()
{
    node *root;
    node *tmp;

    root=NULL;

    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 16);
    insert(&root, 17);
    insert(&root, 2);

    printf("Pre order display\n");
    print_preorder(root);

    printf("In order display\n");
    print_inorder(root);

    printf("Post order display\n");
    print_postorder(root);

    tmp = search(&root, 37);
    if(tmp)
    {
        printf("searched node=%d\n", tmp->data);
    }
    else
    {
        printf("Data not found in tree.\n");
    }

    deltree(root);

}
