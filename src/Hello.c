﻿#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define space ' '

void bai1() {
	printf("Nhap so co 3 chu so:");
	int n,so1,so2,so3;
	scanf("%d",&n);
	
	so1 = n % 10;
	so2 = (n / 10) % 10;
	so3 = n / 100;
	int top, middle,bottom;
	if (so1 > so2 &&so1>so3)
		top = so1;
	else if (so2 > so1 &&so2>so3)
		top = so2;
	else if (so3 > so1 &&so3>so2)
		top = so3;
	if (so1 < so2&&so1 < so3)
		bottom = so1;
	else if (so2 < so1&&so2 < so3)
		bottom = so2;
	else if (so3 < so1&&so3 < so2)
		bottom = so3;
	if (so1 > so2&&so1 < so3)
		middle = so1;
	else if (so2 > so1&&so2 < so3)
		middle = so2;
	else if (so3 > so1&&so3 < so2)
		middle = so3;
	printf("so sap xep theo thu tu giam dan la:%d%d%d",top,middle,bottom);
}

void bai2() {
	printf("Nhap vao 1 chuoi:");
	char a[100];
	int demhoa = 0;
	int demthuong = 0;
	scanf("%s", a);
	for (int i = 0; i < strlen(a); i++)
	{
		if (isupper(a[i]))
			demhoa++;
		if (islower(a[i]))
			demthuong++;
	}
	printf("So ki tu thuong: %d", demthuong);
	printf("So ki tu hoa: %d", demhoa);

}
void bai3() {
	int m;
	int sotien;
	printf("Nhap so m da di:");
	scanf("%d", &m);
	if (m == 1000||m<1000)
		sotien = 10000;
	if (m > 1000 && m <= 30000)
		sotien = 10000 + ((m - 1000) / 200) * 1500;
	if (m > 30000)
		sotien = 10000 + (29000 / 200) * 1500 + (m - 30000) * 8000;
	printf("So tien phai tra:%d vnd cho %d m da di", sotien, m);

}
void bai4() {
	int i, j;
	printf("Nhap chieu cao cho tam giac can:");
	int h;
	scanf("%d", &h);
	for (i = 1; i <= h; i++)
	{
		for (j = 1; j <= h - i; j++)
			printf(" ");
		for (j = 1; j <= 2 * i - 1; j++)
			printf("*");
		printf("\n");
	}
}
int kiemtranamnhuan(int nam) {
	if (nam % 19 == 0 || nam % 19 == 3 || nam % 19 == 6 || nam % 19 == 9 || nam % 19 == 11 || nam % 19 == 14 || nam % 19 == 17)
		return 1;
	else
	{
		return 0;
	}
}
int kiemtrathoigianhople(int ngay,int thang,int nam){
	int kiemtra;
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:if (ngay <= 31)
		kiemtra = 1;
			else kiemtra= 0;
		break;
	case 2:if (ngay <= 29 && kiemtranamnhuan(nam) == 1)
		kiemtra = 1;
		   else if (ngay <= 28 && kiemtranamnhuan(nam) != 1)
			   kiemtra = 1;
		   else kiemtra = 0;
		break;
	case 4:
	case 6:
	case 9:
	case 11: if (ngay <= 30)
		kiemtra = 1;
			 else kiemtra = 0;
		break;


	default:
		break;
	}
	return kiemtra;
}
void bai5() {
	int ngay, thang, nam;
	do {
		printf("Nhap ngay:");
		scanf("%d",&ngay);
		printf("Nhap thang:");
		scanf("%d",&thang);
		printf("Nhap nam:");
		scanf("%d", &nam);
		if (ngay>31 || ngay<0 || thang>12 || thang<0 || nam<0 ||kiemtrathoigianhople(ngay,thang,nam)!=1)
			printf("Ban nhap sai dinh dang.Vui long nhap lai!!!\n");
	} while (ngay>31||ngay<0||thang>12||thang<0||nam<0||kiemtrathoigianhople(ngay, thang, nam) != 1);
	printf("%d-%d-%d\n",ngay,thang,nam);
	if (kiemtranamnhuan(nam) == 1)
		printf("Nam nay la nam nhuan");
	else
		printf("Nam nay khong phai nam nhuan");

}

void bai6() {
	
	char a[100];
	
	getchar();
	printf("Nhap vao 1 xau ki tu:\n");
	fgets(a, 100, stdin);
	while (a[0] == ' ') {     //xoa khoang trang dau
		for (int i = 0; i < strlen(a); i++)
		{
			a[i] = a[i + 1];
		}
	}
	int i=0,j;
	while (i < strlen(a)) {  //xoa khoang trang cuoi
		if (a[i] == ' '&&a[i + 1] == ' ')
			for (j = i; j < strlen(a); j++) {
				a[j] = a[j + 1];
			}
		i++;
	} 
	int k = 0,l;
	while (k < strlen(a)) {// xoa khoang trang truoc dau phay
		if (a[k] == ' '&&a[k + 1] == ',')
			for (l= k; l < strlen(a); l++) {
				a[l] = a[l + 1];
				a[l + 1] = ' ';
			}
		k++;
	}
	for (int z = 0; z < strlen(a); z++)
	{
		if (a[z] == '.'&&a[z + 1] == '.'|| a[z] == ','&&a[z + 1] == ',')//xoa 2 dau cham,dau phay,dau cach canh nhau
			for (int t = z; t < strlen(a) ; t++)
			{
				a[t] = a[t + 1];
			}
	}
	for (int z = 0; z < strlen(a); z++)
	{
		if (a[z] == ' '&&a[z + 1] == ' ' )//xoa 2 dau cach canh nhau
			for (int t = z; t < strlen(a); t++)
			{
				a[t] = a[t + 1];
			}
	}
	int n = strlen(a);
	for (int b = 0; b < n; b++)
	{
		if (a[b] == ',') {
			for (int e = n-1; e >= b+1; e--)
			{
				a[e] = a[e-1];
			}
			a[b+1] = ' ';
			n++;
			break;
		}
	}
	for (int kk = 0; kk < strlen(a); kk++) //hien thi
	{
		putchar(a[kk]);
	}
}


void bai7() {
	int a, b,i;
	printf("Nhap so nguyen thu nhat:");
	scanf("%d",&a);
	printf("Nhap so nguyen thu hai:");
	scanf("%d", &b);
	if(a<b)
		for ( i = b; i >0; i--)
		{
			if (b%i == 0 && a%i == 0)
			{
				printf("UCLN cua 2 so la:%d\n", i);
				break;
			}
		}
	else
		for (i = a; i >0; i--)
		{
			if (a%i == 0 && b%i == 0)
			{
				printf("UCLN cua 2 so la:%d\n", i);
				break;
			}
		}
	int j=2;
	while (a%b != 0)
	{
		a = a / (j - 1)*j; j++;
	}
	printf("BCNN cua 2 so la:%d", a);



}


void bai8() {
	int i;
	printf("Nhap vao xau ki tu:");
	char s[100];
	scanf("%s", s);
	for (i = strlen(s)-1; i >= 0; i--)
		putchar(s[i]);
}
int main() {
	int chon;
label:
	do
	{
		printf("Chon bai:\n");
		printf("1. Bài 1\n");
		printf("2. Bài 2\n");
		printf("3. Bài 3\n");
		printf("4. Bài 4\n");
		printf("5. Bài 5\n");
		printf("6. Bài 6\n");
		printf("7. Bài 7\n");
		printf("8. Bài 8\n");
		
		scanf("%d", &chon);
		switch (chon)
		{
		case 1: bai1();
			printf("\n");
			break;
		case 2:  bai2();
			printf("\n");
			break;

		case 3: bai3();
			printf("\n");
			break;

		case 4:
			bai4();
			printf("\n");
			break;

		case 5:
			bai5();
			printf("\n");

			break;

		case 6:
			bai6();
			printf("\n");
			break;

		case 7:
			bai7();
			printf("\n");

			break;

		case 8:
			bai8();
			printf("\n");

			break;

		default:
			printf("Nhap lai:\n");
			goto label;
			break;
		}
	} while (chon>0||chon<9);

	
	return 0;
}
