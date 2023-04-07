#include <stdio.h>
#define max 100
struct pixel{
	int x,y;	
};
struct Hinhchunhat{
	pixel trentrai,duoiphai;	
};
void input_pixel(pixel &a);
void output_pixel(pixel a);
void input_HCN(Hinhchunhat &h);
void output_HCN(Hinhchunhat &h);
float dientich_HCN(Hinhchunhat h);
void input_arr_HCN(Hinhchunhat h[],int &n);
void output_arr_HCN(Hinhchunhat h[],int n);
float dientich_n_HCN(Hinhchunhat h[],int n);
void ghifile(FILE *f,char filename[],Hinhchunhat h[],int n);
void docfile(FILE *f,char filename[],Hinhchunhat h[],int &n);
int main(int argc, char *argv[])
{
	Hinhchunhat h1[max],h2[max];
	int n1,n2;
	FILE *f;
	char filename[20];
	input_arr_HCN(h1,n1);
	printf("nhap ten file:");scanf("%s",&filename);
	ghifile(f,filename,h1,n1);
	docfile(f,filename,h2,n2);
	output_arr_HCN(h2,n2);
	//output_arr_HCN(h,n);
//	printf("dien tich cua %d HCN la:%f",n,dientich_n_HCN(h,n));
	return 0;
}
void input_pixel(pixel &a){
	printf("nhap diem:");scanf("%d,%d",&a.x,&a.y);
}
void output_pixel(pixel a){
	printf("\nxuat diem (%d,%d)",a.x,a.y);
}
void input_HCN(Hinhchunhat &h){
	printf("nhap diem tren trai:");
	input_pixel(h.trentrai);
	printf("nhap diem duoi phai:");
	input_pixel(h.duoiphai);
}
void output_HCN(Hinhchunhat &h){
	output_pixel(h.trentrai);
	output_pixel(h.duoiphai);
}
float dientich_HCN(Hinhchunhat h){
	float cr=h.duoiphai.x-h.trentrai.x;
	float cd=h.trentrai.y-h.duoiphai.y;
	return cd*cr;
}
void input_arr_HCN(Hinhchunhat h[],int &n){
	printf("nhap so HCN:");scanf("%d",&n);
	for(int i=0;i<n;i++)
		input_HCN(h[i]);
}
void output_arr_HCN(Hinhchunhat h[],int n){
	for(int i=0;i<n;i++)
		output_HCN(h[i]);
}
float dientich_n_HCN(Hinhchunhat h[],int n){
	float s=0;
	for(int i=0;i<n;i++)
		s+=dientich_HCN(h[i]);
	return s;
}
void ghifile(FILE *f,char filename[],Hinhchunhat h[],int n){
	f=fopen(filename,"wb");
	fwrite(&n,sizeof(int),1,f);
	for(int i=0;i<n;i++)
		fwrite(&h[i],sizeof(Hinhchunhat),1,f);
	fclose(f);
}
void docfile(FILE *f,char filename[],Hinhchunhat h[],int &n){
	f=fopen(filename,"rb");
	fread(&n,sizeof(int),1,f);
	for(int i=0;i<n;i++)
		fread(&h[i],sizeof(Hinhchunhat),1,f);
	fclose(f);
}
