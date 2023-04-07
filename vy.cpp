#include<stdio.h>
#include<conio.h>
#include<string.h>

struct sinhvien 
{
	char ho[100];
	char ten[100];
	int mssv;
};

void nhap(sinhvien sv[], int &n) {
	printf("nhap so sv muon them:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("nhap mssv: ");
		scanf("%d", &sv[i].mssv);
		printf("nhap ho sv \n");
		getchar(); 
		gets(sv[i].ho);
		fflush(stdin);
		printf("nhap ten sv ");
		gets(sv[i].ten);
	}
}

void xuat(sinhvien sv[], int n) {
	printf("\n\nthong tin sinh vien:");
	for (int i = 0; i < n; i++) {
		printf("\nsinh vien thu %d\n", i + 1);
		printf("mssv:%d\nho sinh vien:%s\nten sinh vien:%s ", sv[i].mssv, sv[i].ho, sv[i].ten);
	}
}

int main() {
	sinhvien sv[100];
	int n;
	nhap(sv, n);
	xuat(sv, n);
	getch();
	return 0;
}
