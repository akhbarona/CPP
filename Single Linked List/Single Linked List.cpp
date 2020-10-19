#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct TElmlist *address;
typedef struct TElmlist{
	infotype info;
	address next;
}ElmtList;

struct List{
	address first;
};

void createList(List *L){
	(*L).first=NULL;
}

bool IsEmpty(List *L){
	return ((*L).first==NULL);
}

address Allocation(infotype x){
	address NewElmt;
	NewElmt = new ElmtList;
	NewElmt->info=x;
	NewElmt->next=NULL;
	return NewElmt;
}

void Deallocation(address hapus){
	free(hapus);
}

void InsertFirst(List *L, infotype x){
	address NewElmt;
	NewElmt = Allocation(x);
	
	if(NewElmt!=NULL){
		NewElmt->next = (*L).first;
		(*L).first = NewElmt;
	}
}

void InsertAfter(List *L,infotype x, infotype y){
	address Baru, ptr;
	Baru = Allocation(x);
	if((*L).first==NULL){
		(*L).first=Baru;
	}else{
		ptr = (*L).first;
		while(ptr->info!=y){
			ptr = ptr->next;
		}
		Baru->next = ptr->next;
		ptr->next = Baru;
	}
}

void InsertBefore(List *L, infotype x, infotype y){
	address Baru,ptr;
	Baru = Allocation(x);
	if((*L).first==NULL){
		(*L).first=Baru;
	}else{
		ptr = (*L).first;
		while(ptr->next->info!=y){
			ptr=ptr->next;
		}
		Baru->next = ptr->next;
		ptr->next = Baru;
	}
}

void InsertLast(List *L, infotype x){
	address Baru,ptr;
	Baru = Allocation(x);
	
	if((*L).first==NULL){
		(*L).first=Baru;
	}else{
		ptr = (*L).first;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = Baru;
	}
}

void DeleteFirst(List *L, infotype *hapus);
void DeleteBefore;
void DeleteAfter;

int main(){
	List d;
	address view;
	createList(&d);
	InsertFirst(&d,2);
	InsertFirst(&d,1);
	InsertLast(&d,5);
	InsertFirst(&d,3);
	InsertBefore(&d,6,1);
	InsertAfter(&d,7,1);
	
	view = d.first;
	while(view!=NULL){
		cout<< view->info<<" ";
		view = view->next;
	}
}
