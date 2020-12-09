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

Node* chenthanhvitri(Node* head, int x, int n){
	Node* r;
	int j;
	for(j = 1, r = head; r != NULL; r=r->next, ++j){
	;}
	if(n <= 0||j <= n-2){
		printf("\nKhong ton tai vi tri %d de chen\n", n);
	}else{
	Node* q = taomotnot(x);
	Node* p;
	if(head == NULL){
	head = q;}else{
		p = head;
		int k = 1;
		while(k<=n-2){
		p = p->next;
		k = k + 1;
		}
		q->next = p->next;
		p->next = q;
		}
	}
return head;	
}

Node* chensaugiatrivalue(Node* head, int x, int value){
	Node* p;
	int k, soluong = 0;
	for(k = 1, p = head; p!= NULL; p=p->next, k++){
		if(p->data == value){
			chenthanhvitri(head, x, k+1);
			soluong++;
		}	
	}
	if(0 == soluong) printf("\n\tKhong ton tai node co gia tri %d de chen sau", value);
	return head;
}

Node* chentruocgiatrivalue(Node* head, int x, int value){
	Node* p;
	int k, soluong = 0;
	if(head == NULL){
		chendau(head, x);
	}
	for(k = 2, p = head; p!= NULL; p=p->next, k++){
		if(p->data == value){
			chenthanhvitri(head, x, k-1);
			soluong++;
		}	
	}
	if(0 == soluong) printf("\n\tKhong ton tai node co gia tri %d de chen truoc\n", value);
	return head;
}

Node* xoadau(Node* head){
	Node* q;
	if(head == NULL){
		puts("\n\tKhong co gi de xoa");
	}else{
		q = head;
		head = head->next;
		free(q);
	}
	return head;
}

Node* xoacuoi(Node* head){
	Node* q;
	Node* p;
	if(head == NULL){
		puts("\n\tKhong co gi de xoa");
	}else{
		p = head;
		while(p->next->next != NULL){
		p=p->next;
		}
		q = p->next;
		p->next = NULL;
		free(q);
	}
	return head;
}

Node* xoanodetaivitri(Node* head, int n){
	Node* xoanodecogiatrivalue(Node* head, int value);
	Node* q;
	Node* p;
	if(head == NULL){
		puts("\n\tKhong co gi de xoa");
	}else{
		if(n == 1){
		head = xoadau(head);
		}else{
			p = head;
			int k = 2;
			while(k!=n){
				p=p->next;
				k = k+1;
			}
			q = p->next;
			p->next = p->next->next;
			free(q);
		}
	}
	return head;
}
	
Node* xoanodecogiatrivalue(Node* head, int value){
	Node* q;
	Node* p;
	if(head == NULL){
		puts("\n\tKhong co gi de xoa");
	}else{
		p = head;
		if(p->data == value){
		head = xoadau(head);
		}else{
			while(p->next->data != value){
			p=p->next;
			}
			q = p->next;
			p->next = p->next->next;
			free(q);
		}
	}
	return head;
}

Node* nhapdanhsach(){
	Node* head = NULL;
	int n, x;
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		printf("Nhap gia tri can them: ");
		scanf("%d", &x);
		head = chencuoi(head, x);
	}
	return head;
}

void indanhsach(Node* head){
	Node* p;
	for(p = head; p!= NULL; p=p->next){
		printf("\t%d", p->data);
	}
}

int main(){
	int n, x;
	Node* head = nhapdanhsach();
	printf("\n\n\tDanh sach ban dau la\n");
	indanhsach(head);
	
	head = chendau(head, 2);
	head = chendau(head, 1);
	head = chencuoi(head, 19);
	head = chencuoi(head, 20);
	printf("\n\tSau khi chen dau va cuoi\n");
	indanhsach(head);
	
	head = chensaugiatrivalue(head, 6, 4);
	printf("\n\tSau khi chen sau gia tri\n");
	indanhsach(head);
	
	head = chenthanhvitri(head, 7, 6);
	printf("\n\tSau khi chen thanh vi tri\n");
	indanhsach(head);
	
	head = chentruocgiatrivalue(head, 5, 6);
	printf("\n\tSau khi chen truoc gia tri\n");
	indanhsach(head);
	
	head = xoadau(head);
	printf("\n\tSau khi xoa dau\n");
	indanhsach(head);
	
	head = xoacuoi(head);
	printf("\n\tSau khi xoa cuoi\n");
	indanhsach(head);
	
	head = xoanodetaivitri(head, 4);
	printf("\n\tSau khi xoa node tai vi tri\n");
	indanhsach(head);
	
	head = xoanodecogiatrivalue(head, 19);
	printf("\n\tSau khi xoa node co gia tri\n");
	indanhsach(head);
	
	return 0;
}
