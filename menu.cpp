#include"Interface.h"
#include"MyLib.h"

int vitricu = -1;
// Hàm menu truyền vào 1 chuỗi chứa tên các mục , số các mục, vị trí trên màn hình, trả về vị trí hiện tại (nếu nhấn chọn) hoặc -1 nếu nhấn thoát
int menu(str arrThaoTac[], int n, int vitriX,int vitriY) {
	int temp = 0; // lưu vị trí đang chọn để tô màu
	int *mau = new int[n];
	for (int i = 0; i < n; i++)
	{
		mau[i] = MAUKHONGCHON;
		mau[0] = MAUCHON;
	}
	while (true)
	{
		for (int i = 0; i < n; i++)
		{
			textColor(mau[i]);
			inDanhMuc(arrThaoTac[i], vitriX, vitriY + i * 6);
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);

		switch (trangthai)
		{
		case UP:
			if (temp == 0) temp = n;
			temp--;
			break;
		case DOWN:
			if (temp == n - 1) temp = -1;
			temp++;
			break;
		case RIGHT:
			vitricu = temp;
			return temp;
			break;
		case LEFT:
			return -1;
			break;
		case ESC:
			return -1;
			break;
		}
		for (int i = 0; i < n; i++)
		{
			mau[i] = MAUKHONGCHON;
			mau[temp] = MAUCHON;
		}
	}
}

TRANGTHAI key(int z) {
	if (z == 224) {
		char c = _getch();
		if (c == 72)
			return UP;
		if (c == 80)
			return DOWN;
		if (c == 75)
			return LEFT;
		if (c == 77)
			return RIGHT;
	}
	if (z == 27)
		return ESC;
}

