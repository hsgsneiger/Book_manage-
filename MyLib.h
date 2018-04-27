#pragma once
#include<iostream>
#include<Windows.h>
#include<string.h>
#include<string>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include <stdlib.h>
#include<vector>

using namespace std;
typedef char str[31];
enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ESC, ENTER, Delete };

#define MAUCHON 244			// NỀN TRẮNG CHỮ ĐỎ NÂU
#define MAUKHONGCHON 243 // NỀN TRẮNG CHỮ XANNH ĐẬM
#define TenFile "ThuVienSach.txt"
#define ObjSort maSach

struct sach
{
	string maSach;
	string tenSach;
	string nhaXuatBan;
	string namXuatBan;
	string soTrang;
	string tacGia;
	string noiDung;
	string giaSach;
	string ghiChu;

	sach* pNext = NULL;
};
typedef sach SACH;

struct list
{
	SACH* pHead;
	SACH* pTail;
};
typedef list LIST;

int menu(str arrThaoTac[], int n, int vitriX, int vitriY);
TRANGTHAI key(int z);
void runMenu(int inDexMenu);
void gotoxy(int x, int y);// function
void textColor(int x);// function
void inDanhMuc(str danhMuc, int vitriX, int vitriY);// function
void xoaDanhMuc(str danhMuc, int vitriX, int vitriY);// function
int SaveAndCancel();// function
int themSach(SACH &s);// function
void xoaManHinh();// function
void InDanhSachSach(LIST l); // function
TRANGTHAI option(int z);
void InitList(LIST &l); // data
void addTail(LIST &l, SACH* s); // data
SACH* newSach(string maSach, string tenSach, string nhaXuatBan, string namXuatBan, string soTrang, string tacGia, string noiDung, string giaSach, string ghiChu);
void nhapTuFile(LIST &l);	// data
void inKhungDS(); // function
int demSach(LIST l); // function
void inKhungTheohang(int n); // function
void inFormDSS(int n);
void inTheoTrang(int trang, LIST l); // function
int ChangePage(int *pageNow, int pageEnd, LIST l); // function
void xoaTrangDSSach(); // function
SACH* SachThu(int x, LIST l); // data
void toMau1Dong(int* pageNow, int dong, LIST l, int color); // function
SACH* chonDong(int *pageNow, LIST l); // function
void thayDoiNoiDungSach(int *pageNow, int dong, SACH *p, LIST l); // function
string layThongTinSach(int stt, SACH *p); // data
void toMau1ThongTinSach(int dong, int stt, SACH *p, int color); //fuction
int chon1ThongTinSach(int dong, SACH *p); // function
void xoaSachTheoSTT(int stt, LIST &l); // data
void toMau1DongTheoSach(SACH* s, int dong, int color); // function
void Swap(SACH *s1, SACH *s2); // data
void SelectionSort(LIST l, int cas);
void BubbleSort(LIST l, int cas);
void InsertSort(LIST l, int cas);
int laySTTSach(LIST l, SACH* a);
bool SoSanhHon(SACH s1, SACH s2, int cas);
void quickSort(LIST l, SACH* left, SACH* right, int cas);
string chuoiCanTimKiem();
vector<SACH> timKienTuanTu(LIST l, string str, vector<int> &arrViTri, int cas);
int timChuoiCon(string str, SACH *p, int cas);
void inSachTimKiem(vector<SACH> arrSach, vector<int> arrViTri, string str, int cas);
void thongKe(LIST l, int cas);
int changePageThongKe(int *pageNow, int pageEnd, LIST l, vector<string> arrSach, vector<int> count, int cas);
void timKiemNhiPhan(LIST l, string str, SACH* left, SACH* right, int cas, vector <SACH> & vtrS);
bool soSanhBang(SACH s1, SACH s2, int cas);
void inSachTimKiemNhiPhan(vector<SACH> vtrS);