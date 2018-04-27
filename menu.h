#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include<conio.h>




using namespace std;
typedef char str[31];
enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ESC, ENTER };

#define MAUCHON 244			// NỀN TRẮNG CHỮ ĐỎ NÂU
#define MAUKHONGCHON 243 // NỀN TRẮNG CHỮ XANNH ĐẬM


int menu(str arrThaoTac[], int n, int vitriX, int vitriY);
//void runMenu(int inDexMenu);
TRANGTHAI key(int z);
