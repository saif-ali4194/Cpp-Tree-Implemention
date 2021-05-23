#include"BST.h"

void menu() {
	cout<<"\t\t\tTREE\n";
	cout<<"1.\tinsert\n2.\tpreOrder\n3.\tinOrder\n4.\ttree_successor\n5.\tminimum & maximum\n6.\texit\n";
}
int main() {
	char ch;
	node *root = NULL, *temp = NULL; 
	int key;
	bst obj;
	while(1) {
		system("cls");
		menu();
		cin>>ch;
		if(ch == '1') {
			system("cls");
			root = obj.insert();
		}else if(ch == '2') {
			system("cls");
			if(root != NULL)
				obj.preOrder(root);
			else	cout<<"Create a tree first\n";
			system("pause");
		}else if(ch == '3') {
			if(root != NULL)
				obj.inOrder(root);
			else	cout<<"Create a tree first\n";
			system("pause");
		}else if(ch == '4') {
			system("cls");
			if(root != NULL) {
				cout<<"Enter node key whose sucessor u want to find\n";
				cin>>key;
				temp = obj.successor(key);
				if(temp != NULL)	cout<<"successor: "<<temp->key<<endl;
				else cout<<"key u entered is either largest node or doesn't exist at all!\n";
			}else	cout<<"Create a tree first\n";
			system("pause");
		}else if(ch == '5') {
			if(root != NULL) {
				temp = obj.minimum(root);
				cout<<"Minimun: "<<temp->key<<endl;
				temp = obj.maximum(root);
				cout<<"Maximum: "<<temp->key<<endl;
			}else	cout<<"Create a tree first\n";
			system("pause");
		}else if(ch == '6')		exit;
	}
}