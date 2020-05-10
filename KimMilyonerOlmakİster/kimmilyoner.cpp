#include "stdafx.h"
#include "kimmilyoner.h"
#include "stdafx.h" 
#include <iostream> 
#include<string> 
#include<fstream>
#include <sstream>
#include "vector"
#include "time.h"
#include<stdlib.h>
#include<iomanip>
#include <Windows.h>


using namespace std;

void dosyadanokuma()
{
	ifstream dosya("question.csv", ios::in);
	vector<vector<string >> asil;

	if (!dosya)
	{
		cout << " dosya acilamiyor";
		exit(EXIT_FAILURE);

	}
	string line;
	while (getline(dosya, line)) {
		string soru;
		vector<string>sorular;
		stringstream stream(line);
		while (getline(stream, soru, '"'))
		{
			if (soru != ",") {
				sorular.push_back(soru);
			}
		}
		asil.push_back(sorular);
	}
	
	dosya.close();
	srand(time(NULL));
	int kazancarray[13] = { 0,500,1000,2000,3000,5000,7500,15000,30000,60000,125000,250000,1000000};
	int haklar[2] = { 1,1 };
	int yandimi = 0;
	int sorukac = 1;
	int kazanilan = 0;
	string cevap;
	int jokerkullanilacakmi = 0;
	int sorucevaplanacakmi = 1;
	string dogrucevap;
	string ad;
	string soyad;
	int basamaksayisi = 0;

	int adlenght = 30-ad.length();
	int soyadlenght = 30-soyad.length();
	cout << endl << endl << endl << endl << "          LUTFEN ONCE AD SONRA SOYAD GIRINIZ "<< endl;

	cout << "          _________________________________________________________________________________________________" << endl << endl;
	cout << "          AD : ";
		cin >> ad;
	cout << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
	cout << "          SOYAD : ";
	cin >> soyad;
	system("CLS");

	

	while (yandimi == 0 && sorukac <=12) {	
		int randomdeger = 0;
	    int	soru = stoi(asil[randomdeger][2]);
		while (soru != sorukac) {
			randomdeger = rand() % 1907+1;
			soru = stoi(asil[randomdeger][2]);
		
		}
		if (asil[randomdeger][9] == "A") {
			dogrucevap = asil[randomdeger][5];
		}
		if (asil[randomdeger][9] == "B") {
			dogrucevap = asil[randomdeger][6];
		}
		if (asil[randomdeger][9] == "C") {
			dogrucevap = asil[randomdeger][7];
		}
		if (asil[randomdeger][9] == "D") {
			dogrucevap = asil[randomdeger][8];
		}
		
		cout << "          _________________________________________________________________________________________________" << endl << endl;
		cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;		
		cout << "          _________________________________________________________________________________________________" << endl << endl;
		cout << "          " << asil[randomdeger][3] << endl;
		cout << "          _________________________________________________________________________________________________" << endl << endl;

		cout << "          A-) " << asil[randomdeger][5] << "   ";
		cout << "B-) " << asil[randomdeger][6] << "   ";
		cout << "C-) " << asil[randomdeger][7] << "   ";
		cout << "D-) " << asil[randomdeger][8] << "   ";
		cout << endl << "          _________________________________________________________________________________________________" << endl  ;

		cout << endl  << "          SORUYU CEVAPLAMAK ISTIYORSANIZ 1 | YARISMADAN CEKILMEK ISTIYORSANIZ 2 GIRINIZ.";
		cout << endl <<"          _________________________________________________________________________________________________" << endl  ;

		cout << endl <<  "          CEVABINIZ : ";
		cin >> sorucevaplanacakmi;
			

		
			while (sorucevaplanacakmi != 1 && sorucevaplanacakmi != 2) {
				system("CLS");
				cout << "                                          YANLIS BIR DEGER GIRDINIZ !! " << endl;
				cout << "          _________________________________________________________________________________________________" << endl << endl;
				cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;				cout << "          _________________________________________________________________________________________________" << endl << endl;
				cout << "          " << asil[randomdeger][3] <<endl ; 
				cout << "          _________________________________________________________________________________________________" << endl << endl;

				cout << "          A-) " << asil[randomdeger][5] << "   ";
				cout << "B-) " << asil[randomdeger][6] << "   ";
				cout << "C-) " << asil[randomdeger][7] << "   ";
				cout << "D-) " << asil[randomdeger][8] << "   ";
				cout << endl << "          _________________________________________________________________________________________________" << endl;

				cout << endl << "          SORUYU CEVAPLAMAK ISTIYORSANIZ 1 | YARISMADAN CEKILMEK ISTIYORSANIZ 2 GIRINIZ.";
				cout << endl << "          _________________________________________________________________________________________________" << endl;

				cout << endl << "          CEVABINIZ : ";
				cin >> sorucevaplanacakmi;
			}
			switch (sorucevaplanacakmi) {

			case 2: {
			
				    kazanilan = kazancarray[sorukac - 1];
					ofstream outfile("oynayanlar.txt", ios::out | ios::app);
					outfile << left << setw(30) << ad << left << setw(30) << soyad << left << setw(7) << kazanilan << " TL" << endl;										outfile.close();
					outfile.close();
				for (int a = 10; a > 0; a--) {
					system("CLS");
					cout << endl << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
					cout << "                                       YARISMADAN CEKILDINIZ  " << kazancarray[sorukac - 1] << " TL KAZANDINIZ ";
					cout << endl << "          _________________________________________________________________________________________________" << endl << endl << endl;
					cout << "                                     " << a << " SANIYE SONRA MENUYE YONLENDIRILECEKSINIZ.";
					Sleep(1000);
					
				}
				menu();
				break;
			}
			case 1: {
				if (haklar[0] == 1 && haklar[1] == 1) {
					cout << endl << endl << "          50/50 JOKER HAKKI ICIN 1 | CIFT CEVAP HAKKI ICIN 2 | JOKER KULLANMAMAK ICIN 0 GIRINIZ";
					cout << endl << "          _________________________________________________________________________________________________" << endl ;
					cout << endl << "          CEVABINIZ  : ";

					cin >> jokerkullanilacakmi;
					while (jokerkullanilacakmi != 1 && jokerkullanilacakmi != 0 && jokerkullanilacakmi != 2) {
						system("CLS");
						cout << "                                          YANLIS BIR DEGER GIRDINIZ !! " << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          " << asil[randomdeger][3] << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;

						cout << "          A-) " << asil[randomdeger][5] << "   ";
						cout << "B-) " << asil[randomdeger][6] << "   ";
						cout << "C-) " << asil[randomdeger][7] << "   ";
						cout << "D-) " << asil[randomdeger][8] << "   ";
						cout << endl << endl << "          50/50 JOKER HAKKI ICIN 1 | CIFT CEVAP HAKKI ICIN 2 | JOKER KULLANMAMAK ICIN 0 GIRINIZ";
						cout << endl << "          _________________________________________________________________________________________________" << endl;
						cout << endl << "          CEVABINIZ  : ";
						cin >> jokerkullanilacakmi;
					}
				}
				if (haklar[0] == 1 && haklar[1] == 0) {
					cout << endl << endl << "          50/50 JOKER HAKKI ICIN 1 | JOKER KULLANMAMAK ICIN 0 GIRINIZ";
					cout << endl << "          _________________________________________________________________________________________________" << endl;
					cout << endl << "          CEVABINIZ  : ";

					cin >> jokerkullanilacakmi;
					while (jokerkullanilacakmi != 1 && jokerkullanilacakmi != 0 && jokerkullanilacakmi != 2) {
						system("CLS");
						cout << "                                          YANLIS BIR DEGER GIRDINIZ !! " << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          " << asil[randomdeger][3] << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;

						cout << "          A-) " << asil[randomdeger][5] << "   ";
						cout << "B-) " << asil[randomdeger][6] << "   ";
						cout << "C-) " << asil[randomdeger][7] << "   ";
						cout << "D-) " << asil[randomdeger][8] << "   ";
						cout << endl << endl << "          50/50 JOKER HAKKI ICIN 1 | JOKER KULLANMAMAK ICIN 0 GIRINIZ";
						cout << endl << "          _________________________________________________________________________________________________" << endl;
						cout << endl << "          CEVABINIZ  : ";
						cin >> jokerkullanilacakmi;
					}
				}
				if (haklar[0] == 0 && haklar[1] == 1) {
					cout << endl << endl << "          CIFT CEVAP HAKKI ICIN 2 | JOKER KULLANMAMAK ICIN 0 GIRINIZ";
					cout << endl << "          _________________________________________________________________________________________________" << endl;
					cout << endl << "          CEVABINIZ  : ";

					cin >> jokerkullanilacakmi;
					while (jokerkullanilacakmi != 1 && jokerkullanilacakmi != 0 && jokerkullanilacakmi != 2) {
						system("CLS");
						cout << "                                          YANLIS BIR DEGER GIRDINIZ !! " << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          " << asil[randomdeger][3] << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;

						cout << "          A-) " << asil[randomdeger][5] << "   ";
						cout << "B-) " << asil[randomdeger][6] << "   ";
						cout << "C-) " << asil[randomdeger][7] << "   ";
						cout << "D-) " << asil[randomdeger][8] << "   ";
						cout << endl << endl << "          CIFT CEVAP HAKKI ICIN 2 | JOKER KULLANMAMAK ICIN 0 GIRINIZ";
						cout << endl << "          _________________________________________________________________________________________________" << endl;
						cout << endl << "          CEVABINIZ  : ";
						cin >> jokerkullanilacakmi;
					}
				}

				switch (jokerkullanilacakmi) {
				case 0: {

					system("CLS");
					cout << "          _________________________________________________________________________________________________" << endl << endl;
					cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;					cout << "          _________________________________________________________________________________________________" << endl << endl;
					cout << "          " << asil[randomdeger][3] << endl;
					cout << "          _________________________________________________________________________________________________" << endl << endl;

					cout << "          A-) " << asil[randomdeger][5] << "   ";
					cout << "B-) " << asil[randomdeger][6] << "   ";
					cout << "C-) " << asil[randomdeger][7] << "   ";
					cout << "D-) " << asil[randomdeger][8] << "   ";
					cout << endl << "          _________________________________________________________________________________________________" << endl;
					cout << "          CEVABINIZ : ";
					cin >> cevap;
					while (cevap != "A" && cevap != "B" && cevap != "C" && cevap != "D") {
						system("CLS");
						cout << endl << endl << "                                     YANLIS BIR DEGER GIRDINIZ TEKRAR GIRINIZ !! " << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          " << asil[randomdeger][3] << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;

						cout << "          A-) " << asil[randomdeger][5] << "   ";
						cout << "B-) " << asil[randomdeger][6] << "   ";
						cout << "C-) " << asil[randomdeger][7] << "   ";
						cout << "D-) " << asil[randomdeger][8] << "   ";
						cout << endl << "          _________________________________________________________________________________________________" << endl;
						cout << "          CEVABINIZ : ";
						cin >> cevap;
					}

					if (cevap == asil[randomdeger][9]) {

						cout << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "                                                    CEVABINIZ DOGRU" << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						Sleep(3000);
						sorukac++;
						system("CLS");

					}
					else {
						if (sorukac <= 2) {
								kazanilan = 0;
								ofstream outfile("oynayanlar.txt", ios::out | ios::app);
								outfile << left << setw(30) << ad << left << setw(30) << soyad << left << setw(7) << kazanilan << " TL" << endl;										outfile.close();
								for (int a = 10; a > 0; a--) {
								system("CLS");
								cout << endl << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
								cout << "                                         YANLIS CEVAP VERDINIZ 0 TL KAZANDINIZ  ";
								cout << endl << "          _________________________________________________________________________________________________" << endl << endl << endl;
								cout << "                                     " << a << " SANIYE SONRA MENUYE YONLENDIRILECEKSINIZ.";
								Sleep(1000);
							}
								menu();

						}
						if (sorukac > 2 && sorukac <= 7) {
								kazanilan = 1000;
								ofstream outfile("oynayanlar.txt", ios::out | ios::app);
								outfile << left << setw(30) << ad << left << setw(30) << soyad << left << setw(7) << kazanilan << " TL" << endl;										outfile.close();
								for (int a = 10; a > 0; a--) {
								system("CLS");
								cout << endl << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
								cout << "                                         YANLIS CEVAP VERDINIZ 1.000 TL KAZANDINIZ  ";
								cout << endl << "          _________________________________________________________________________________________________" << endl << endl << endl;
								cout << "                                     " << a << " SANIYE SONRA MENUYE YONLENDIRILECEKSINIZ.";
								Sleep(1000);
							}
								menu();
							if (sorukac > 7) {
									kazanilan = 15000;
									ofstream outfile("oynayanlar.txt", ios::out | ios::app);
									outfile << left << setw(30) << ad << left << setw(30) << soyad << left << setw(7) << kazanilan << " TL" << endl;										outfile.close();
									for (int a = 10; a > 0; a--) {
									system("CLS");
									cout << endl << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
									cout << "                                         YANLIS CEVAP VERDINIZ 15.000 TL KAZANDINIZ  ";
									cout << endl << "          _________________________________________________________________________________________________" << endl << endl << endl;
									cout << "                                     " << a << " SANIYE SONRA MENUYE YONLENDIRILECEKSINIZ.";
									Sleep(1000);
								}
									menu();
							}

						}
								yandimi = 1;

						}
					jokerkullanilacakmi = 0;
						break;
					}
				
				case 1: {
					for (int sayac3 = 0; sayac3 <= 1; sayac3++) {
						int rand2 = 0;
						rand2 = rand() % 9;
						while (rand2 < 5 || asil[randomdeger][rand2] == dogrucevap || asil[randomdeger][rand2] == "-") {
							rand2 = rand() % 9;
						}
						asil[randomdeger][rand2] = "-";



					}
					haklar[0] = 0;
					system("CLS");
					cout << "          _________________________________________________________________________________________________" << endl << endl;
					cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;					cout << "          _________________________________________________________________________________________________" << endl << endl;
					cout << "          " << asil[randomdeger][3] << endl;
					cout << "          _________________________________________________________________________________________________" << endl << endl;

					cout << "          A-) " << asil[randomdeger][5] << "   ";
					cout << "B-) " << asil[randomdeger][6] << "   ";
					cout << "C-) " << asil[randomdeger][7] << "   ";
					cout << "D-) " << asil[randomdeger][8] << "   ";
					cout << endl << "          _________________________________________________________________________________________________" << endl;
					cout << "          CEVABINIZ : ";

					cin >> cevap;
					while (cevap != "A" && cevap != "B" && cevap != "C" && cevap != "D") {
						system("CLS");
						cout << endl << endl << "                                     YANLIS BIR DEGER GIRDINIZ TEKRAR GIRINIZ !! " << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          " << asil[randomdeger][3] << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;

						cout << "          A-) " << asil[randomdeger][5] << "   ";
						cout << "B-) " << asil[randomdeger][6] << "   ";
						cout << "C-) " << asil[randomdeger][7] << "   ";
						cout << "D-) " << asil[randomdeger][8] << "   ";
						cout << endl << "          _________________________________________________________________________________________________" << endl;
						cout << "          CEVABINIZ : ";
						cin >> cevap;
					}

					if (cevap == asil[randomdeger][9]) {
						cout << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "                                                    CEVABINIZ DOGRU" << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;

						Sleep(3000);
						sorukac++;
						system("CLS");

					}
					else {
						if (sorukac <= 2) {
								kazanilan = 0;
								ofstream outfile("oynayanlar.txt", ios::out | ios::app);
								outfile << left << setw(30) << ad << left << setw(30) << soyad << left << setw(7) << kazanilan << " TL" << endl;										outfile.close();
								for (int a = 10; a > 0; a--) {
								system("CLS");
								cout << endl << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
								cout << "                                           YANLIS CEVAP VERDINIZ 0 TL KAZANDINIZ  ";
								cout << endl << "          _________________________________________________________________________________________________" << endl << endl << endl;
								cout << "                                     " << a << " SANIYE SONRA MENUYE YONLENDIRILECEKSINIZ.";
								Sleep(1000);
							}
								menu();

						}
						if (sorukac > 2 && sorukac <= 7) {
								kazanilan = 1000;
								ofstream outfile("oynayanlar.txt", ios::out | ios::app);
								outfile << left << setw(30) << ad << left << setw(30) << soyad << left << setw(7) << kazanilan << " TL" << endl;										outfile.close();
								for (int a = 10; a > 0; a--) {
								system("CLS");
								cout << endl << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
								cout << "                                           YANLIS CEVAP VERDINIZ 1.000 TL KAZANDINIZ  ";
								cout << endl << "          _________________________________________________________________________________________________" << endl << endl << endl;
								cout << "                                     " << a << " SANIYE SONRA MENUYE YONLENDIRILECEKSINIZ.";
								Sleep(1000);
							}
								menu();
							if (sorukac > 7) {
									kazanilan = 15000;
									ofstream outfile("oynayanlar.txt", ios::out | ios::app);
									outfile << left << setw(30) << ad << left << setw(30) << soyad << left << setw(7) << kazanilan << " TL" << endl;										outfile.close();
									for (int a = 10; a > 0; a--) {
									system("CLS");
									cout << endl << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
									cout << "                                           YANLIS CEVAP VERDINIZ 15.000 TL KAZANDINIZ  ";
									cout << endl << "          _________________________________________________________________________________________________" << endl << endl << endl;
									cout << "                                     " << a << " SANIYE SONRA MENUYE YONLENDIRILECEKSINIZ.";
									Sleep(1000);
								}
									menu();
							}

						}
								yandimi = 1;

					}

					jokerkullanilacakmi = 0;
					break;
				}

				case 2:
				{
					haklar[1] = 0;
					system("CLS");
					cout << "          _________________________________________________________________________________________________" << endl << endl;
					cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;					cout << "          _________________________________________________________________________________________________" << endl << endl;
					cout << "          " << asil[randomdeger][3] << endl;
					cout << "          _________________________________________________________________________________________________" << endl << endl;

					cout << "          A-) " << asil[randomdeger][5] << "   ";
					cout << "B-) " << asil[randomdeger][6] << "   ";
					cout << "C-) " << asil[randomdeger][7] << "   ";
					cout << "D-) " << asil[randomdeger][8] << "   ";
					cout << endl << "          _________________________________________________________________________________________________" << endl;
					cout << "          CEVABINIZ : ";
					cin >> cevap;
					while (cevap != "A" && cevap != "B" && cevap != "C" && cevap != "D") {
						system("CLS");
						cout << endl << endl << "                                     YANLIS BIR DEGER GIRDINIZ TEKRAR GIRINIZ !! " << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          " << asil[randomdeger][3] << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;

						cout << "          A-) " << asil[randomdeger][5] << "   ";
						cout << "B-) " << asil[randomdeger][6] << "   ";
						cout << "C-) " << asil[randomdeger][7] << "   ";
						cout << "D-) " << asil[randomdeger][8] << "   ";
						cout << endl << "          _________________________________________________________________________________________________" << endl;
						cout << "          CEVABINIZ : ";
						cin >> cevap;
					}
					if (cevap == asil[randomdeger][9]) {
						cout << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "                                                    CEVABINIZ DOGRU" << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						Sleep(3000);
						sorukac++;
						system("CLS");

					}
					else {
						int deger13 = 0;
						if (cevap == "A") {
							deger13 = 5;

						}
						if (cevap == "B") {
							deger13 = 6;

						}
						if (cevap == "C") {
							deger13 = 7;

						}
						if (cevap == "D") {
							deger13 = 8;

						}

						asil[randomdeger][deger13] = "-";

						system("CLS");
						cout << "                                       BIR HAKKINIZ DAHA BULUNMAKTA" << endl << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;						cout << "          _________________________________________________________________________________________________" << endl << endl;
						cout << "          " << asil[randomdeger][3] << endl;
						cout << "          _________________________________________________________________________________________________" << endl << endl;

						cout << "          A-) " << asil[randomdeger][5] << "   ";
						cout << "B-) " << asil[randomdeger][6] << "   ";
						cout << "C-) " << asil[randomdeger][7] << "   ";
						cout << "D-) " << asil[randomdeger][8] << "   ";
						cout << endl << "          _________________________________________________________________________________________________" << endl;
						cout << "          2.CEVABINIZ : ";
						cin >> cevap;
						while (cevap != "A" && cevap != "B" && cevap != "C" && cevap != "D") {
							system("CLS");
							cout << endl << endl << "                                     YANLIS BIR DEGER GIRDINIZ TEKRAR GIRINIZ !! " << endl;
							cout << "          _________________________________________________________________________________________________" << endl << endl;
							cout << "          SORU  " << sorukac << "     ( " << kazancarray[sorukac] << " TL) " << endl << endl;						cout << "          _________________________________________________________________________________________________" << endl << endl;
							cout << "          " << asil[randomdeger][3] << endl;
							cout << "          _________________________________________________________________________________________________" << endl << endl;

							cout << "          A-) " << asil[randomdeger][5] << "   ";
							cout << "B-) " << asil[randomdeger][6] << "   ";
							cout << "C-) " << asil[randomdeger][7] << "   ";
							cout << "D-) " << asil[randomdeger][8] << "   ";
							cout << endl << "          _________________________________________________________________________________________________" << endl;
							cout << "          2.CEVABINIZ : ";
							cin >> cevap;
						}


						if (cevap == asil[randomdeger][9]) {

							cout << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
							cout << "                                                    CEVABINIZ DOGRU" << endl;
							cout << "          _________________________________________________________________________________________________" << endl << endl;
							Sleep(3000);
							sorukac++;
							system("CLS");

						}
						else {
							if (sorukac <= 2) {
									kazanilan = 0;
									ofstream outfile("oynayanlar.txt", ios::out | ios::app);
									outfile << left << setw(30) << ad << left << setw(30) << soyad << left << setw(7) << kazanilan << " TL" << endl;										outfile.close();
									for (int a = 10; a > 0; a--) {
									system("CLS");
									cout << endl << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
									cout << "                                           YANLIS CEVAP VERDINIZ 0 TL KAZANDINIZ  ";
									cout << endl << "          _________________________________________________________________________________________________" << endl << endl << endl;
									cout << "                                     " << a << " SANIYE SONRA MENUYE YONLENDIRILECEKSINIZ.";
									Sleep(1000);
								}
								menu();

							}
							if (sorukac > 2 && sorukac <= 7) {
									kazanilan = 1000;
									ofstream outfile("oynayanlar.txt", ios::out | ios::app);
									outfile << left << setw(30) << ad << left << setw(30) << soyad << left << setw(7) << kazanilan << " TL" << endl;										outfile.close();
									for (int a = 10; a > 0; a--) {
									system("CLS");
									cout << endl << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
									cout << "                                           YANLIS CEVAP VERDINIZ 1.000 TL KAZANDINIZ  ";
									cout << endl << "          _________________________________________________________________________________________________" << endl << endl << endl;
									cout << "                                     " << a << " SANIYE SONRA MENUYE YONLENDIRILECEKSINIZ.";
									Sleep(1000);
								}
								menu();
								if (sorukac > 7) {
										kazanilan = 15000;
										ofstream outfile("oynayanlar.txt", ios::out | ios::app);
										outfile << left << setw(30) << ad << left << setw(30) << soyad << left << setw(7) << kazanilan << " TL" << endl;										outfile.close();
										for (int a = 10; a > 0; a--) {
										system("CLS");
										cout << endl << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
										cout << "                                           YANLIS CEVAP VERDINIZ 15.000 TL KAZANDINIZ  ";
									    cout << endl << "          _________________________________________________________________________________________________" << endl << endl << endl;
										cout << "                                     " << a << " SANIYE SONRA MENUYE YONLENDIRILECEKSINIZ.";
										Sleep(1000);
									}
									menu();
								}

							}
							yandimi = 1;

						}

					}
					jokerkullanilacakmi = 0;
					break;
				}
				}
			}
					
			}
			}
		
					kazanilan = 1000000;
					ofstream outfile("oynayanlar.txt", ios::out | ios::app);
					outfile << left << setw(30) << ad << left << setw(30) << soyad << left << setw(7) << kazanilan << " TL" << endl;										outfile.close();
					outfile.close();
				for (int a = 10; a > 0; a--) {
					system("CLS");
					cout << endl << endl << endl << endl << endl << endl << "          _________________________________________________________________________________________________" << endl << endl;
					cout << "                                           BUYUK ODUL 1.000.000 TL KAZANDINIZ !!  ";
					cout << endl << "          _________________________________________________________________________________________________" << endl << endl << endl;
					cout << "                                     " << a << " SANIYE SONRA MENUYE YONLENDIRILECEKSINIZ.";
					Sleep(1000);
				}

			
			
	}



void menu()
{
	int secim = 0;
	system("CLS");
	cout << "                              _________________________________________________________" << endl << endl;
	cout << "                                          KIM MILYONER OLMAK ISTER OYUNU           " << endl;
	cout << "                              _________________________________________________________" << endl << endl;
	cout << "                                                   OYUN MENUSU                          " << endl;

	cout << "                              _________________________________________________________" << endl << endl;
	cout << "                                              LUTFEN SECIMINIZI GIRINIZ            " << endl;
	cout << "                              _________________________________________________________" << endl << endl;
	cout << "                               1 -) OYUNU BASLAT" << endl;
	cout << "                               2 -) SKOR TABLOSU" << endl;
	cout << "                               3 -) YAPIMCILAR" << endl << endl << endl;
	cout << "                              _________________________________________________________" << endl << endl;
	cout << "                                                     SECIMINIZ :  ";
	cin >> secim;
	cout << endl;
	cout << "                              _________________________________________________________" << endl << endl;


	system("CLS");
	while (secim > 3 || secim < 1) {
		cout << "                              _________________________________________________________" << endl << endl;
		cout << "                                          KIM MILYONER OLMAK ISTER OYUNU              " << endl;
		cout << "                              _________________________________________________________" << endl << endl;
		cout << "                                                   OYUN MENUSU                          " << endl;

		cout << "                              _________________________________________________________" << endl << endl;
		cout << "                                              LUTFEN SECIMINIZI GIRINIZ            " << endl;
		cout << "                              _________________________________________________________" << endl << endl;
		cout << "                               1 -) OYUNU BASLAT" << endl;
			cout << "                               2 -) SKOR TABLOSU" << endl;
		cout << "                               3 -) YAPIMCILAR" << endl << endl << endl;
		cout << "                              _________________________________________________________" << endl << endl;
		cout << "                                              YANLIS BIR DEGER GIRDINIZ              " << endl;
		cout << "                              _________________________________________________________" << endl << endl;
		cout << "                              _________________________________________________________" << endl << endl;
		cout << "                                                     SECIMINIZ :  ";
		cin >> secim;
		system("CLS");
	}

	switch (secim) {

	case 1: {
		dosyadanokuma();
		break;
	}
	case 2: {
		int secim22;
		ifstream fileread;
		fileread.open("oynayanlar.txt", ios::in);
		string okunan;

		while (!fileread.eof())
		{
			getline(fileread, okunan);
			cout << okunan << "\n";
		}
		fileread.close();
		cout << endl << endl << "                              _________________________________________________________" << endl << endl;
		cout << "                                              MENUYE DONMEK ICIN 1 GIRINIZ           " << endl;
		cout << "                              _________________________________________________________" << endl << endl;
		cout << "                                                     SECIMINIZ :  ";
		cin >> secim22;
		while (secim22 != 1) {
			cout << endl << endl << "                              _________________________________________________________" << endl << endl;
			cout << "                                              YANLIS BIR DEGER GIRDINIZ          " << endl;
			cout << "                              _________________________________________________________" << endl << endl;
			cout << "                                                     SECIMINIZ :  ";
			cin >> secim22;
		}
		switch (secim22) {
		case 1:
			menu();
		}
		break;
	}
	case 3: {
		cout << "                              _________________________________________________________" << endl << endl;
		cout << "                                                     YAPANLAR           " << endl;
		cout << "                              _________________________________________________________" << endl << endl;
		cout << "                               1 -) 160101018  --  BERAT OK" << endl;
		cout << "                               2 -) 160101028  --  BAYRAM SONER SIMSEK" << endl;
		cout << "                               3 -) 160101034  --  OGUZ ARAC " << endl;
		cout << "                              _________________________________________________________" << endl << endl;
		cout << "                                               GERI DONMEK ICIN 1 GIRIN :  " << endl;
		int secim33 = 0;
		cin >> secim33;
		system("CLS");
		while (secim33 != 1) {
			cout << "                              _________________________________________________________" << endl << endl;
			cout << "                                                     YAPANLAR           " << endl;
			cout << "                              _________________________________________________________" << endl << endl;
			cout << "                               1 -) 160101018  --  BERAT OK" << endl;
			cout << "                               2 -) 160101034  --  OGUZ ARAC " << endl;
			cout << "                               3 -) 160101000  --  SONER SIMSEK" << endl;
			cout << "                              _________________________________________________________" << endl << endl;
			cout << "                                                   YANLIS DEGER GIRDINIZ" << endl;
			cout << "                              _________________________________________________________" << endl << endl;
			cout << "                                                GERI DONMEK ICIN 1 GIRINIZ : ";
			cin >> secim33;
			system("CLS");
		}

		switch (secim33)
	case 1: {
			system("CLS");
			menu();
			break; }
		
		break;
	}

	}

}

