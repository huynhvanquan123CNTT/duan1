#include <stdio.h>
#include <string.h>

void hienThiTenCot();

struct HoTen{
	char ho[20];
	char dem[20];
	char ten[20];
};

struct DiemMH{
	float TK, GK, CK, tbc;
};

struct SinhVien{
	int ma;
	struct HoTen hoVaTen;
	int tuoi;
	char gioiTinh[10];
	struct DiemMH diem;
};

void nhapDiem(struct DiemMH* diem){
	printf("TK: ");
	scanf("%f", &diem->TK);
	printf("GK: ");
	scanf("%f", &diem->GK);
	printf("CK: ");
	scanf("%f", &diem->CK);
	diem->tbc = (diem->TK*2 + diem->GK*3 + diem->CK*10) / 10;
}

void nhapHoTen(struct HoTen* ten){
	printf("Ho: ");
	scanf("%s", ten->ho);
	printf("Dem: ");
	getchar();
	gets(ten->dem);
	printf("Ten: ");
	scanf("%s", ten->ten);
}

struct SinhVien nhapSV(){
	struct SinhVien sv;
	printf("Nhap ma: "); 
	scanf("%d", &sv.ma);
	nhapHoTen(&sv.hoVaTen);
	printf("Tuoi: ");
	scanf("%d", &sv.tuoi);
	printf("Gioi tinh: ");
	scanf("%s", sv.gioiTinh);
	nhapDiem(&sv.diem);
	return sv;
}

void hienThiTTSV(struct SinhVien sv){
	printf("%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
	sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.tuoi, sv.gioiTinh,
	sv.diem.TK, sv.diem.GK, sv.diem.CK, sv.diem.tbc);
}

void sapXepTheoTen(struct SinhVien* ds, int slsv){
	for(int i = 0; i < slsv - 1; i++){
		for(int j = slsv - 1; j > i; j--){
			if(strcmp(ds[j].hoVaTen.ten, ds[j-1].hoVaTen.ten) < 0){
				struct SinhVien sv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = sv;
			}
		}
	}
}

void sapXepTheoDiem(struct SinhVien* ds, int slsv){
	for(int i = 0; i < slsv - 1; i++){
		for(int j = slsv - 1; j > i; j --){
			if(ds[j].diem.tbc > ds[j - 1].diem.tbc) {
				struct SinhVien sv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = sv;
			}
		}
	}
}

void timTheoTen(struct SinhVien* ds, int slsv){
	char ten[20];
	printf("Nhap ten: ");
	scanf("%s", ten);
	hienThiTenCot();
	int timSV = 0;
	for(int i = 0; i < slsv; i++){
		if(strcmp(ten, ds[i].hoVaTen.ten) == 0){
			hienThiTTSV(ds[i]);
			timSV = 1;
		}
	}
	if(timSV == 0){
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}
}

void ghiFile(struct SinhVien* ds, int slsv){
	FILE* fOut = fopen("SV.txt", "a");
	for(int i = 0; i < slsv; i++){
		struct SinhVien sv = ds[i];
		fprintf(fOut, "%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
		sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.tuoi, sv.gioiTinh,
		sv.diem.TK, sv.diem.GK, sv.diem.CK, sv.diem.tbc);
	}
	fclose(fOut);
}

void hienThiTenCot(){
	printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
		"Ma SV", "Ho", "Dem", "Ten", "Tuoi", "Gioi Tinh", 
		"Diem TK", "Diem GK", "Diem CK", "Diem TBC");
}

int main(){
	struct SinhVien dssv[100];
	int slsv = 0;
	int luaChon;
	do{
		printf("=============== MENU ===============");
		printf("\n1. Them Sinh vien vao danh sach.");
		printf("\n2. Hien thi danh sach sinh vien.");
		printf("\n3. Sap xep theo ten.");
		printf("\n4. Sap xep theo diem giam dan.");
		printf("\n5. Tim sinh vien theo ten.");
		printf("\n6. Ghi thong tin sinh vien ra file.");
		printf("\n0. Thoat chuong trinh.");
		printf("\nBan chon ? ");
		
		scanf("%d", &luaChon);
		struct SinhVien sv;
		int i;
		switch(luaChon) {
			case 0:
				break;
				
			case 1:
				sv = nhapSV();
				dssv[slsv++] = sv;
				break;
				
			case 2:
				hienThiTenCot();
				for(i = 0; i < slsv; i++) {
					hienThiTTSV(dssv[i]);
				}
				break;
				
			case 3:
				sapXepTheoTen(dssv, slsv);
				hienThiTenCot();
				for(i = 0; i < slsv; i++) {
					hienThiTTSV(dssv[i]);
				}
				break;
				
			case 4:
				sapXepTheoDiem(dssv, slsv);
				hienThiTenCot();
				for(i = 0; i < slsv; i++) {
					hienThiTTSV(dssv[i]);
				}
				break;
				
			case 5:
				timTheoTen(dssv, slsv);
				break;
				
			case 6:
				ghiFile(dssv, slsv);
				break;
				
			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}
	}while(luaChon);
	return 0;
}
