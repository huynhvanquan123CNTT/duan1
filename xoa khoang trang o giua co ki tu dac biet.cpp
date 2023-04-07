#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool NhanBietKhoangTrang(char c) {
	return c == ' ' || c == '\t' || c == '\n';
}

bool KiTuDacBiet(char c) {
	return c == ',' || c == '.' || c == '(' || c == ')' 
	|| c == '?' || c == ':' || c == ';' || c == '!';
}

void XoaKhoangTrang(char*);

void XoaKhoangTrang(char *s) {
	int i, j;
	int len = strlen(s);
	for(i = 0; i < len; i++) {
		if(NhanBietKhoangTrang(s[i]) && NhanBietKhoangTrang(s[i + 1])) {
			for(j = i + 1; j < len; j++) {
				s[j] = s[j + 1];
			}
			i--;
			len--;
		} else if(NhanBietKhoangTrang(s[i]) && KiTuDacBiet(s[i + 1])) {
			for(j = i; j < len; j++) {
				s[j] = s[j + 1];
			}
			i--;
			len--;
		} else if(s[i] == '\t') {
			s[i] = ' ';
		}
	}
}

int main(){
	char s[100];
	printf("Nhap vao chuoi: ");
	gets(s);
//	fgets(s, 99, stdin);
	XoaKhoangTrang(s);
	printf("Chuoi da xoa:%s", s);
	return 0;
}
