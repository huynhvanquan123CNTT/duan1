#include<stdio.h>
struct ngaynhap{
	int ngay, thang, nam;
};

struct hanghoa{
	char ten[30];
	char mahanghoa[20];
	int soluong[100];
	ngaynhap ngayin;
};

void nhaphanghoa(hanghoa &X){
	printf("Nhap ten hang hoa: ");
	gets(X.ten);
	printf("\nNhap ma hang hoa: ");
	gets(X.mahanghoa);
	printf("\nNhap so luong hang hoa: ");
	scanf("%d", X.soluong);
	printf("\nNhap ngay, thang, nam hang hoa: ");
	scanf("%d %d %d", &X.ngayin.ngay, &X.ngayin.thang, &X.ngayin.nam);
}
int xuat(hanghoa X){
	printf("\nTen hang hoa: %s", X.ten);
	printf("\nMa hang hoa: %s", X.mahanghoa);
	printf("\nSo luong hang hoa: %d", *X.soluong);
	printf("\nNgay thang nam cua hang hoa: %d %d %d", X.ngayin.ngay, X.ngayin.thang, X.ngayin.nam);
}
 int main(){
 	hanghoa X;
	nhaphanghoa(X);
	xuat(X);
 	return 0; 
}
