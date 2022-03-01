#include<bits/stdc++.h>
using namespace std;


// de quan li 1 node chi can node dau tien cua no thoi
//khi ch co phan tu nao thi node dau tien se la null

struct Node{
	int data;//8 b(thuc te la 4b) luon du 8b
	Node *next;//8b luu dia chi cua node tiep theo
};

typedef struct Node* node;

//tao 1 node moi
node makenode(int x){  //tao 1 node moiw voi data la x
	node tmp= new Node();//tmp dang la con tro nen phai dung ->
	tmp->data=x;
	tmp->next=NULL;//nullptr
	return tmp;
}

// kime tra rong 
bool empty(node a){//a la node dau trong dslk
	return a==NULL;
}

//dem so phan tu trong node
int size(node a){
	int cnt=0;
	while (a!=NULL){
		++cnt;
		a=a->next;//gan dic chi cua node tiep theo cho node hien tai
	}
	return cnt;
}



//them vao dau dslk
void insertfirst(node &a,int x){
	node tmp=makenode(x);
	if(a==NULL){
		a=tmp;
	}
	else{
		tmp->next=a;
		a=tmp;//cap nhat lai a la tmp de dua a ve lai la phan tu dau tien
	}
}



//chen vao cuoi
void insertlast(node &a,int x){
	node tmp=makenode(x);
	if(a==NULL){
		a=tmp;
	}
	else{
		node p=a;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=tmp;
	}
}

//them vao giua
void insertmid(node &a,int x,int pos){ //chen x vao pos
    int n=size(a);
	if(pos<=0||pos>n+1){
		cout<<"vi tri khong hop le"<<endl;//hoac la return;
	}
	else if(pos==1){
		insertfirst(a,x);return ;
	}
	else if(pos==n+1){
		insertlast(a,x);return;
	}
	node p=a;
	//cho next cua tmp cho vao pos
	//cho next pos-1 tro vao tmp
	for(int i=1;i<pos-1;i++){//lap pos-2 lan thoi
		p=p->next;
	}
	node tmp = makenode(x);
	tmp->next = p->next;//p dang la pos -1 khi do p->next se chi den pos
	p->next=tmp;
	
}

//xoa dau
void deleteF(node &a){
	if(a==NULL) return;
	a=a->next;
}

//xoa cuoi
void deleteEnd(node &a){
	if(a==NULL) return ;
	node truoc=NULL,sau=a;
	while(sau->next!=NULL){//sau la not cuoi cung ,truoc la phan tu sat node cuoi cung
	    truoc =sau;
	    sau=sau->next;
	}
	if(truoc==NULL){//danhsach co 1 phan tu thi cho a=mull de xoa di la xong
		a=NULL;
	}
	else {
		truoc->next=NULL;
	}
}

//xoa 1 phan tu nao do
void deletemid(node &a,int pos){
	if(pos<=0||pos>size(a)) return ;
	node truoc =NULL,sau=a;
	for(int i=1;i<pos ;i++){
		truoc =sau;
		sau=sau->next;
	}
	if(truoc==NULL){
		a=a->next;
	}
	else {
		truoc->next=sau->next;//node sau pos
	}
}
void in(node a){
	cout<<"-------------------------------------"<<endl;
	while(a!=NULL){
		cout<<a->data<<endl;
		a=a->next;
	}
	cout<<"-------------------------------------"<<endl;
}


int main(){
    //	cout<<sizeof(Node)<<endl; he dieu hanh 64 bit thi luon la 8b
	node head=NULL;//khoi tao node dau trong dslk
	while(1){
		cout<<"--------------menu-------------------"<<endl;
		cout<<"1.chen dau"<<endl;
		cout<<"2.chen cuoi"<<endl;
		cout<<"3.chen giua"<<endl;
		cout<<"4.xoa dau"<<endl;
		cout<<"5.xoa cuoi"<<endl;
		cout<<"6.xoa giua"<<endl;
		cout<<"7.in"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"Nhap lua chon : ";
		int lc;cin>>lc;
		if(lc==1){
			int x;cout<<"nhap gia chen : ";cin>>x;
			insertfirst(head,x);
		}
		else if(lc==2){
			int x;cout<<"nhap gia chen : ";cin>>x;
			insertlast(head,x);
		}
		else if(lc==3){
			int x;cout<<"nhap gia chen : ";cin>>x;
			int pos;
			cout<<"nhap vi tri chen : ";cin>>pos;
			insertmid(head,x,pos);
		}
		else if(lc==4){
		    deleteF(head);
		}
		else if(lc==5){
		    deleteEnd(head);
		}
		else if(lc==6){
		    int pos;
			cout<<"nhap vi tri xoa : ";cin>>pos;
			deletemid(head,pos);
		}
		else if(lc==7){
			in(head);
		}
	}
	return 0;
}
