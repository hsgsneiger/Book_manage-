#include"Interface.h"
#include"MyLib.h"

str thaotac[6] = { "  Cap Nhat Sach   ", "   In Danh Sach", "     Sap xep","    Tim Kiem", "    Thong ke", "      Thoat\n" };
str thaoTacM1[3] = { "       Nhap", "       Sua", "       Xoa" };
str thaoTacM3[4] = { "  Selection sort", "   Insert sort" , "    Buber sort" , "    Quick sort" };
str sortField[6] = { "      Ma Sach " , "      Ten Sach" , "       NXB" , "   Nam Xuat ban" , "     Tac Gia" , "        Gia" };
str thaoTacM4[2] = { " Tim kiem Tuan Tu" , " Tim Kiem Nhi Phan" };
str thaoTacM5[3] = { "     Tac Gia", "   Nha Xuat Ban", "   Nam Xuat Ban" };
str thaoTacM2[2] = { "  In ra man hinh ", "    In ra file" };
str searchField[7] = { "      Ma Sach " , "      Ten Sach" , "       NXB" , "   Nam Xuat ban" , "     Tac Gia" , "     Noi Dung" ,"      Ghi Chu" };
LIST DANHSACH;

void main() {
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);  // hàm phóng to màn hình
	wellcome();							    // Hàm in ra intro 
	system("cls");							// Xóa màn hình intro
	system("color f3");						// Đổi màu console nền trắng, chữ xanh
	InitList(DANHSACH);						// khởi tạo danh sách
	int inDexMenu = 0;
	//	head();									
	nhapTuFile(DANHSACH);					// Nhập data từ file
	runMenu(0);								// chạy chương menu chính
	system("pause>nul");
}

// hàm chạy menu, truyền vào tham số ứng với từng menu: 0:M0, 1:M1, 2:M2,........
void runMenu(int inDexMenu) {
	head();
	for (int i = 9; i < 54; i++)
	{
		gotoxy(68, i);
		printf("%c", 177);
	}
	switch (inDexMenu)
	{
	case 0: // ĐÂY LÀ MENU CHÍNH 
		switch (menu(thaotac, 6, 1, 11))
		{
		case -1: // THOÁT
			switch (MessageBox(NULL, "Ban co muon thoat khong?", "Xac Nhan Thoat", MB_YESNO | MB_ICONQUESTION))
			{
			case IDYES: exit(0);
				break;
			case IDNO: runMenu(0);
			}
			break;
		case 0: // Chọn vào M1 ( chạy runMenu với tham số 1 (chạy vào menu M1)
			runMenu(1);
			break;
		case 1: // In Danh Sách 
			runMenu(6);
			break;
		case 2: // CHỌN VÀO MỤC SẮP XẾP
			runMenu(2);
			break;
		case 3:
			runMenu(3);
			break;
		case 4:
			runMenu(4);
			break;
		case 5:
			exit(0);
		}
		break;
	case 1: //Menu Cập Nhật Sách (M1)
		switch (menu(thaoTacM1, 3, 25, 11))
		{
		case -1: // Thoát về Menu CHÍNH 
			for (int i = 0; i < 3; i++) // Xóa menu thống kê trước khi trở về menu 0
				xoaDanhMuc(thaoTacM1[i], 25, 11 + i * 6);
			runMenu(0);
			break;
		case 0:  // NHẬP
		{
			SACH s1;
			switch (themSach(s1))
			{
			case 0: // Khong lưu
				xoaManHinh();
				runMenu(0);
				break;
			case 1: // LƯU
				addTail(DANHSACH, newSach(s1.maSach, s1.tenSach, s1.nhaXuatBan, s1.namXuatBan, s1.soTrang, s1.tacGia, s1.noiDung, s1.giaSach, s1.ghiChu));
				MessageBox(NULL, "Luu thong tin thanh cong!", "Thanh Cong", MB_OK | MB_ICONINFORMATION);
				xoaManHinh();
				runMenu(0);
				break;
			}
		}
		case 1: // Sửa 
			MessageBox(NULL, "Nhan phim Enter, phim dieu huong de chon thong tin can sua, Esc de thoat", "Tro giup", MB_OK | MB_ICONINFORMATION);
			InDanhSachSach(DANHSACH);
			break;
		case 2: // Xóa
			MessageBox(NULL, "Nhan phim dieu huong de chon Sach, Delete de xoa, Esc de thoat", "Tro giup", MB_OK | MB_ICONINFORMATION);
			InDanhSachSach(DANHSACH);
			break;
		}
		break;
	case 2:// Menu Sâp Xếp (M3)
		switch (menu(thaoTacM3, 4, 25, 23))
		{
		case -1: // Thoát Về MENU CHÍNH 
			for (int i = 0; i < 4; i++) // Xóa dấu vết menu thống kê trước khi trở về menu 0
				xoaDanhMuc(thaoTacM3[i], 25, 23 + i * 6);
			textColor(243);
			runMenu(0);
			break;
		case 0: // Selection sort
			runMenu(5);
			break;
		case 1: // Insert sort
			runMenu(7);
			break;
		case 2: //bubber sort
			runMenu(8);
			break;
		case 3: //quick sort
			runMenu(8);
			break;
		}
		break;
	case 3: // Menu Tìm Kiếm (M4)
		switch (menu(thaoTacM4, 2, 25, 29))
		{
		case -1:
			for (int i = 0; i < 3; i++) // Xóa dấu vết menu thống kê trước khi trở về menu 0
				xoaDanhMuc(thaoTacM4[i], 25, 29 + i * 6);
			textColor(243);
			runMenu(0);
			break;
		case 0: // Tìm KIẾM TUẦN TỰ
			runMenu(10);
			break;
		case 1: // TÌM KIẾM NHỊ PHÂN
			runMenu(11);
			break;
		}
		break;
	case 4: // Menu Thống Kê (M5)
		if (DANHSACH.pHead == NULL) {
			MessageBox(NULL, "Danh sach trong!", "Thong bao", MB_OK | MB_ICONINFORMATION);
			runMenu(0);
		}
		switch (menu(thaoTacM5, 3, 25, 35))
		{
		case -1:  // thoát về M0
			for (int i = 0; i < 3; i++) // Xóa dấu vết menu thống kê trước khi trở về menu 0
				xoaDanhMuc(thaoTacM5[i], 25, 35 + i * 6);
			runMenu(0);
			break;
		case 0: // Thống kê theo Tác giả
			thongKe(DANHSACH, 0);
			runMenu(4);
			break;
		case 1: // Thống kê theo nhà Xuất Bản
			thongKe(DANHSACH, 1);
			runMenu(4);
			break;
		case 2: // Thống Kê theo Năm Xuất Bản
			thongKe(DANHSACH, 2);
			runMenu(4);
			break;
		}
		break;
	case 5: // trường sắp xếp trong M3
		switch (menu(sortField, 6, 49, 17))
		{
		case -1: // Thoát về menu2
			for (int i = 0; i < 6; i++) // Xóa dấu vết menu thống kê trước khi trở về menu 0
				xoaDanhMuc(sortField[i], 49, 17 + i * 6);
			textColor(243);
			runMenu(2);
			break;
		case 0: //mã sách
		{
			SelectionSort(DANHSACH, 0);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 1: // tên sách
		{
			SelectionSort(DANHSACH, 1);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 2: // nhà xuất bản
		{
			SelectionSort(DANHSACH, 2);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 3: // năm xuất bản
		{
			SelectionSort(DANHSACH, 3);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 4: // tác giả
		{
			SelectionSort(DANHSACH, 4);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 5: // giá
		{
			SelectionSort(DANHSACH, 5);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		}
		break;
	case 6: // menu in danh sách

		switch (menu(thaoTacM2, 2, 25, 17))
		{
		case -1: // thoát
			for (int i = 0; i < 6; i++) // Xóa dấu vết menu in ds trước khi trở về menu 0
				xoaDanhMuc(sortField[i], 25, 17 + i * 6);
			runMenu(0);
			break;
		case 0: // In r màn hình
			if (DANHSACH.pHead == NULL) {
				MessageBox(NULL, "Danh sach trong!", "Thong bao", MB_OK | MB_ICONINFORMATION);
				runMenu(6);
			}
			InDanhSachSach(DANHSACH);
			break;
		case 1: // In ra file
			ofstream file(TenFile); // tạo file mới
			for (SACH* p = DANHSACH.pHead; p; p = p->pNext)
			{
				file << p->maSach << endl;
				file << p->tenSach << endl;
				file << p->nhaXuatBan << endl;
				file << p->namXuatBan << endl;
				file << p->soTrang << endl;
				file << p->tacGia << endl;
				file << p->noiDung << endl;
				file << p->giaSach << endl;
				file << p->ghiChu << endl;
				file << "----------" << endl;
			}
			file.close();
			MessageBox(NULL, "Luu vao file thanh cong!", "SAVE", MB_OK | MB_ICONINFORMATION);
			textColor(243);
			for (int i = 0; i < 6; i++) // Xóa dấu vết menu in ds trước khi trở về menu 0
				xoaDanhMuc(sortField[i], 25, 17 + i * 6);
			runMenu(0);
			break;
		}
		break;
	case 7: // trường sắp xếp insert sort
		switch (menu(sortField, 6, 49, 17))
		{
		case -1: // Thoát về menu2
			for (int i = 0; i < 6; i++) // Xóa dấu vết menu thống kê trước khi trở về menu 0
				xoaDanhMuc(sortField[i], 49, 17 + i * 6);
			textColor(243);
			runMenu(2);
			break;
		case 0: //mã sách
		{
			InsertSort(DANHSACH, 0);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 1: // tên sách
		{
			InsertSort(DANHSACH, 1);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 2: // nhà xuất bản
		{
			InsertSort(DANHSACH, 2);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 3: // năm xuất bản
		{
			InsertSort(DANHSACH, 3);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 4: // tác giả
		{
			InsertSort(DANHSACH, 4);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 5: // giá
		{
			InsertSort(DANHSACH, 5);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		}
		break;
	case 8: // trường sắp xếp Bubble sort
		switch (menu(sortField, 6, 49, 17))
		{
		case -1: // Thoát về menu2
			for (int i = 0; i < 6; i++) // Xóa dấu vết menu thống kê trước khi trở về menu 0
				xoaDanhMuc(sortField[i], 49, 17 + i * 6);
			textColor(243);
			runMenu(2);
			break;
		case 0: //mã sách
		{
			BubbleSort(DANHSACH, 0);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 1: // tên sách
		{
			BubbleSort(DANHSACH, 1);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 2: // nhà xuất bản
		{
			BubbleSort(DANHSACH, 2);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 3: // năm xuất bản
		{
			BubbleSort(DANHSACH, 3);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 4: // tác giả
		{
			BubbleSort(DANHSACH, 4);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 5: // giá
		{
			BubbleSort(DANHSACH, 5);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		}
		break;
	case 9: // trường sắp xếp Quick Sort
		switch (menu(sortField, 6, 49, 17))
		{
		case -1: // Thoát về menu2
			for (int i = 0; i < 6; i++) // Xóa dấu vết menu thống kê trước khi trở về menu 0
				xoaDanhMuc(sortField[i], 49, 17 + i * 6);
			textColor(243);
			runMenu(2);
			break;
		case 0: //mã sách
		{
			quickSort(DANHSACH, DANHSACH.pHead, DANHSACH.pTail, 0);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 1: // tên sách
		{
			quickSort(DANHSACH, DANHSACH.pHead, DANHSACH.pTail, 1);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 2: // nhà xuất bản
		{
			quickSort(DANHSACH, DANHSACH.pHead, DANHSACH.pTail, 2);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 3: // năm xuất bản
		{
			quickSort(DANHSACH, DANHSACH.pHead, DANHSACH.pTail, 3);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 4: // tác giả
		{
			quickSort(DANHSACH, DANHSACH.pHead, DANHSACH.pTail, 4);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		case 5: // giá
		{
			quickSort(DANHSACH, DANHSACH.pHead, DANHSACH.pTail, 5);
			MessageBox(NULL, "Danh sach sach da duoc sap xep!", "Xac Nhan", MB_OK | MB_ICONINFORMATION);
			runMenu(5);
		}
		break;
		}
		break;
	case 10: // trường tìm kiếm tuần tự
	{
		vector<int> arrViTri;
		arrViTri.resize(0);
		switch (menu(searchField, 7, 49, 13)) // "      Ma Sach " , "      Ten Sach" , "       NXB" , "   Nam Xuat ban" , "     Tac Gia" , "        Gia" ,"     Ghi Chu"
		{
		case -1: // thoát
			for (int i = 0; i < 7; i++) // Xóa dấu vết menu thống kê trước khi trở về menu 0
				xoaDanhMuc(searchField[i], 49, 13 + i * 6);
			textColor(243);
			runMenu(3);
			break;
		case 0: { // mã sách
			string str = chuoiCanTimKiem();
			vector<SACH> arrSach = timKienTuanTu(DANHSACH, str, arrViTri, 0);
			inSachTimKiem(arrSach, arrViTri, str, 0);
			break; }
		case 1: { // tên sách 
			string str = chuoiCanTimKiem();
			vector<SACH> arrSach = timKienTuanTu(DANHSACH, str, arrViTri, 1);
			inSachTimKiem(arrSach, arrViTri, str, 1);
			break; }
		case 2: { // NXB
			string str = chuoiCanTimKiem();
			vector<SACH> arrSach = timKienTuanTu(DANHSACH, str, arrViTri, 2);
			inSachTimKiem(arrSach, arrViTri, str, 2);
			break; }
		case 3: { // năm xuất bản
			string str = chuoiCanTimKiem();
			vector<SACH> arrSach = timKienTuanTu(DANHSACH, str, arrViTri, 3);
			inSachTimKiem(arrSach, arrViTri, str, 3);
			break; }
		case 4: { // tác giả
			string str = chuoiCanTimKiem();
			vector<SACH> arrSach = timKienTuanTu(DANHSACH, str, arrViTri, 4);
			inSachTimKiem(arrSach, arrViTri, str, 4);
			break; }
		case 5: { // nội dung
			string str = chuoiCanTimKiem();
			vector<SACH> arrSach = timKienTuanTu(DANHSACH, str, arrViTri, 5);
			inSachTimKiem(arrSach, arrViTri, str, 5);
			break; }
		case 6: { // ghi chú
			string str = chuoiCanTimKiem();
			vector<SACH> arrSach = timKienTuanTu(DANHSACH, str, arrViTri, 6);
			inSachTimKiem(arrSach, arrViTri, str, 6);
			break; }
		}
		xoaManHinh();
		runMenu(0);
	}
	break;
	case 11: // trường tìm kiếm nhị phân
		switch (menu(searchField, 7, 49, 13)) // "      Ma Sach " , "      Ten Sach" , "       NXB" , "   Nam Xuat ban" , "     Tac Gia" , "        Gia" ,"     Ghi Chu"
		{
		case -1: // thoát
			for (int i = 0; i < 7; i++) // Xóa dấu vết menu thống kê trước khi trở về menu 0
				xoaDanhMuc(searchField[i], 49, 13 + i * 6);
			textColor(243);
			runMenu(3);
			break;
		case 0: { // mã sách
			vector <SACH> vtrS;
			timKiemNhiPhan(DANHSACH, chuoiCanTimKiem(), DANHSACH.pHead, DANHSACH.pTail, 0, vtrS);
			inSachTimKiemNhiPhan(vtrS);
			system("pause");
			break; }
		case 1: { // tên sách sle
			vector <SACH> vtrS;
			timKiemNhiPhan(DANHSACH, chuoiCanTimKiem(), DANHSACH.pHead, DANHSACH.pTail, 1, vtrS);
			inSachTimKiemNhiPhan(vtrS);
			system("pause");
			break; }
		case 2: { // NXB
			vector <SACH> vtrS;
			timKiemNhiPhan(DANHSACH, chuoiCanTimKiem(), DANHSACH.pHead, DANHSACH.pTail, 2, vtrS);
			inSachTimKiemNhiPhan(vtrS);
			system("pause");
			break; }
		case 3: { // năm xuất bản
			vector <SACH> vtrS;
			timKiemNhiPhan(DANHSACH, chuoiCanTimKiem(), DANHSACH.pHead, DANHSACH.pTail, 3, vtrS);
			inSachTimKiemNhiPhan(vtrS);
			system("pause");
			break; }
		case 4: { // tác giả
			vector <SACH> vtrS;
			timKiemNhiPhan(DANHSACH, chuoiCanTimKiem(), DANHSACH.pHead, DANHSACH.pTail, 4, vtrS);
			inSachTimKiemNhiPhan(vtrS);
			system("pause");
			break; }
		case 5: { // nội dung
			vector <SACH> vtrS;
			timKiemNhiPhan(DANHSACH, chuoiCanTimKiem(), DANHSACH.pHead, DANHSACH.pTail, 5, vtrS);
			inSachTimKiemNhiPhan(vtrS);
			system("pause");
			break; }
		case 6: { // ghi chú
			vector <SACH> vtrS;
			timKiemNhiPhan(DANHSACH, chuoiCanTimKiem(), DANHSACH.pHead, DANHSACH.pTail, 6, vtrS);
			inSachTimKiemNhiPhan(vtrS);
			system("pause");
			break; }
		}
		xoaManHinh();
		runMenu(0);
		break;
	}

}


