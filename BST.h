#include"node.h"

class bst {
    node *root, *cur;
public:
    bst(node*);
    node* insert();
    node* successor(int);
    void preOrder(node*) const;
    void inOrder(node*) const;
	node* minimum(node*) const;
	node* maximum(node*) const;
	node* search(int);
};

bst::bst(node *rootNode = NULL)
    :root(rootNode)
{   }

node* bst::insert() {
    char ch;
    do {
		node *nnode = new node;
        cout<<"Enter data\n";
        cin>>nnode->key;
        if(root == NULL) {
			root = cur = nnode;
		}else {
			cur = root;
			while(cur) {
				if(nnode->key < cur->key) {
					if(cur->left == NULL) {
						cur->left = nnode;
						nnode->parent = cur;
						break;
					}else   cur = cur->left;
                
				}else if(nnode->key >= cur->key) {
					if(cur->right == NULL) {
						cur->right = nnode;
						nnode->parent = cur;
						break;
					}else   cur = cur->right;
				}
			}
		}
        cout<<"Do u want to insert another node\n";
        cin>>ch;
        if(ch == 'n' || ch == 'N')  break;
    }while(1);
	cur = root;
	return root;
}

void bst::inOrder(node *cur) const {
	if(cur) {
		inOrder(cur->left);
		cout<<cur->key<<" ";
		inOrder(cur->right);
	}
}

void bst::preOrder(node *cur) const  {
	if(cur) {
		cout <<cur->key << " ";
		preOrder(cur->left);
		preOrder(cur->right);
	}
}

node* bst::minimum(node *cur) const {
	while(cur->left != NULL)	cur = cur->left;
	return cur;
}

node* bst::maximum(node *cur) const {
	while(cur->right != NULL)	cur = cur->right;
	return cur;
}

node* bst::search(int key) {
	cur = root;
	while(cur != NULL && cur->key != key) {
		if(key < cur->key)	cur = cur->left;
		else cur = cur -> right;
	}
	if(cur->key == key)
		return cur;
	return NULL;
}

node* bst::successor(int key) {
	node *temp, *max;
	cur = search(key);
	max = maximum(root);
	if(cur != NULL && cur != max) {
		if(cur->right != NULL)
			return minimum(cur->right);
		temp = cur->parent;
		while(temp != NULL && cur == temp->right) {
			cur = temp;
			temp = temp->parent;
		}
		return temp;
	}
	return NULL;
}