#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next;
};
typedef struct node Node;
Node* taomotnot(int x){
	Node* p;
	p = (Node*)malloc(sizeof(struct node));
	p->data = x;
	p->next = NULL;
	return p;
}
Node* chendau(Node *head, int x){
	Node* p = taomotnot(x);
	if(head == NULL){
		head = p;
	}else{
		p->next = head;
		head = p;
	}
	return head;
}
Node* chencuoi(Node* head, int x){
	Node* q = taomotnot(x);
	Node* p;
	if(head == NULL){
	head = q;}else{
		p = head;
		while(p->next!= NULL){
			p = p->next;
		}
		p->next = q;
		q->next = NULL;
	}
	return head;	
}
Node* chentaivitri(Node* head, int x, int n){
	Node* r;
	int j;
	for(j = 1, r = head; r != NULL; r=r->next, j++){
	;}
	if(j <= n-1){
		printf("\nKhong ton tai vi tri %d de chen\n", n);
	}else{
	Node* q = taomotnot(x);
	Node* p;
	if(head == NULL){
	head = q;}else{
		p = head;
		int k = 1;
		while(k<n-1){
		p = p->next;
		k = k + 1;
		}
		q->next = p->next;
		p->next = q;
		}
	}
return head;	
}
Node* chensaugiatri(Node* head, int x, int y){
	Node* q = taomotnot(x);
	Node* p;
	int k;
	for(k = 0, p = head; p!= NULL; p=p->next, k++){
		if(p->data == y){
			q->next = p->next;
			p->next = q;
		}	
	}
	return head;
}
Node* xoadau(Node* head){
	if(head!=NULL){
		head = head->next;
	}
	return head;
}
Node* xoacuoi(Node* head){
	Node* p;
	p = head;
	while(p->next->next != NULL){
		p=p->next;
	}
	p->next = NULL;
	return head;
}
Node* xoabatky(Node* head, int value){
	Node* p;
	p = head;
	int k = 0;
	while(p->next != NULL){
		if(p->next->data == value){
		p->next = p->next->next;
		k = k + 1;
		}else{
			p=p->next;
		}	
	}
	if(0==k) printf("\n\n\tKhong co de xoa\n");
	return head;
}
Node* nhapdanhsach(){
	Node* head = NULL;
	int n, x;
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		printf("Nhap gia tri cua node thu %d: ", i);
		scanf("%d", &x);
		head = chencuoi(head, x);
	}
	return head;
}
void indanhsach(Node* head){
	Node* p;
	for(p = head; p!= NULL; p=p->next){
		printf("\n\t\t%d", p->data);
	}
}
int main(){
	int n, x;
	Node* head = nhapdanhsach();
	printf("\n\n\tdanh sach ban dau la");
	indanhsach(head);
	
	head = chendau(head, 100);
	head = chendau(head, 50);
	head = chencuoi(head, 200);
	head = chencuoi(head, 300);
	printf("\n\n\tsau khi chen dau va cuoi");
	indanhsach(head);
	
	head = chensaugiatri(head, 888, 6);
	printf("\n\n\tsau khi chen sau gia tri");
	indanhsach(head);
	
	head = chentaivitri(head, 999, 200);
	printf("\n\n\tsau khi chen tai vi tri");
	indanhsach(head);
	
	//head = xoacuoi(head);
	//printf("\n\n\txoa cuoi");
	//indanhsach(head);
	
	head = xoabatky(head, 1000);
	printf("\n\n\tsau khi xoa bat ky");
	indanhsach(head);
	return 0;
}
