#include<stdio.h>
long tong(int n);
long tich(int n);
double luythua(float a, int n);
double capsocong(int n, int a, int r);
double capsonhan(int n, int a, int q);
void xuatnhiphan(int n);
int main(){
	int n,r,q;
	float a;
	do{
		printf("\nNhap n: ");
		scanf("%d",&n);
		if(n<0){
			printf("\nNhap lai!");
		}
	}while(n<0);
	printf("\nNhap a: ");
	scanf("%f",&a);
	printf("\nNhap r: ");
	scanf("%d",&r);
	printf("\nNhap q: ");
	scanf("%d",&q);
	printf("\nTong S= %ld",tong(n));
	printf("\nTich P= %ld",tich(n));
	printf("\nLuy thua A= %.2lf",luythua(a,n));
	printf("\nCap so cong voi 10 so tren 1 dong: ");
	for(int i=1; i<=n; i++){
		if(i%10==1)
			printf("\n");
		printf("%5.0lf",capsocong(i,a,r));
	}
	printf("\nCap so nhan voi 10 so tren 1 dong: ");
	for(int i=1; i<=n; i++){
		if(i%10==1)
			printf("\n");
		printf("%5.0lf",capsonhan(i,a,q));
	}
	printf("\nSo %d chuyen sang nhi phan la: ",n);
	xuatnhiphan(n);
}

long tong(int n){
	if(n==0)
		return 0;
	return tong(n-1)+n;
}

long tich(int n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return tich(n-1)*n;
}

double luythua(float a, int n){
	if(n==0)
		return 1;
	return luythua(a, n-1)*a;
}

double capsocong(int n, int a, int r){
	if(n==0)
		return 0;
	if(n==1)
		return a;
	return r+capsocong(n-1, a, r);
			
}

double capsonhan(int n, int a, int q){
	if(n==0)
		return 0;
	if(n==1)
		return a;
	return q*capsonhan(n-1, a, q);
}

void xuatnhiphan(int n){
	if(n>=0){
		if(n/2>0)
		xuatnhiphan(n/2);
		printf("%d", n%2);
	}
}


