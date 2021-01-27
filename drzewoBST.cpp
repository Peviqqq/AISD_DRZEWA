#include <iostream>
#include <string>
using namespace std;


struct node{
	int data;
	node* left;
	node* right;
	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

void showNode(node* tree){
	if(tree == NULL){
		return;
	}
	cout<<tree->data<<" ";
	showNode(tree->left);
	showNode(tree->right);
}



//zadanie 2

node* zad2a(int* a, const int k){
	if(k==1){
		node* scho = new node(a[0]);
		scho->left = NULL;
		scho->right = NULL;
		return scho;
	}else{
		node* scho = new node(a[k/2]);
		scho->left = zad2a(a,k/2);
		scho->right = zad2a(a+k/2+1,k/2);
		return scho;
	}
}

void zad2b(node* tree, int a[], int *i ){
		
	if(tree == NULL) return;
	a[*i] = tree->data;
	(*i)++;
	zad2b(tree->left, a, i);
	zad2b(tree->right, a, i);
	
}



//zadanie 3

bool search(node* tree, int x){
	if(tree == NULL){
		return false;
	}
	if(tree->data == x){
		return true;
	}else if(x >= tree->data){
		search(tree->right, x);		
	}else{
		search(tree->left, x);
	}
}

int main(){
	
	//zadanie 2
	
	node* drze = new node(8);
	drze->left = new node(3);
	drze->left->left = new node(1);
	drze->left->right = new node(6);
	drze->left->right->left = new node(4);
	drze->left->right->right = new node(7);
	drze->right = new node(10);
	drze->right->right = new node(14);
	drze->right->right->left = new node(13);
	int n = 9;
	int* a = new int[n];
	int ii=0;
	zad2b(drze, a, &ii);
	for(int i=0;i<=8;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;	
	node* nowy = zad2a(a,n);
	showNode(nowy);
	
	
	//zadanie 3
	node* drzewo = new node(8);
	drzewo->left = new node(4);
	drzewo->right = new node(9);
	drzewo->left->left = new node(2);
	drzewo->left->right = new node(5);
	
	if(search(drzewo, 5)==true){//wynik: jest
		cout<<"jest"<<endl;
	}else{
		cout<<"nie jest"<<endl;
	}
	
	node* drze1 = new node(925);
	drze1->left = new node(202);
	drze1->left->right = new node(911);
	

	//zadanie 4
	/*
	a) 2, 252, 401, 398, 330, 344, 397, 363.
	b) 924, 220, 911, 244, 898, 258, 362, 363.   
	c) 925, 202, 911, 240, 912, 245, 363.           - nie mo¿e byæ sprawdzone poniewa¿ 245 jest prawym wnukiem 911 co nie mo¿e siê zdarzyæ w drzewie BST
	d) 2, 399, 387, 219, 266, 382, 381, 278, 363.
	e) 935, 278, 347, 621, 299, 392, 358, 363.      - nie mo¿e byæ sprawdzone poniewa¿ 299 jest prawym wnukiem 347 co nie mo¿e siê zdarzyæ w drzewie BST
	*/
	
	
	
	return 0;
}
