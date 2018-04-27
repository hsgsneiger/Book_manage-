#include"MyLib.h"
#include"Interface.h"

void gotoxy(int x, int y) { // di chuyển con trỏ đến vị trí x, y
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void textColor(int x) {  // Đổi màu chữ
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
// in ra ô chữ nhật là 1 mục của 1 menu , truyền vào tên mục, vị trí in ra màn hình
void inDanhMuc(str danhMuc, int vitriX, int vitriY) {
	gotoxy(vitriX, vitriY);
	cout << danhMuc;
	for (int i = 0; i < 20; i++)
	{
		gotoxy(vitriX + i - 1, vitriY - 1);
		printf("%c", 220);
		gotoxy(vitriX + i - 1, vitriY + 1);
		printf("%c", 220);
	}
	for (int i = 0; i < 2; i++)
	{
		gotoxy(vitriX - 1, vitriY + i);
		printf("%c", 219);
		gotoxy(vitriX + 18, vitriY + i);
		printf("%c", 219);
	}
}
// Xóa 1 mục của 1 menu , truyền vào tên mục, vị trí in ra màn hình (ngược lại hàm in)
void xoaDanhMuc(str danhMuc, int vitriX, int vitriY) {
	gotoxy(vitriX, vitriY);
	cout << "                   ";
	for (int i = 0; i < 20; i++)
	{
		gotoxy(vitriX + i - 1, vitriY - 1);
		printf(" ");
		gotoxy(vitriX + i - 1, vitriY + 1);
		printf(" ");
	}
	for (int i = 0; i < 2; i++)
	{
		gotoxy(vitriX - 1, vitriY + i);
		printf(" ");
		gotoxy(vitriX + 18, vitriY + i);
		printf(" ");
	}
}
// chạy khi chọn mục thêm sách, để in ra trường cho NSD nhập sách vào, trả về 1 nếu NSD lưu sách, 0 nếu NSD không lưu sách
int themSach(SACH &s) {
	{// in menu
		string title[] = { "     Ma Sach","    Ten Sach","Nha Xuat Ban" ,"Nam Xuat Ban" ,"    So Trang","     Tac Gia" ,"     Noi Dung","   Gia Thanh","     Ghi Chu" };
		for (int i = 11; i < 36; i += 3)
		{
			textColor(243);
			gotoxy(69, i);	cout << title[(i - 11) / 3]; // 11 14 17 20 23 26 29 32 35
			textColor(115);								 // 0   3  6  9 12 
			gotoxy(84, i); cout << "          ";
		}
		textColor(120);
		gotoxy(76, 39);
		cout << "SAVE";
		gotoxy(86, 39);
		cout << "CANCEL";
	}
	textColor(116);
	for (int i = 11; i < 36; i += 3) // lấy dữ liệu
	{
		gotoxy(84, i);
		switch (i)
		{
		case 11: // mã Sách
			getline(cin, s.maSach);
			break;
		case 14:// Tên sách
			getline(cin, s.tenSach);
			break;
		case 17://Nhà xuất bản
			getline(cin, s.nhaXuatBan);
			break;
		case 20:// Năm xuất bản
		{ // Bắt lỗi nhập sai định dạng năm
			bool ok = true;
			do {
				gotoxy(84, 20);
				getline(cin, s.namXuatBan);
				if (s.namXuatBan == "") {
					ok = false;
					continue;
				}
				int x = atoi(&s.namXuatBan.at(0));
				(0 < x && x <= 2019) ? (ok = true) : (ok = false);
				if (!ok) {
					gotoxy(84, 20); cout << "          "; textColor(243); cout << "                                                                                          ";
					gotoxy(84, 20); textColor(116);
				}
			} while (!ok);
		}
		break;
		case 23: // Số trang
		{ // Bắt lỗi nhập sai định dạng int

			bool ok = true;
			do {
				gotoxy(84, 23);
				getline(cin, s.soTrang);
				if (s.soTrang == "") {
					ok = false;
					continue;
				}
				int x = atoi(&s.soTrang.at(0));
				(0 < x && x <= 5000) ? (ok = true) : (ok = false);
				if (!ok) {
					gotoxy(84, 23); cout << "          "; textColor(243); cout << "                                                                                          ";
					gotoxy(84, 23); textColor(116);
				}
			} while (!ok);
		}
		break;
		case 26:// Tác giả
			getline(cin, s.tacGia);
			break;
		case 29:// Nội dung
			getline(cin, s.noiDung);
			break;
		case 32: // Giá thành
		{ // Bắt lỗi nhập sai định dạng giá sách
			bool ok = true;
			do {
				gotoxy(84, 32);
				getline(cin, s.giaSach);
				if (s.giaSach == "") {
					ok = false;
					continue;
				}
				int x = atoi(&s.giaSach.at(0));
				(0 < x && x <= 9999999) ? (ok = true) : (ok = false);
				if (!ok) {
					gotoxy(84, 32); cout << "          "; textColor(243); cout << "                                                                                          ";
					gotoxy(84, 32); textColor(116);
				}
			} while (!ok);

		}
		break;
		case 35: // Ghi chú
			getline(cin, s.ghiChu);
			break;
		}
	}

	switch (SaveAndCancel())
	{
	case -1:  // KHÔNG LƯU
		return 0;
		break;
	case 1: // LƯU SÁCH
		return 1;
		break;
	}
}
// chuyển ký tự nhập từ bàn phím sang kiểu TRANGTHAI(up down left right)
TRANGTHAI option(int z) {
	if (z == 224) {
		char c = _getch();
		if (c == 75)	return LEFT;
		if (c == 77)	return RIGHT;
		if (c == 72)	return UP;
		if (c == 80)	return DOWN;
	}
	if (z == 13)
		return ENTER;
	if (z == 27)
		return ESC;
	if (z == 8)
		return Delete;
}
// Tạo 2 nút save, cancel ở mục thêm sách. trả về 1 nếu save, 0 nếu cacel
int SaveAndCancel() {
	int ok = 1;  // ok = 1: save, ok = 0: cancel
	while (true) {
		if (ok != -1) {
			textColor(132);		gotoxy(76, 39);
			cout << "SAVE";

			textColor(120);		gotoxy(86, 39);
			cout << "CANCEL";
		}
		else {
			textColor(120);		gotoxy(76, 39);
			cout << "SAVE";

			textColor(132);		gotoxy(86, 39);
			cout << "CANCEL";
		}
		int z = _getch();  // lưu phím (mũi tên) nhập vào từ bàn phím
		TRANGTHAI trangthai = option(z);
		switch (trangthai)
		{
		case LEFT:
			ok = ok * -1;
			break;
		case RIGHT:
			ok = ok * -1;
			break;
		case ENTER:
			return ok;
			break;
		}
	}
}

// xóa màn hình (trừ phần head)
void xoaManHinh() {
	textColor(243);
	system("cls");
	head();
}
// In danh sách sách ra màn hình
void InDanhSachSach(LIST l) {		 // In danh sách ra màn hình
	int soSach = demSach(l);
	xoaManHinh();
	inKhungDS();
	int *pageNow;
	int x = 1;
	pageNow = &x;
	int pageEnd = soSach / 17 + 1;
	gotoxy(4, 13);
	inFormDSS(17);
	inTheoTrang(1, l);

	while (true)
		inTheoTrang(ChangePage(pageNow, pageEnd, l), l);

	system("pause>nul");
}

void inFormDSS(int n) {
	gotoxy(4, 13);
	for (int i = 0; i < 199; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 218);
			break;
		case 10: case 53: case 79: case 87: case 98: case 128: case 171: case 186:
			printf("%c", 194);
			break;
		case 198:
			printf("%c", 191);
			break;
		default:
			printf("%c", 196);
			break;
		}
	}
	gotoxy(4, 14);
	printf("%c Ma Sach %c                 Ten Sach                 %c           NXB           %c  Nam  %c So Trang %c           Tac Gia           %c                 Noi Dung                 %c   Gia Sach   %c  Ghi Chu  %c", 179, 179, 179, 179, 179, 179, 179, 179, 179, 179);
	for (int i = 1; i <= n; i++)
		inKhungTheohang(i);
}

// trả về số lượng sách đang có
int demSach(LIST l) {
	int n = 0;
	for (SACH* p = l.pHead; p; p = p->pNext)
		n++;
	return n;
}
// in khung xung quanh 1 sách ở phần in danh sách sách
void inKhungTheohang(int n) {
	if (n == 0) return;
	gotoxy(4, 15 + (2 * (n - 1)));
	for (int i = 0; i < 199; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 195);
			break;
		case 10: case 53: case 79: case 87: case 98: case 128: case 171: case 186:
			printf("%c", 197);
			break;
		case 198:
			printf("%c", 180);
			break;
		default:
			printf("%c", 196);
			break;
		}
	}

	gotoxy(4, 16 + (2 * (n - 1)));
	for (int i = 0; i < 199; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 179);
			break;
		case 10: case 53: case 79: case 87: case 98: case 128: case 171: case 186:
			printf("%c", 179);
			break;
		case 198:
			printf("%c", 179);
			break;
		default:
			printf(" ");
			break;
		}
	}

	gotoxy(4, 17 + (2 * (n - 1)));
	for (int i = 0; i < 199; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 192);
			break;
		case 10: case 53: case 79: case 87: case 98: case 128: case 171: case 186:
			printf("%c", 193);
			break;
		case 198:
			printf("%c", 217);
			break;
		default:
			printf("%c", 196);
			break;
		}
	}
}
// In thông tin sách theo trang hiện tại
void inTheoTrang(int trang, LIST l) {
	int stt = 1;
	int i = 1;
	textColor(243);
	for (SACH* p = l.pHead; p; p = p->pNext)
	{
		if (stt >= (trang - 1) * 17 + 1 && stt <= trang * 17) {
			gotoxy(4, 16 + (2 * (i - 1)));
			cout << (char)179 << setw(9) << left << p->maSach << (char)179 << setw(42) << left << p->tenSach << (char)179 << setw(25) << left << p->nhaXuatBan << (char)179 << setw(7) << left << p->namXuatBan << (char)179 << setw(10) << left << p->soTrang << (char)179 << setw(29) << left << p->tacGia << (char)179 << setw(42) << left << p->noiDung << (char)179 << setw(14) << left << p->giaSach << (char)179 << setw(11) << left << p->ghiChu << (char)179 << endl;
			i++;
		}
		stt++;
	}
}
// Xử lý chuyển qua lại các trang
int ChangePage(int *pageNow, int pageEnd, LIST l) { // tạo << Page 1 >>

	while (true) {
		textColor(248);		gotoxy(100, 51);
		cout << (char)174;

		textColor(248);		gotoxy(109, 51);
		cout << (char)175;
		textColor(240);		gotoxy(102, 51);
		cout << "Page " << *pageNow;
		int z = _getch();  // lưu phím (mũi tên) nhập vào từ bàn phím
		TRANGTHAI trangthai = option(z);
		switch (trangthai)
		{
		case LEFT:
			textColor(252);		gotoxy(100, 51);
			cout << (char)174;
			if (*pageNow == 1) *pageNow = pageEnd;
			else *pageNow -= 1;
			textColor(240);		gotoxy(102, 51);
			cout << "Page " << *pageNow;
			xoaTrangDSSach();
			return *pageNow;
			break;
		case RIGHT:
			textColor(252);		gotoxy(109, 51);
			cout << (char)175;
			if (*pageNow == pageEnd) *pageNow = 1;
			else *pageNow += 1;
			textColor(240);		gotoxy(102, 51);
			cout << "Page " << *pageNow;
			xoaTrangDSSach();
			return *pageNow;
			break;
		case ESC:
			xoaManHinh();
			runMenu(0);
			break;
		case ENTER:
			if (chonDong(pageNow, l) == NULL)
				return *pageNow;

			break;
		}
	}
}
// xử lý việc chọn dòng để sửa, xóa
SACH*  chonDong(int *pageNow, LIST l) {
	int vitri = 1;
	while (true) {
		switch (vitri)
		{
		case 1:
			toMau1Dong(pageNow, 17, l, 243);
			toMau1Dong(pageNow, 2, l, 243);
			break;
		case 17:
			toMau1Dong(pageNow, 16, l, 243);
			toMau1Dong(pageNow, 1, l, 243);
			break;
		default:
			toMau1Dong(pageNow, vitri + 1, l, 243);
			toMau1Dong(pageNow, vitri - 1, l, 243);
			break;
		}
		toMau1Dong(pageNow, vitri, l, 124);
		int z = _getch();  // lưu phím (mũi tên) nhập vào từ bàn phím
		TRANGTHAI trangthai = option(z);
		switch (trangthai)
		{
		case UP:
			if (vitri == 1)
				vitri = 18;
			vitri--;
			break;
		case DOWN:
			if (vitri == 17)
				vitri = 0;
			vitri++;
			break;
		case ESC:
			//	xoaManHinh();
			return NULL;
			break;
		case ENTER:
			thayDoiNoiDungSach(pageNow, vitri, SachThu((*pageNow - 1) * 17 + vitri, l), l);
			break;
		case Delete:

			switch (MessageBox(NULL, "Ban co chac muon xoa cuon Sach nay?", "Xac Nhan", MB_YESNO | MB_ICONQUESTION))
			{
			case IDYES://
				MessageBox(NULL, "Xoa Thanh Cong!", "", MB_OK | MB_ICONINFORMATION);
				xoaSachTheoSTT((*pageNow - 1) * 17 + vitri, l);
				inTheoTrang(*pageNow, l);
				break;
			case IDNO:
				break;
			}
			break;
		}
	}
}
// xóa 1 trang DSsách
void xoaTrangDSSach() {
	textColor(243);
	for (int i = 1; i <= 17; i++)
	{
		gotoxy(4, 16 + (2 * (i - 1)));
		cout << (char)179 << setw(9) << left << "         " << (char)179 << setw(42) << left << "                                        " << (char)179 << setw(25) << left << "                         " << (char)179 << setw(7) << left << "       " << (char)179 << setw(10) << left << "          " << (char)179 << setw(29) << left << "                            " << (char)179 << setw(42) << left << "                                          " << (char)179 << setw(14) << left << "              " << (char)179 << setw(11) << left << "           " << (char)179 << endl;
	}
}
// Tô màu dòng thông tin trang sách
void toMau1Dong(int* pageNow, int dong, LIST l, int color) {
	textColor(color);
	SACH *s = SachThu((*pageNow - 1) * 17 + dong, l);
	if (s == NULL) return;
	gotoxy(4, 16 + (2 * (dong - 1))); // 9-42-25-7-10-29-42-14-11
	cout << (char)179 << setw(9) << left << s->maSach << (char)179 << setw(42) << left << s->tenSach << (char)179 << setw(25) << left << s->nhaXuatBan << (char)179 << setw(7) << left << s->namXuatBan << (char)179 << setw(10) << left << s->soTrang << (char)179 << setw(29) << left << s->tacGia << (char)179 << setw(42) << left << s->noiDung << (char)179 << setw(14) << left << s->giaSach << (char)179 << setw(11) << left << s->ghiChu << (char)179 << endl;
}
// 4 hàm dưới xử lý chọn sách, chọn thông tin sách để sửa & xóa
void thayDoiNoiDungSach(int *pageNow, int dong, SACH *p, LIST l) {
	int stt = 1;
	toMau1Dong(pageNow, dong, l, 243);
	chon1ThongTinSach(dong, p);
}
void toMau1ThongTinSach(int dong, int stt, SACH *p, int color) {
	int vitri;
	textColor(color);
	switch (stt)
	{
	case 1:
		gotoxy(5, 16 + (dong - 1) * 2);
		cout << layThongTinSach(stt, p);
		gotoxy(5, 16 + (dong - 1) * 2);
		break;
	case 2:
		gotoxy(15, 16 + (dong - 1) * 2);
		cout << layThongTinSach(stt, p);
		gotoxy(15, 16 + (dong - 1) * 2);
		break;
	case 3:
		gotoxy(58, 16 + (dong - 1) * 2);
		cout << layThongTinSach(stt, p);
		gotoxy(58, 16 + (dong - 1) * 2);
		break;
	case 4:
		gotoxy(84, 16 + (dong - 1) * 2);
		cout << layThongTinSach(stt, p);
		gotoxy(84, 16 + (dong - 1) * 2);
		break;
	case 5: gotoxy(92, 16 + (dong - 1) * 2);
		cout << layThongTinSach(stt, p);
		gotoxy(92, 16 + (dong - 1) * 2);
		break;
	case 6:
		gotoxy(103, 16 + (dong - 1) * 2);
		cout << layThongTinSach(stt, p);
		gotoxy(103, 16 + (dong - 1) * 2);
		break;
	case 7:
		gotoxy(133, 16 + (dong - 1) * 2);
		cout << layThongTinSach(stt, p);
		gotoxy(133, 16 + (dong - 1) * 2);
		break;
	case 8:
		gotoxy(176, 16 + (dong - 1) * 2);
		cout << layThongTinSach(stt, p);
		gotoxy(176, 16 + (dong - 1) * 2);
		break;
	case 9:
		gotoxy(191, 16 + (dong - 1) * 2);
		cout << layThongTinSach(stt, p);
		gotoxy(191, 16 + (dong - 1) * 2);
		break;
	}


}
int chon1ThongTinSach(int dong, SACH *p) {
	int stt = 1;
	while (true) {
		switch (stt)
		{
		case 1:
			toMau1ThongTinSach(dong, 9, p, 243);
			toMau1ThongTinSach(dong, 2, p, 243);
			break;
		case 9:
			toMau1ThongTinSach(dong, 1, p, 243);
			toMau1ThongTinSach(dong, 8, p, 243);
			break;
		default:
			toMau1ThongTinSach(dong, stt + 1, p, 243);
			toMau1ThongTinSach(dong, stt - 1, p, 243);
			break;
		}
		toMau1ThongTinSach(dong, stt, p, 140);
		int z = _getch();  // lưu phím (mũi tên) nhập vào từ bàn phím
		TRANGTHAI trangthai = option(z);
		switch (trangthai)
		{
		case LEFT:
			if (stt == 1)
				stt = 10;
			stt--;
			break;
		case RIGHT:
			if (stt == 9)
				stt = 0;
			stt++;
			break;
		case ESC:
			//	xoaManHinh();
			return 0;
			break;
		case ENTER:
			string s;
			toMau1ThongTinSach(dong, stt, p, 255);
			textColor(252);
			getline(cin, s);
			switch (stt)
			{
			case 1: p->maSach = s;
				break;
			case 2: p->tenSach = s;
				break;
			case 3:p->nhaXuatBan = s;
				break;
			case 4:p->namXuatBan = s;
				break;
			case 5:p->soTrang = s;
				break;
			case 6:p->tacGia = s;
				break;
			case 7:p->noiDung = s;
				break;
			case 8:p->giaSach = s;
				break;
			case 9:p->ghiChu = s;
				break;
			}
			break;
		}
	}
}
void toMau1DongTheoSach(SACH* s, int dong, int color) {
	textColor(color);
	gotoxy(4, 16 + (2 * (dong - 1))); // 9-42-25-7-10-29-42-14-11
	cout << (char)179 << setw(9) << left << s->maSach << (char)179 << setw(42) << left << s->tenSach << (char)179 << setw(25) << left << s->nhaXuatBan << (char)179 << setw(7) << left << s->namXuatBan << (char)179 << setw(10) << left << s->soTrang << (char)179 << setw(29) << left << s->tacGia << (char)179 << setw(42) << left << s->noiDung << (char)179 << setw(14) << left << s->giaSach << (char)179 << setw(11) << left << s->ghiChu << (char)179 << endl;
}

void inSachTimKiemNhiPhan(vector<SACH> vtrS) {
	textColor(243);
	gotoxy(110, 16);
	cout << setw(15) << right << "Ma Sach:   " << vtrS[0].maSach << endl;
	gotoxy(110, 17);
	cout << setw(15) << right << "Ten Sach:   " << vtrS[0].tenSach << endl;
	gotoxy(110, 18);
	cout << setw(15) << right << "NXB:   " << vtrS[0].nhaXuatBan << endl;
	gotoxy(110, 19);
	cout << setw(15) << right << "Nam XB:   " << vtrS[0].namXuatBan << endl;
	gotoxy(110, 20);
	cout << setw(15) << right << "Tac Gia:   " << vtrS[0].tacGia << endl;
	gotoxy(110, 21);
	cout << setw(15) << right << "So  Trang:   " << vtrS[0].soTrang << endl;
	gotoxy(110, 22);
	cout << setw(15) << right << "Noi Dung:   " << vtrS[0].noiDung << endl;
	gotoxy(110, 23);
	cout << setw(15) << right << "Gia Sach:   " << vtrS[0].giaSach << endl;
	gotoxy(110, 24);
	cout << setw(15) << right << "Ghi Chu:   " << vtrS[0].ghiChu << endl;
}