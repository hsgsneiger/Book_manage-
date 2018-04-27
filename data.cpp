#include"MyLib.h"
void InitList(LIST &l) { // Khởi tạo danh sách liên kết
	l.pHead = l.pTail = NULL;
}
// Hàm tạo sách
SACH* newSach(string maSach, string tenSach, string nhaXuatBan, string namXuatBan, string soTrang, string tacGia, string noiDung, string giaSach, string ghiChu) {
	SACH *pSACH = new SACH;
	if (!pSACH)
	{
		return NULL;
	}
	pSACH->maSach = maSach.substr(0, 9);				// Lấy dữ liệu của SACH nhập vào vào dữ liệu SACH trong danh sách liên kết
	pSACH->tenSach = tenSach.substr(0, 42);			// đồng thời giới hạn ký tự
	pSACH->nhaXuatBan = nhaXuatBan.substr(0, 25);
	pSACH->namXuatBan = namXuatBan.substr(0, 7);
	pSACH->tacGia = tacGia.substr(0, 29);
	pSACH->noiDung = noiDung.substr(0, 42);
	pSACH->giaSach = giaSach.substr(0, 14);
	pSACH->ghiChu = ghiChu.substr(0, 11);
	pSACH->soTrang = soTrang.substr(0, 10);
	pSACH->pNext = NULL;
	return pSACH;
}

void addTail(LIST &l, SACH* s) {					// Thêm Node vào cuối danh sách
	if (l.pHead == NULL)
		l.pHead = l.pTail = s;
	else {
		l.pTail->pNext = s;
		l.pTail = s;
		//	s->pNext = NULL;
	}
}
//Hàm nhập dữ liệu từ file, gọi khi ctrinh chạy
void nhapTuFile(LIST &l) {
	ifstream file;
	file.open(TenFile);
	while (!file.eof())
	{
		{
			SACH s1;
			getline(file, s1.maSach, '\n');
			if (s1.maSach == "") break;
			getline(file, s1.tenSach, '\n');
			getline(file, s1.nhaXuatBan, '\n');
			getline(file, s1.namXuatBan, '\n');
			getline(file, s1.soTrang, '\n');
			getline(file, s1.tacGia, '\n');
			getline(file, s1.noiDung, '\n');
			getline(file, s1.giaSach, '\n');
			getline(file, s1.ghiChu, '\n');
			string s;
			getline(file, s);
			addTail(l, newSach(s1.maSach, s1.tenSach, s1.nhaXuatBan, s1.namXuatBan, s1.soTrang, s1.tacGia, s1.noiDung, s1.giaSach, s1.ghiChu));
		}
	}
	file.close();
}
// Truyền vào số thứ tự sách, trả về con trỏ trỏ tới sách đó trong dslk
SACH* SachThu(int x, LIST l) {
	int i = 1;
	for (SACH* p = l.pHead; p; p = p->pNext)
	{
		if (i == x)
			return p;
		i++;
	}
	return NULL;
}
// truyền vào từ 1 đến 9 ứng với trả về dữ liệu của sách tương ứng
string layThongTinSach(int stt, SACH *p) {
	switch (stt)
	{
	case 1: return p->maSach; break;
	case 2: return p->tenSach; break;
	case 3: return p->nhaXuatBan; break;
	case 4: return p->namXuatBan; break;
	case 5: return p->soTrang; break;
	case 6: return p->tacGia; break;
	case 7: return p->noiDung; break;
	case 8: return p->giaSach; break;
	case 9: return p->ghiChu; break;
	}
}
// Xóa sách trong dslk theo số thứ tự
void xoaSachTheoSTT(int stt, LIST &l) {
	if (stt == 1) {
		SACH *s = l.pHead;
		l.pHead = s->pNext;
	}
	else if (stt == demSach(l)) {
		l.pTail = SachThu(stt - 1, l);
		l.pTail->pNext = NULL;
	}
	else {
		SachThu(stt - 1, l)->pNext = SachThu(stt + 1, l);
		InDanhSachSach(l);
		//		inTheoTrang(demSach(l) / 17 + 1, l); // xóa luôn trên trang ko refesh lại
	}
}

// truyền vào danh sách sách, case để chọn đối tượng so sánh (hàm SoSanh)
void SelectionSort(LIST l, int cas) {
	int end = demSach(l) - 1;
	for (int i = 0; i <= end; i++)
	{
		SACH *temp = SachThu(i + 1, l);
		int index = i + 1;
		for (int j = i; j <= end; j++)
		{
			if (SoSanhHon(*temp, *SachThu(j + 1, l), cas)) {
				//if (*temp > *SachThu(j + 1, l)) {
				temp = SachThu(j + 1, l);
				index = j + 1;
			}
			// tìm gtrij min
		}
		// swap min và i
		if (temp != SachThu(i + 1, l))
			Swap(SachThu(i + 1, l), SachThu(index, l));
	}
}

void BubbleSort(LIST l, int cas) {
	int end = demSach(l) - 1;
	for (int i = 0; i <= end; i++)
	{
		int index = i + 1;
		for (int j = 0; j < end; j++)
		{
			if (SoSanhHon(*SachThu(j + 1, l), *SachThu(j + 2, l), cas)) {
				Swap(SachThu(j + 1, l), SachThu(j + 2, l));
			}
			// tìm gtrij min
		}
	}
}

// Xắp sếp chèn
void InsertSort(LIST l, int cas) {
	int end = demSach(l) - 1;
	for (int i = 0; i <= end; i++)
	{
		SACH *temp = SachThu(i + 1, l);
		int index = i + 1;
		for (int j = i; j <= end; j++)
		{
			if (SoSanhHon(*temp, *SachThu(j + 1, l), cas)) {
				//if (*temp > *SachThu(j + 1, l)) {
				temp = SachThu(j + 1, l);
				index = j + 1;
			}
		}
		if (temp != SachThu(i + 1, l))
			Swap(SachThu(i + 1, l), SachThu(index, l));
	}
}

//Tham số: danh sách (full), sách bên trái, sách bên phải, đối tượng sắp xếp 
void quickSort(LIST l, SACH* left, SACH* right, int cas)
{
	int iLeft = laySTTSach(l, left);
	int iRight = laySTTSach(l, right);
	SACH* key = SachThu(((iLeft + iRight) / 2), l); // Lấy key làm sách ở giữa
	int i = iLeft, j = iRight;
	while (i <= j)
	{
		while (SoSanhHon(*key, *SachThu(i, l), cas)) i++;
		while (SoSanhHon(*SachThu(j, l), *key, cas)) j--;
		if (i <= j) {
			if (i < j)
				Swap(SachThu(i, l), SachThu(j, l));
			i++;
			j--;
		}
	}
	if (iLeft < j) quickSort(l, SachThu(iLeft, l), SachThu(j, l), cas);
	if (i < iRight) quickSort(l, SachThu(i, l), SachThu(iRight, l), cas);
}

void Swap(SACH *s1, SACH *s2) {
	SACH temp = *s1;
	*s1 = *s2;
	*s2 = temp;
	s2->pNext = s1->pNext;
	s1->pNext = temp.pNext;
}

// truyền vào thông tin 2 sách, cas, trả về đúng nếu s1 > s2
bool SoSanhHon(SACH s1, SACH s2, int cas) {
	bool ok;
	switch (cas)
	{
	case 0:
		(s1.maSach.compare(s2.maSach) > 0) ? ok = true : ok = false;
		break;
	case 1:
		(s1.tenSach.compare(s2.tenSach) > 0) ? ok = true : ok = false;
		break;
	case 2:
		(s1.nhaXuatBan.compare(s2.nhaXuatBan) > 0) ? ok = true : ok = false;
		break;
	case 3:
		(s1.namXuatBan.compare(s2.namXuatBan) > 0) ? ok = true : ok = false;
		break;
	case 4:
		(s1.tacGia.compare(s2.tacGia) > 0) ? ok = true : ok = false;
		break;
	case 5:
		(s1.giaSach.compare(s2.giaSach) > 0) ? ok = true : ok = false;
		break;
	}
	return ok;
}

int laySTTSach(LIST l, SACH* a) {
	int i = 0;
	for (SACH*p = l.pHead; p; p = p->pNext) {
		if (a->maSach == p->maSach) return i + 1;
		i++;
	}
}

// in và trả về chuỗi cần tìm kiếm
string chuoiCanTimKiem() {
	string str;
	gotoxy(70, 13);
	cout << "Nhap vao tu khoa can tim kiem: ";
	textColor(112); cout << "                     ";
	gotoxy(101, 13);
	textColor(124);
	getline(cin, str);
	return str;
}

// trả về 1 vector Sách tìm được, mỗi sách có vị trí xuất hiện của chuỗi con, được gán vào vecto arrViTri
vector<SACH> timKienTuanTu(LIST l, string str, vector<int> &arrViTri, int cas) {
	vector<SACH> arrSach;
	for (SACH* p = l.pHead; p; p = p->pNext)
	{
		int vitri = timChuoiCon(str, p, cas);
		if (vitri != -1)
		{
			arrSach.push_back(*p);
			arrViTri.push_back(vitri);
		}
	}
	return arrSach;
}

// truyền vào str, 1 con trỏ trỏ tới sách, trả về vị trí của chuỗi trong str, -1 nếu ko có
int timChuoiCon(string str, SACH *p, int cas) {
	switch (cas)
	{
	case 0: return p->maSach.find(str);
	case 1: return p->tenSach.find(str);
	case 2: return p->nhaXuatBan.find(str);
	case 3: return p->namXuatBan.find(str);
	case 4: return p->tacGia.find(str);
	case 5: return p->noiDung.find(str);
	case 6: return p->ghiChu.find(str);
	}
}

// in ra, tô màu chỗ cần tìm kiếm
void inSachTimKiem(vector<SACH> arrSach, vector<int> arrViTri, string str, int cas) {
	if (arrSach.size() == 0)
	{
		MessageBox(NULL, "Khong tim thay Sach chua thong tin can tim!", "Thong bao", MB_OK | MB_ICONINFORMATION);
		return;
	}
	textColor(243);
	xoaManHinh();
	inKhungDS();
	inKhungTheohang(arrSach.size());
	inFormDSS(arrSach.size());
	int n = 1;
	for (int i = 0; i < arrSach.size(); i++)
	{
		gotoxy(4, 16 + (2 * (n - 1)));
		cout << (char)179 << setw(9) << left << arrSach[i].maSach << (char)179 << setw(42) << left << arrSach[i].tenSach << (char)179 << setw(25) << left << arrSach[i].nhaXuatBan << (char)179 << setw(7) << left << arrSach[i].namXuatBan << (char)179 << setw(10) << left << arrSach[i].soTrang << (char)179 << setw(29) << left << arrSach[i].tacGia << (char)179 << setw(42) << left << arrSach[i].noiDung << (char)179 << setw(14) << left << arrSach[i].giaSach << (char)179 << setw(11) << left << arrSach[i].ghiChu << (char)179 << endl;
		n++;
		switch (cas) //// 9-42-25-7-10-29-42-14-11
		{
		case 0:	// max sach
			gotoxy((5 + arrViTri[i]), 16 + (2 * (n - 2)));
			textColor(252);
			cout << str;
			textColor(243);
			break;
		case 1:
			gotoxy((15 + arrViTri[i]), 16 + (2 * (n - 2)));
			textColor(252);
			cout << str;
			textColor(243);
			break;
		case 2:
			gotoxy((58 + arrViTri[i]), 16 + (2 * (n - 2)));
			textColor(252);
			cout << str;
			textColor(243);
			break;
		case 3:
			gotoxy((84 + arrViTri[i]), 16 + (2 * (n - 2)));
			textColor(252);
			cout << str;
			textColor(243);
			break;
		case 4:
			gotoxy((103 + arrViTri[i]), 16 + (2 * (n - 2)));
			textColor(252);
			cout << str;
			textColor(243);
			break;
		case 5:
			gotoxy((133 + arrViTri[i]), 16 + (2 * (n - 2)));
			textColor(252);
			cout << str;
			textColor(243);
			break;
		case 6:
			gotoxy((191 + arrViTri[i]), 16 + (2 * (n - 2)));
			textColor(252);
			cout << str;
			textColor(243);
			break;
		}
	}
	while (true)
	{
		int z = _getch();  // lưu phím (mũi tên) nhập vào từ bàn phím
		TRANGTHAI trangthai = option(z);
		switch (trangthai)
		{
		case ESC:
			return;
		}
	}
}

void timKiemNhiPhan(LIST l, string str, SACH* left, SACH* right, int cas, vector <SACH> &vtrS) {
	SACH s1;
	s1.maSach = s1.tenSach = s1.nhaXuatBan = s1.namXuatBan = s1.tacGia = s1.noiDung = s1.ghiChu = s1.giaSach = s1.soTrang = str;
	int iLeft = laySTTSach(l, left);
	int iRight = laySTTSach(l, right);
	int mid = (iLeft + iRight) / 2;
	SACH mid2 = *SachThu(mid, l);
	if (soSanhBang(s1, mid2, cas)) {
		vtrS.push_back(mid2);
		return ;
	}
	else if (SoSanhHon(s1, mid2, cas)) {
		timKiemNhiPhan(l, str, SachThu(mid, l), right, cas,vtrS );
	}
	else { 
		timKiemNhiPhan(l, str, left, SachThu(mid, l), cas, vtrS);
	}

}

// truyền vào thông tin 2 sách, cas. trả về true nếu s1 = s2
bool soSanhBang(SACH s1, SACH s2, int cas) {
	bool ok = true;
	switch (cas)
	{
	case 0:
		if (s1.maSach != s2.maSach)
			ok = false;
	break;
	case 1:
		if (s1.tenSach != s2.tenSach)
			ok = false;
		break;
	case 2:
		if (s1.nhaXuatBan != s2.nhaXuatBan)
			ok = false;
		break;
	case 3:
		if (s1.namXuatBan != s2.namXuatBan)
			ok = false;
		break;
	case 4:
		if (s1.tacGia != s2.tacGia)
			ok = false;
		break;
	case 5:
		if (s1.giaSach != s2.giaSach)
			ok = false;
		break;
	case 6:
		if (s1.ghiChu != s2.ghiChu)
			ok = false;
		break;
	}
	return ok;
}

void thongKe(LIST l, int cas) {
	vector<string> arrSach;
	vector<int> count/* = { 0 }*/;
	bool ok = true;
	for (SACH* p = l.pHead; p; p = p->pNext)
	{
		ok = true;
		for (int i = 0; i < arrSach.size(); i++)
		{
			switch (cas)
			{
			case 0:  // tác giả
				if (p->tacGia == arrSach[i]) {
					count[i]++;
					ok = false;
				}
				break;
			case 1: //NXB
				if (p->nhaXuatBan == arrSach[i]) {
					count[i]++;
					ok = false;
				}
				break;
			case 2: // Nam
				if (p->namXuatBan == arrSach[i]) {
					count[i]++;
					ok = false;
				}
				break;
			}
		}
		if (ok)
		{
			switch (cas)
			{
			case 0:
				arrSach.push_back(p->tacGia);
				count.push_back(1);
				break;
			case 1:
				arrSach.push_back(p->nhaXuatBan);
				count.push_back(1);
				break;
			case 2:
				arrSach.push_back(p->namXuatBan);
				count.push_back(1);
				break;
			}
		}

	}
	int *pageNow;  int x = 1;	pageNow = &x;
	int pageEnd = count.size() / 17 + 1;
	while (true)
	{
		for (int i = 0; i < 20; i++)
		{
			gotoxy(70, 12 + i * 2);
			cout << "                                                                                                                                      ";
		}
		switch (changePageThongKe(pageNow, pageEnd, l, arrSach, count, cas))
		{
		case -1:
			textColor(243);
			for (int i = 0; i < 20; i++)
			{
				gotoxy(70, 12 + i * 2);
				cout << "                                                                                                                                   ";
			}
			runMenu(4);
		default:
			break;
		}
	}
}

// Xử lý chuyển qua lại các trang ở phần thống kê
int changePageThongKe(int *pageNow, int pageEnd, LIST l, vector<string> arrSach, vector<int> count, int cas) { // tạo << Page 1 >>
	int soSach;
	if (*pageNow == pageEnd)
		soSach = count.size() % 17;
	else soSach = 17;
	while (true) {
		textColor(243);
		gotoxy(70, 12);
		switch (cas)
		{
		case 0:
			cout << "                       Tac Gia" << "  " << (char)179;
			break;
		case 1:
			cout << "                  Nha Xuat Ban" << "  " << (char)179;
			break;
		case 2:
			cout << "                  Nam Xuat Ban" << "  " << (char)179;
			break;
		}
		for (int i = 0; i < soSach; i++)
		{
			gotoxy(70, 14 + i * 2);
			cout << setw(30) << right << arrSach[i + (*pageNow - 1) * 17]  /*<< setw(6) << left << count[i + (*pageNow - 1) * 34] << (char)179*/;
			cout << "  ";
		}
		for (int i = 0; i < soSach; i++)
		{
			gotoxy(103, 14 + i * 2);
			textColor(rand() % 14 + 240);
			for (int j = 0; j < count[i + (*pageNow - 1) * 17]; j++)
			{

				cout << (char)177 << (char)177 << (char)177;
				Sleep(20);
			}
			cout << " " << setprecision(3) << (count[i + (*pageNow - 1) * 17])/(float)demSach(l)*100 << " " <<(char)37;
		}
		textColor(248);		gotoxy(135, 51);  //next page
		cout << (char)174;
		textColor(248);		gotoxy(144, 51);
		cout << (char)175;
		textColor(240);		gotoxy(137, 51);
		cout << "Page " << *pageNow;
		int z = _getch();  // lưu phím (mũi tên) nhập vào từ bàn phím
		TRANGTHAI trangthai = option(z);
		switch (trangthai)
		{
		case LEFT:
			textColor(252);		gotoxy(135, 51);
			cout << (char)174;
			if (*pageNow == 1) *pageNow = pageEnd;
			else *pageNow -= 1;
			textColor(240);		gotoxy(137, 51);
			cout << "Page " << *pageNow;
			return *pageNow;
			break;
		case RIGHT:
			textColor(252);		gotoxy(144, 51);
			cout << (char)175;
			if (*pageNow == pageEnd) *pageNow = 1;
			else *pageNow += 1;
			textColor(240);		gotoxy(137, 51);
			cout << "Page " << *pageNow;
			return *pageNow;
			break;
		case ESC:
			return -1;
			break;
		}
	}
}