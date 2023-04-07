#include<stdio.h>
#include<math.h>
struct Point{
	int x, y;
};
void input_point(Point &p){
	printf("Nhap toa do cua 1 diem: ");
	scanf("%d,%d", &p.x, &p.y);
}
void output_point(Point p){
	printf("(%d,%d)", p.x, p.y);
}
float P1P2(Point P1,Point P2){
	return sqrt((P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y));
}
void input_arr_point(Point p[], int &n){
	printf("nhap so dinh cua da giac: ");
	scanf("%d", &n);
	for(int i=0;i<n; i++)
		output_point(p[i]);
}
void ouput_arr_point(Point p[], int n){
	for(int i=0;i<n; i++)
		output_point(p[i]);
}
float SP1P2P3(Point P1, Point P2, Point P3){
	float a, b, c;
	a = P1P2(P1.P2);
	b = P1P2(P1.P3);
	c = P1P2(P2.P3);
	if(a+b>c && a+c>b && b+c>a)
		float p = (a+b+c)/2;
		return sqrt(p*(p-a)*(p-b)*(p-c));
}
float S(Point p[]){
	float dt = 0;
	for(int i=1; i<n-1; i++)
		dt = p[i]+p[i-1]+p[i-2];
}

int main(){
	
}
