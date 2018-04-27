#include"Interface.h"
#include"MyLib.h"

// màn hình chào
void wellcome() {
	for (int i = 7; i < 15; i++){
		textColor(i);
		logo();//	Sleep(10);
	} // in logo
	textColor(11);
	logo();
	textColor(14);
	for (int i = 1; i < 53; i++){
		gotoxy(1, i);
		cout << "||";
		gotoxy(208, 53 - i);
		cout << "||";
		Sleep(10);
	}
	for (int i = 1; i < 208; i++){
		gotoxy(i, 52);
		cout << "=";
		gotoxy(208 - i, 1);
		cout << "=";
		//Sleep(5);
	}
	text();
	//Sleep(2000);
	system("pause>nul");
}
// Logo ở màn hình chào
void logo() {
	gotoxy(0, 4);
	cout << "\t\t\t\t\t\t	                                                              ............                         " << endl;
	cout << "\t\t\t\t\t\t	                                                        `.-:/++ossyyyssso+/-`                      " << endl;
	cout << "\t\t\t\t\t\t\t                                                   `.:/osyyyyyyyyyyyyyyyyyyyyyo-                    " << endl;
	cout << "\t\t\t\t\t\t\t                                               .:+syyyyyso++///////++syyyyyyyyyyo`                  " << endl;
	cout << "\t\t\t\t\t\t\t                                          `-/oyyo+/-.`                 `:+yyyyyyyo                  " << endl;
	cout << "\t\t\t\t\t\t\t                                      `-/os+:-`                           `/yyyyyy`                 " << endl;
	cout << "\t\t\t\t\t\t\t                                   .:++:.`                                  -yyyyy.                 " << endl;
	cout << "\t\t\t\t\t\t\t                                -//:`                                        +yyyy`                 " << endl;
	cout << "\t\t\t\t\t\t\t                             .--.                                            :yyy/                  " << endl;
	cout << "\t\t\t\t\t\t\t                          ...                                                /yyo                   " << endl;
	cout << "\t\t\t\t\t\t\t            ooooooooo/  ``     `ooooooooo:     -ooooooooooooooooooooo`      `yys`-oooooooo.         " << endl;
	cout << "\t\t\t\t\t\t\t            yyyyyyyyyy+       .syyyyyyyyy/     :yyyyyyyyyyyyyyyyyyyyy`      +ys`:yyyyyyyyys.        " << endl;
	cout << "\t\t\t\t\t\t\t            yyyyyyyyyyyo`    .yyyyyyyyyyy/     :yyyyyyyyyyyyyyyyyyyyy`     /y+`/yyyyyyyyyyyy-       " << endl;
	cout << "\t\t\t\t\t\t\t            yyyyyyyyyyyys`  -yyyyyyyyyyyy/            `yyyyyyo            +y: /yyyyyy+syyyyyy:      " << endl;
	cout << "\t\t\t\t\t\t\t            yyyyyy+.syyyyyyyyyyyy+`yyyyyy/             yyyyyyo         :s- `oyyyyyyy+++oyyyyyyy/    " << endl;
	cout << "\t\t\t\t\t\t\t          ` yyyyyy+ `oyyyyyyyyyy/ `yyyyyy/             yyyyyyo       -o:  `syyyyyyyyyyyyyyyyyyyy+   " << endl;
	cout << "\t\t\t\t\t\t\t        `-. yyyyyy+  `oyyyyyyyy:  `yyyyyy/             yyyyyyo     .+:`  `syyyyyysssssssssyyyyyyyo` " << endl;
	cout << "\t\t\t\t\t\t\t       ://  yyyyyy+    +yyyyyy-   `yyyyyy/             yyyyyyo   :+:    .syyyyyy:          /yyyyyys`" << endl;
	cout << "\t\t\t\t\t\t\t     `+/s`  ::::::-     -::::.     ::::::.             ::::::-./+:      -::::::-            -::::::-" << endl;
	cout << "\t\t\t\t\t\t\t    -s:ys                                                  -/++-`                                   " << endl;
	cout << "\t\t\t\t\t\t\t   /y-yyy.                                             `:+o+/-`                                     " << endl;
	cout << "\t\t\t\t\t\t\t  /yo/yyyo`                                        .:+so+/:.                                        " << endl;
	cout << "\t\t\t\t\t\t\t :yy:oyyyys:                                  .:/oys+++/-                                           " << endl;
	cout << "\t\t\t\t\t\t\t.yyy//yyyyyyy/-`                       `.:/+syys+++++:`                                             " << endl;
	cout << "\t\t\t\t\t\t\t+yyys.syyyyyyyyyso/:--........--://+osyyyyys+++os+-`                                                " << endl;
	cout << "\t\t\t\t\t\t\tyyyyys-+yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo++++sys/.                                                    " << endl;
	cout << "\t\t\t\t\t\t\tyyyyyyy+:/oyyyyyyyyyyyyyyyyyyyyso+++++syys+-`                                                       " << endl;
	cout << "\t\t\t\t\t\t\t/yyyyyyyys+/////+++++++++++++++osyyyyo/-`                                                           " << endl;
	cout << "\t\t\t\t\t\t\t +yyyyyyyyyyyyyyyyyyyyyyyyyyyyyys+:.                                                                " << endl;
	cout << "\t\t\t\t\t\t\t  .+yyyyyyyyyyyyyyyyyyyyyys+/-.                                                                     " << endl;
	cout << "\t\t\t\t\t\t\t     .:+oosssssssoo+/:-.`                                                                           " << endl;
}
// Chữ phía trên khi chạy ctrinh
void head() {
	gotoxy(1, 1);
	cout << "\t\t\t\t\t   _____ _                               _______   _       _        ____                      _              ____             _" << endl;
	cout << "\t\t\t\t\t  / ____| |                             |__   __| (_)     | |      / __ \\                    | |            / ___|           | |" << endl;
	cout << "\t\t\t\t\t | |    | |__  _   _  ___  _ __   __ _     | |_ __ _ _ __ | |__   | |  | |_   _  __ _ _ __   | |    _   _  | (___   __ _  ___| |__" << endl;
	cout << "\t\t\t\t\t | |    | '_ \\| | | |/ _ \\| '_ \\ / _` |    | | '__| | '_ \\| '_ \\  | |  | | | | |/ _` | '_ \\  | |   | | | |  \\___ \\ / _` |/  _| '_ \\" << endl;
	cout << "\t\t\t\t\t | |____| | | | |_| | (_) | | | | (_| |    | | |  | | | | | | | | | |__| | |_| | (_| | | | | | |___| |_| |  ____) | (_| |  (_| | | |" << endl;
	cout << "\t\t\t\t\t  \\_____|_| |_|\\__,_|\\___/|_| |_|\\__, |    |_|_|  |_|_| |_|_| |_|  \\___\\_\\\\__,_|\\__,_|_| |_| |______\\__, | |_____/ \\__,_|\\___|_| |_|" << endl;
	cout << "\t\t\t\t\t                                  __/ |                                                              __/ |                                               " << endl;
	cout << "\t\t\t\t\t                                 |___/                                                              |___/                                                " << endl;
	for (int i = 0; i < 211; i++)
		printf("%c", 177);
	gotoxy(0, 53);
	for (int i = 0; i < 211; i++)
		printf("%c", 177);
}
// chữ ở màn hình chào
void text() {
	textColor(14);
	gotoxy(0, 38);
	cout << " ||\t\t\t\t\t  _____ _  _ _   _  ___   _____ _   ___   _  ____   __  _____ _  _ _   _  _ _____   _      _   ___   _____ ___ ___ _  _ _  _ " << endl;
	cout << " ||\t\t\t\t\t |_   _| || | | | |/ __| |_   _/_\\ | _ \\ | |/ /\\ \\ / / |_   _| || | | | |/_\\_   _| | |    /_\\ | _ \\ |_   _| _ \\_ _| \\| | || |" << endl;
	cout << " ||\t\t\t\t\t   | | | __ | |_| | (__    | |/ _ \\|  _/ | ' <  \\ V /    | | | __ | |_| / _ \\| |   | |__ / _ \\|  _/   | | |   /| || .` | __ |" << endl;
	cout << " ||\t\t\t\t\t   |_| |_||_|\\___/ \\___|   |_/_/ \\_\\_|   |_|\\_\\  |_|     |_| |_||_|\\___/_/ \\_\\_|   |____/_/ \\_\\_|     |_| |_|_\\___|_|\\_|_||_|" << endl;
	cout << endl;
	gotoxy(141, 43);
	cout << " PHAM NGOC TOAN _ KTPM15";
}
// In khung phần hiển thị danh sách
void inKhungDS() {
	gotoxy(1, 11);					// ra vị trí khung bên phải
	printf("%c", 201);
	for (int i = 0; i < 208; i++)
		printf("%c", 205);
	printf("%c", 187);
	for (int i = 12; i < 50; i++) {
		gotoxy(1, i);
		printf("%c", 186);
		gotoxy(210, i);
		printf("%c", 186);
	}
	gotoxy(1, 50);
	printf("%c", 200);
	for (int i = 0; i < 208; i++)
		printf("%c", 205);
	printf("%c", 188);
	gotoxy(98, 11);
	printf("%c  Thong Tin Sach  %c", 185, 204); // in khung bên ngoài
	gotoxy(98, 10);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	gotoxy(98, 12);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
}