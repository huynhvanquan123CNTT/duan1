#include<stdio.h>
#include<string.h>
void chuyen_chu_hoa(char str[]);
void standard(char s[]);
void xoa(char s[],int vt);
int demsotu(char *s);
void xoatoanbo(char *s);
int main(){
	char s1[100], *s2;
	int n;
	s2 = new char[100];
	printf("Nhap chuoi s1: ");
	gets(s1);
	printf("s1 = %s", s1);
	chuyen_chu_hoa(s1);
	printf("\nDay chu da viet hoa tu dau tien: %s", s1);
	standard(s1);
	printf("\nChuoi da xoa khoang trang:%s", s1);
	printf("\nSo tu trong chuoi la: %d", demsotu(s1));
}
//chuyen cac ki tu dau thanh chu in HOA
void chuyen_chu_hoa(char str[]){
	for(int i=0; str[i] != '\0'; i++){
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if(str[i-1] == ' ' || i == 0){
			if(str[i] >= 'a' && str[i] <= 'z')
				str [i] = str[i] - 32;
		}
	}
}
// xoa bo khoang trang dau cuoi va giua
void standard(char s[]){
	for(int i=0; i<strlen(s); i++)
		if(s[i]==' ' && s[i+1]==' '){
			xoa(s,i);
			i--;
		}
	if(s[0]==' ')
		xoa(s,0);
	if(s[strlen(s)-1]==' ')
		xoa(s,strlen(s)-1);
}
void xoa(char s[],int vt){
	for(int i=vt; i<strlen(s); i++)
		s[i] = s[i+1];
}
// dem xem co bao nhieu tu trong S
int demsotu(char *s){
	int n=strlen(s),i;
	int dem=0;
	if(s[0]!=' ')
		dem=1;
	for( i=0;i<n-1;i++)
	{
		if(s[i]==' ' && s[i+1]!=' ')
			dem++;
	}
	return dem;
}

// xoa toan bo khoang trang
void xoatoanbo(char *s){
	char *c = strstr(s, " ");
	while(c!= NULL){
		int t= strlen(s)-strlen(c);
		for(int i=t; i<strlen(s); i++)
			s[i] = s[i+1];
			c= strstr(s," ");
		}
		if(s[0] == ' ')
		s = s+1;
		int n=strlen(s);
		if(s[n-1]==' ')
			s[n-1]= '\0';
}
