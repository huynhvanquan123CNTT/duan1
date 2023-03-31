#include<stdio.h>
#include<string.h>

//void delete1(char s[], int pos, int n){
//	for(int i=1; i<=n; i++)
//		for(int j=pos; j<strlen(s); j++)
//			s[j] = s[j+1];
//}

char *mid(char s[], int pos, int n){
	int j=0;
	char s1[100];
	for(int i=pos; i<pos+n; i++){
		s1[j]=s[i];
		j++;
		s1[j]='\0';
		return &s1[0];
	}
}

int main(){
	char s[100];
	char *s1;
	int pos, n;
	printf("Nhap chuoi: ");
	gets(s);
	printf("Nhap vi tri xoa: ");
	scanf("%d", &pos);
	printf("Nhap so phan tu xoa: ");
	scanf("%d", &n);
//	delete1(s, pos, n);
	s1 = mid(s, pos, n);
//	printf("Ket qua: %s", s);
	printf("Chuoi s1 la: %s", s1);
	return 0;
}
