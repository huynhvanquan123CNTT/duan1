#include<stdio.h>
#include<math.h>
typedef struct ps{
	int tu;
	int mau;
}PS;
void nhapphanso(PS &phanso);
void xuatphanso(PS phanso);
int ULCN(int a, int b);
void rutgon(PS &phanso);

void nhapphanso(PS &phanso){
	printf("\nNhap vao tu so: ");
	scanf("%d", &phanso.tu);
	do
	{
		printf("Nhap vao mau so: ");
		scanf("%d",&phanso.mau);
		if(phanso.mau==0)
			printf("\nMau phai khac khong Vui long kiem tra lai!!!");
	}while(phanso.mau==0);
}
void xuatphanso(PS phanso){
	printf("%d / %d", phanso.tu, phanso.mau);
}
int UCLN(int a, int b){
	a=abs(a);
	b=abs(b);
	while(a!=b){
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}
void toigian(PS &phanso){
	int c=UCLN(phanso.tu,phanso.mau);
	phanso.tu=phanso.tu/c;
	phanso.mau=phanso.mau/c;
}
int main(){
	PS p;
	printf("Nhap phan so");
	nhapphanso(p);
	printf("\nPhan so vua nhap: ");
	xuatphanso(p);
	toigian(p);
	printf("\nPhan so sau khi toi gian: ");
	xuatphanso(p);
	return 0;
} 
