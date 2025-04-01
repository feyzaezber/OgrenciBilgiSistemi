
#include <iostream> // Standart giriþ/çýkýþ fonksiyonlarýnýn prototiplerini içerir.
#include <string> //Standart kütüphanedeki string sýnýfýnýn tanýmlanmasýný içerir.
#include <iomanip> //Veri akýþlarýný biçimlendirme imkaný saðlayan, akýþ yönetim fonksiyonlarýnýn prototiplerini içerir.
#include <time.h> //Zamaný ve tarihi yöneten fonksiyonlarýn prototiplerini içerir.
#include <cmath> //Matematik kütüphane fonksiyonlarýnýn prototiplerini içerir.
using namespace std;
struct Ogrenci    // öðrenci structý oluþturuldu
{
	string ad;
	string soyad;
	int no;
	float kisaSinav1;
	float kisaSinav2;
	float odev1;
	float odev2;
	float proje;
	float vize;
	float final;
	int dogumTarihi;
};
struct Tarih // tarih structý oluþturuldu
{
	string gun;
	int ay;
	int yýl;
};
Ogrenci ogrenciler[100];

string ogrAdList[30] = { "feyza", "banu", "busra", "elif", "nuray", "besir", "eren", "tahsin", "muhammet",
					"kemal", "hilal", "ahu", "huma","adem", "ela", "kerem", "ali", "mustafa",
					"baris", "ayse", "mehmet", "leyla", "halit", "hazal", "gunes","ahmet", "mert", "cemal",
					"ceyda", "deniz" }; //rastgele öðrenciler için ad listesi

string ogrSoyadList[30] = { "ezber", "sayar", "cakmak", "karaman", "yilmaz", "karatas", "demir", "aktas",
						"yildirim", "pusat",  "ozturk", "enver", "duman","aksu", "onal", "coskun",
						"dogan", "mutlu", "guler", "gursoy", "keskin", "akgun","kaya", "kutluay", "ozdemir", "yakut",
						"goktepe", "aslan", "bayram", "sahin" }; // rastgele öðrenciler için soyad listesi

// yýl içi notu hesaplayan fonksiyon 
float yilIciNot(float vize, float kisaSinav1, float kisaSinav2, float odev1, float odev2, float proje)
{
	float yilIciNot;
	yilIciNot = vize * 0.5 + kisaSinav1 * 0.07 + kisaSinav2 * 0.07 + odev1 * 0.1 + odev2 * 0.2 + proje * 0.16;
	return yilIciNot;
}

float basariNotu(float yilIciNot, float final) // baþarý notunu hesaplayan fonksiyon
{
	float basariNotu;
	basariNotu = yilIciNot * 0.55 + final * 0.45;
	return basariNotu;
}

string harfNotu(float basariNotu) // baþarý notundan harf notuna geçiþ yapan fonksiyon
{
	string harfNotu;
	if (basariNotu <= 100 && basariNotu >= 90)
	{
		harfNotu = "AA";
	}
	else if (basariNotu <= 89 && basariNotu >= 85)
	{
		harfNotu = "BA";
	}
	else if (basariNotu <= 84 && basariNotu >= 80)
	{
		harfNotu = "BB";
	}
	else if (basariNotu <= 79 && basariNotu >= 75)
	{
		harfNotu = "CB";
	}
	else if (basariNotu <= 74 && basariNotu >= 70)
	{
		harfNotu = "CC";
	}
	else if (basariNotu <= 69 && basariNotu >= 65)
	{
		harfNotu = "DC";
	}
	else if (basariNotu <= 64 && basariNotu >= 60)
	{
		harfNotu = "DD";
	}
	else
	{
		cout << "Kaldi!!!";
	}
	return harfNotu;
}

double kontrol(string s, double min, double max)  //girilen not 0 ile 100 arasýnda mý deðil mi diye kontrol eden fonksiyon
{
	double sinavNotu;
	do
	{
		cout << "Sinav notu?";
		cin >> sinavNotu;
	} while (!(sinavNotu >= min && sinavNotu <= max));
	return sinavNotu;
}

void sinifListesi() // Sýnýf listesini yazdýran fonksiyon
{
     cout << "SINIF LISTESI " << endl;
	srand(time(NULL));

	float yilIciNot;
	float basariNotu;
	string harfNotu;

	for (int i = 0; i < 100; i++)
	{
		ogrenciler[i].ad = ogrAdList[rand() % 30]; // isim listesinden rastgele isim atama iþlemi
		ogrenciler[i].soyad = ogrSoyadList[rand() % 30]; // rastgele soyisim atama iþlemi
		ogrenciler[i].no = rand() % 10000; // 10000'den küçük numaralarý rastgele atama iþlemi
		if (i < 10) // Sýnýfýn yüzde 10'u 0 ile 40 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % 41;
			ogrenciler[i].kisaSinav2 = rand() % 41;
			ogrenciler[i].odev1 = rand() % 41;
			ogrenciler[i].odev2 = rand() % 41;
			ogrenciler[i].proje = rand() % 41;
			ogrenciler[i].vize = rand() % 41;
			ogrenciler[i].final = rand() % 41;
		}

		else if (i >= 10 && i < 60) // Sýnýfýn yüzde 50'si 40 ile 70 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].proje = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].vize = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].final = rand() % (70 - 40 + 1) + 40;

		}

		else if (i >= 60 && i < 75) // Sýnýfýn yüzde 15'i 70 ile 80 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].proje = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].vize = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].final = rand() % (70 - 60 + 1) + 70;

		}

		else if (i >= 75 && i < 100) // Sýnýfýn yüzde 15'i 80 ile 100 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].kisaSinav2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].proje = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].vize = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].final = rand() % (100 - 80 + 1) + 80;
		}

		yilIciNot = ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.10 + ogrenciler[i].odev2 * 0.10 + ogrenciler[i].proje * 0.16 + ogrenciler[i].vize * 0.50;
		basariNotu = ogrenciler[i].final * 0.45 + yilIciNot * 0.55;
		if (basariNotu <= 100 && basariNotu >= 90)
		{
			harfNotu = "AA";
		}
		else if (basariNotu < 90 && basariNotu >= 85)
		{
			harfNotu = "BA";
		}
		else if (basariNotu < 85 && basariNotu >= 80)
		{
			harfNotu = "BB";
		}
		else if (basariNotu < 80 && basariNotu >= 75)
		{
			harfNotu = "CB";
		}
		else if (basariNotu < 75 && basariNotu >= 70)
		{
			harfNotu = "CC";
		}
		else if (basariNotu < 70 && basariNotu >= 65)
		{
			harfNotu = "DC";
		}
		else if (basariNotu < 65 && basariNotu >= 60)
		{
			harfNotu = "DD";
		}
		else
		{
			harfNotu = "KALDI!";
		}

		cout << i + 1 << ". OGRENCININ ISMI : " << ogrenciler[i].ad << endl;
		cout << i + 1 << ". OGRENCININ SOYISMI : " << ogrenciler[i].soyad << endl;
		cout << i + 1 << ". OGRENCININ NO'SU : " << ogrenciler[i].no << endl;
		cout << i + 1 << ". OGRENCININ 1. KISA SINAV NOTU: " << ogrenciler[i].kisaSinav1 << endl;
		cout << i + 1 << ". OGRENCININ 2. KISA SINAV NOTU: " << ogrenciler[i].kisaSinav2 << endl;
		cout << i + 1 << ". OGRENCININ 1. ODEV NOTU: " << ogrenciler[i].odev1 << endl;
		cout << i + 1 << ". OGRENCININ 2. ODEV NOTU: " << ogrenciler[i].odev2 << endl;
		cout << i + 1 << ". OGRENCININ VIZE NOTU: " << ogrenciler[i].vize << endl;
		cout << i + 1 << ". OGRENCININ FINAL NOTU: " << ogrenciler[i].final << endl;
		cout << i + 1 << ". OGRENCININ YIL ICI NOTU:" << yilIciNot << endl;
		cout << i + 1 << ". OGRENCININ BASARI NOTU: " << basariNotu << endl;
		cout << i + 1 << ". OGRENCININ HARF NOTU: " << harfNotu << endl;
		cout << endl;

		if (i % 20 == 0 && i != 0)
		{
			cout << "Devam etmek icin herhangi bir tusa basiniz..." << endl;
			system("Pause");
			system("CLS");
		}
	}
}

void enYuksekFonk() // rastgele atanan notlardan en yüksek baþarý notunu bulduran fonksiyon
{
	float yilIciNot;
	float basariNotu;
	float enYuksekBasariNotu = 0;

	for (int i = 0; i < 100; i++)
	{
		if (i < 10)
		{
			ogrenciler[i].kisaSinav1 = rand() % 41;
			ogrenciler[i].kisaSinav2 = rand() % 41;
			ogrenciler[i].odev1 = rand() % 41;
			ogrenciler[i].odev2 = rand() % 41;
			ogrenciler[i].proje = rand() % 41;
			ogrenciler[i].vize = rand() % 41;
			ogrenciler[i].final = rand() % 41;
		}

		else if (i >= 10 && i < 60)
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].proje = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].vize = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].final = rand() % (70 - 40 + 1) + 40;
		}

		else if (i >= 60 && i < 75)
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].proje = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].vize = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].final = rand() % (70 - 60 + 1) + 70;
		}

		else if (i >= 75 && i < 100)
		{
			ogrenciler[i].kisaSinav1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].kisaSinav2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].proje = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].vize = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].final = rand() % (100 - 80 + 1) + 80;
		}

		yilIciNot = ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.10 + ogrenciler[i].odev2 * 0.10 + ogrenciler[i].proje * 0.16 + ogrenciler[i].vize * 0.50;
		basariNotu = ogrenciler[i].final * 0.45 + yilIciNot * 0.55;


		if (basariNotu > enYuksekBasariNotu)
		{
			enYuksekBasariNotu = basariNotu;
		}
	}
	cout << "EN YUKSEK BASARI NOTU : " << enYuksekBasariNotu << endl;
}

void enDusukFonk() // rastgele atanan notlardan en düþük baþarý notunu bulduran fonksiyon
{
	float yilIciNot;
	float basariNotu;
	float enDusukBasariNotu = 100;

	for (int i = 0; i < 100; i++)
	{
		if (i < 10)
		{
			ogrenciler[i].kisaSinav1 = rand() % 41;
			ogrenciler[i].kisaSinav2 = rand() % 41;
			ogrenciler[i].odev1 = rand() % 41;
			ogrenciler[i].odev2 = rand() % 41;
			ogrenciler[i].proje = rand() % 41;
			ogrenciler[i].vize = rand() % 41;
			ogrenciler[i].final = rand() % 41;
		}

		else if (i >= 10 && i < 60)
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].proje = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].vize = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].final = rand() % (70 - 40 + 1) + 40;
		}

		else if (i >= 60 && i < 75)
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].proje = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].vize = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].final = rand() % (70 - 60 + 1) + 70;
		}

		else if (i >= 75 && i < 100)
		{
			ogrenciler[i].kisaSinav1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].kisaSinav2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].proje = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].vize = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].final = rand() % (100 - 80 + 1) + 80;
		}

		yilIciNot = ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.10 + ogrenciler[i].odev2 * 0.10 + ogrenciler[i].proje * 0.16 + ogrenciler[i].vize * 0.50;
		basariNotu = ogrenciler[i].final * 0.45 + yilIciNot * 0.55;

		if (basariNotu < enDusukBasariNotu)
		{
			enDusukBasariNotu = basariNotu;
		}
	}
	cout << "EN DUSUK BASARI NOTU: " << enDusukBasariNotu << endl;
}

void sinifOrtalamasi() // rastgele atanan notlardan baþarý notlarýnýn ortalamasýný bulduran fonksiyon
{
	float yilIciNot;
	float basariNotu;
	float ortalama = 0;
	float toplam = 0;

	for (int i = 0; i < 100; i++)
	{
		if (i < 10)
		{
			ogrenciler[i].kisaSinav1 = rand() % 41;
			ogrenciler[i].kisaSinav2 = rand() % 41;
			ogrenciler[i].odev1 = rand() % 41;
			ogrenciler[i].odev2 = rand() % 41;
			ogrenciler[i].proje = rand() % 41;
			ogrenciler[i].vize = rand() % 41;
			ogrenciler[i].final = rand() % 41;
		}

		else if (i >= 10 && i < 60)
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].proje = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].vize = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].final = rand() % (70 - 40 + 1) + 40;
		}

		else if (i >= 60 && i < 75)
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].proje = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].vize = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].final = rand() % (70 - 60 + 1) + 70;
		}

		else if (i >= 75 && i < 100)
		{
			ogrenciler[i].kisaSinav1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].kisaSinav2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].proje = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].vize = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].final = rand() % (100 - 80 + 1) + 80;
		}

		yilIciNot = ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.10 + ogrenciler[i].odev2 * 0.10 + ogrenciler[i].proje * 0.16 + ogrenciler[i].vize * 0.50;
		basariNotu = ogrenciler[i].final * 0.45 + yilIciNot * 0.55;

		toplam = toplam + basariNotu;
		ortalama = toplam / 100;
	}
	cout << "SINIF ORTALAMASI : " << ortalama << endl;
}

void standartSapma() // rastgele olan baþarý notlarýnýn standart sapmasýný hesaplayan fonksiyon
{
	float yilIciNot;
	float basariNotu;
	float ortalama = 0;
	float toplam = 0;
	float standartSapma;

	for (int i = 0; i < 100; i++)
	{
		if (i < 10)
		{
			ogrenciler[i].kisaSinav1 = rand() % 41;
			ogrenciler[i].kisaSinav2 = rand() % 41;
			ogrenciler[i].odev1 = rand() % 41;
			ogrenciler[i].odev2 = rand() % 41;
			ogrenciler[i].proje = rand() % 41;
			ogrenciler[i].vize = rand() % 41;
			ogrenciler[i].final = rand() % 41;
		}

		else if (i >= 10 && i < 60)
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].proje = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].vize = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].final = rand() % (70 - 40 + 1) + 40;
		}

		else if (i >= 60 && i < 75)
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].proje = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].vize = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].final = rand() % (70 - 60 + 1) + 70;
		}

		else if (i >= 75 && i < 100)
		{
			ogrenciler[i].kisaSinav1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].kisaSinav2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].proje = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].vize = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].final = rand() % (100 - 80 + 1) + 80;
		}

		yilIciNot = ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.10 + ogrenciler[i].odev2 * 0.10 + ogrenciler[i].proje * 0.16 + ogrenciler[i].vize * 0.50;
		basariNotu = ogrenciler[i].final * 0.45 + yilIciNot * 0.55;

		toplam = toplam + basariNotu;
		ortalama = toplam / 100;
		standartSapma = sqrt((pow((ortalama - basariNotu), 2)) / 6);
	}
	cout << "BASARI NOTLARININ STANDART SAPMASI : " << standartSapma << endl;
}

void degerAraligi()
{
	float yilIciNot;
	float basariNotu;
	float altDeger;
	float ustDeger;


	cout << "Alt degeri giriniz: ";
	cin >> altDeger;
	cout << "Ust degeri giriniz:";
	cin >> ustDeger;
	cout << endl;

	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		ogrenciler[i].ad = ogrAdList[rand() % 30]; // isim listesinden rastgele isim atama iþlemi
		ogrenciler[i].soyad = ogrSoyadList[rand() % 30]; // rastgele soyisim atama iþlemi
		ogrenciler[i].no = rand() % 10000; // 10000'den küçük numaralarý rastgele atama iþlemi
		if (i < 10) // Sýnýfýn yüzde 10'u 0 ile 40 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % 41;
			ogrenciler[i].kisaSinav2 = rand() % 41;
			ogrenciler[i].odev1 = rand() % 41;
			ogrenciler[i].odev2 = rand() % 41;
			ogrenciler[i].proje = rand() % 41;
			ogrenciler[i].vize = rand() % 41;
			ogrenciler[i].final = rand() % 41;
		}

		else if (i >= 10 && i < 60) // Sýnýfýn yüzde 50'si 40 ile 70 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].proje = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].vize = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].final = rand() % (70 - 40 + 1) + 40;

		}

		else if (i >= 60 && i < 75) // Sýnýfýn yüzde 15'i 70 ile 80 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].proje = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].vize = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].final = rand() % (70 - 60 + 1) + 70;

		}

		else if (i >= 75 && i < 100) // Sýnýfýn yüzde 15'i 80 ile 100 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].kisaSinav2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].proje = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].vize = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].final = rand() % (100 - 80 + 1) + 80;
		}

		yilIciNot = ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.10 + ogrenciler[i].odev2 * 0.10 + ogrenciler[i].proje * 0.16 + ogrenciler[i].vize * 0.50;
		basariNotu = ogrenciler[i].final * 0.45 + yilIciNot * 0.55;

		if (basariNotu > altDeger && basariNotu < ustDeger)
		{
			cout << "OGRENCININ ISMI : " << ogrenciler[i].ad << endl;
			cout << "OGRENCININ SOYISMI : " << ogrenciler[i].soyad << endl;
			cout << "OGRENCININ NO'SU : " << ogrenciler[i].no << endl;
			cout << "OGRENCININ BASARI NOTU: " << basariNotu << endl;
			cout << endl;
		}
	}
}
void degerinAlti()
{
	float yilIciNot;
	float basariNotu;
	float ustDeger2;

	cout << "Ust degeri giriniz:";
	cin >> ustDeger2;
	cout << endl;

	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		ogrenciler[i].ad = ogrAdList[rand() % 30]; // isim listesinden rastgele isim atama iþlemi
		ogrenciler[i].soyad = ogrSoyadList[rand() % 30]; // rastgele soyisim atama iþlemi
		ogrenciler[i].no = rand() % 10000; // 10000'den küçük numaralarý rastgele atama iþlemi
		if (i < 10) // Sýnýfýn yüzde 10'u 0 ile 40 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % 41;
			ogrenciler[i].kisaSinav2 = rand() % 41;
			ogrenciler[i].odev1 = rand() % 41;
			ogrenciler[i].odev2 = rand() % 41;
			ogrenciler[i].proje = rand() % 41;
			ogrenciler[i].vize = rand() % 41;
			ogrenciler[i].final = rand() % 41;
		}

		else if (i >= 10 && i < 60) // Sýnýfýn yüzde 50'si 40 ile 70 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].proje = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].vize = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].final = rand() % (70 - 40 + 1) + 40;

		}

		else if (i >= 60 && i < 75) // Sýnýfýn yüzde 15'i 70 ile 80 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].proje = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].vize = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].final = rand() % (70 - 60 + 1) + 70;

		}

		else if (i >= 75 && i < 100) // Sýnýfýn yüzde 15'i 80 ile 100 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].kisaSinav2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].proje = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].vize = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].final = rand() % (100 - 80 + 1) + 80;
		}

		yilIciNot = ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.10 + ogrenciler[i].odev2 * 0.10 + ogrenciler[i].proje * 0.16 + ogrenciler[i].vize * 0.50;
		basariNotu = ogrenciler[i].final * 0.45 + yilIciNot * 0.55;

		if (basariNotu < ustDeger2)
		{
			cout << "OGRENCININ ISMI : " << ogrenciler[i].ad << endl;
			cout << "OGRENCININ SOYISMI : " << ogrenciler[i].soyad << endl;
			cout << "OGRENCININ NO'SU : " << ogrenciler[i].no << endl;
			cout << "OGRENCININ BASARI NOTU: " << basariNotu << endl;
			cout << endl;
		}
	}
}
void degerinUstu()
{
	float yilIciNot;
	float basariNotu;
	float altDeger2;

	cout << "Alt degeri giriniz:";
	cin >> altDeger2;
	cout << endl;

	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		ogrenciler[i].ad = ogrAdList[rand() % 30]; // isim listesinden rastgele isim atama iþlemi
		ogrenciler[i].soyad = ogrSoyadList[rand() % 30]; // rastgele soyisim atama iþlemi
		ogrenciler[i].no = rand() % 10000; // 10000'den küçük numaralarý rastgele atama iþlemi
		if (i < 10) // Sýnýfýn yüzde 10'u 0 ile 40 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % 41;
			ogrenciler[i].kisaSinav2 = rand() % 41;
			ogrenciler[i].odev1 = rand() % 41;
			ogrenciler[i].odev2 = rand() % 41;
			ogrenciler[i].proje = rand() % 41;
			ogrenciler[i].vize = rand() % 41;
			ogrenciler[i].final = rand() % 41;
		}

		else if (i >= 10 && i < 60) // Sýnýfýn yüzde 50'si 40 ile 70 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev1 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].odev2 = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].proje = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].vize = rand() % (70 - 40 + 1) + 40;
			ogrenciler[i].final = rand() % (70 - 40 + 1) + 40;

		}

		else if (i >= 60 && i < 75) // Sýnýfýn yüzde 15'i 70 ile 80 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].kisaSinav2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev1 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].odev2 = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].proje = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].vize = rand() % (70 - 60 + 1) + 70;
			ogrenciler[i].final = rand() % (70 - 60 + 1) + 70;

		}

		else if (i >= 75 && i < 100) // Sýnýfýn yüzde 15'i 80 ile 100 arasýnda not alacak
		{
			ogrenciler[i].kisaSinav1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].kisaSinav2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev1 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].odev2 = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].proje = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].vize = rand() % (100 - 80 + 1) + 80;
			ogrenciler[i].final = rand() % (100 - 80 + 1) + 80;
		}

		yilIciNot = ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.10 + ogrenciler[i].odev2 * 0.10 + ogrenciler[i].proje * 0.16 + ogrenciler[i].vize * 0.50;
		basariNotu = ogrenciler[i].final * 0.45 + yilIciNot * 0.55;

		if (basariNotu > altDeger2)
		{
			cout << "OGRENCININ ISMI : " << ogrenciler[i].ad << endl;
			cout << "OGRENCININ SOYISMI : " << ogrenciler[i].soyad << endl;
			cout << "OGRENCININ NO'SU : " << ogrenciler[i].no << endl;
			cout << "OGRENCININ BASARI NOTU: " << basariNotu << endl;
			cout << endl;
		}
	}
}
void sinifListesi2()
{
	int n;
	string ogrAd;
	string ogrSoyad;
	int ogrNo;
	float kisaSinav1;
	float kisaSinav2;
	float odev1;
	float odev2;
	float proje{};
	float vize;
	float final;
	float yilIciNot;
	float basariNotu;
	string harfNotu2;

	cout << "Kac ogrenci gireceksiniz?";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". Ogrencinin adi: ";
		cin >> ogrAd;
		cout << i + 1 << ". Ogrencinin Soyadi: ";
		cin >> ogrSoyad;
		cout << i + 1 << ". Ogrencinin No'su: ";
		cin >> ogrNo;
		cout << i + 1 << ". Ogrencinin 1. Kisa Sinav Notu: ";
		cin >> kisaSinav1;
		cout << i + 1 << ". Ogrencinin 2. Kisa Sinav Notu: ";
		cin >> kisaSinav2;
		cout << i + 1 << ". Ogrencinin 1. Odev Notu: ";
		cin >> odev1;
		cout << i + 1 << ". Ogrencinin 2. Odev Notu: ";
		cin >> odev2;
		cout << i + 1 << ". Ogrencinin Vize Notu: ";
		cin >> vize;
		cout << i + 1 << ". Ogrencinin Final Notu: ";
		cin >> final;

		yilIciNot = kisaSinav1 * 0.07 + kisaSinav2 * 0.07 + odev1 * 0.10 + odev2 * 0.10 + proje * 0.16 + vize * 0.55;
		basariNotu = yilIciNot * 0.55 + final * 0.45;

		if (basariNotu <= 100 && basariNotu >= 90)
		{
			harfNotu2 = "AA";
		}
		else if (basariNotu < 90 && basariNotu >= 85)
		{
			harfNotu2 = "BA";
		}
		else if (basariNotu < 85 && basariNotu >= 80)
		{
			harfNotu2 = "BB";
		}
		else if (basariNotu < 80 && basariNotu >= 75)
		{
			harfNotu2 = "CB";
		}
		else if (basariNotu < 75 && basariNotu >= 70)
		{
			harfNotu2 = "CC";
		}
		else if (basariNotu < 70 && basariNotu >= 65)
		{
			harfNotu2 = "DC";
		}
		else if (basariNotu < 65 && basariNotu >= 60)
		{
			harfNotu2 = "DD";
		}
		else
		{
			harfNotu2 = "KALDI!";
		}

		cout << i + 1 << ". Ogrencinin YIL ICI NOTU :" << yilIciNot << endl;
		cout << i + 1 << ". Ogrencinin BASARI NOTU : " << basariNotu << endl;
		cout << i + 1 << ". Ogrencinin HARF NOTU : " << harfNotu2 << endl;
		cout << endl;
	}
}
void enYuksek2() // kullanýcýnýn girdiði notlardan en yüksek baþarý notunu bulduran fonksiyon
{
	float kisaSinav1;
	float kisaSinav2;
	float odev1;
	float odev2;
	float proje{};
	float vize;
	float final;
	float yilIciNot;
	float basariNotu;
	float enYuksekBasariNotu2 = 0;
	int n;

	cout << "Kac ogrenci gireceksiniz?";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". Ogrencinin 1. Kisa Sinav Notu: ";
		cin >> kisaSinav1;
		cout << i + 1 << ". Ogrencinin 2. Kisa Sinav Notu: ";
		cin >> kisaSinav2;
		cout << i + 1 << ". Ogrencinin 1. Odev Notu: ";
		cin >> odev1;
		cout << i + 1 << ". Ogrencinin 2. Odev Notu: ";
		cin >> odev2;
		cout << i + 1 << ". Ogrencinin Vize Notu: ";
		cin >> vize;
		cout << i + 1 << ". Ogrencinin Final Notu: ";
		cin >> final;
		cout << endl;

		yilIciNot = kisaSinav1 * 0.07 + kisaSinav2 * 0.07 + odev1 * 0.10 + odev2 * 0.10 + proje * 0.16 + vize * 0.55;
		basariNotu = yilIciNot * 0.55 + final * 0.45;

		if (basariNotu > enYuksekBasariNotu2)
		{
			enYuksekBasariNotu2 = basariNotu;
		}
	}
	cout << "GIRILEN EN YUKSEK BASARI NOTU : " << enYuksekBasariNotu2 << endl;
}
void enDusuk2() // kullanýcýnýn girdiði notlardan en düþük baþarý notunu bulduran fonksiyon
{
	float kisaSinav1;
	float kisaSinav2;
	float odev1;
	float odev2;
	float proje{};
	float vize;
	float final;
	float yilIciNot;
	float basariNotu;
	float enDusukBasariNotu2 = 100;
	int n;

	cout << "Kac ogrenci gireceksiniz?";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". Ogrencinin 1. Kisa Sinav Notu: ";
		cin >> kisaSinav1;
		cout << i + 1 << ". Ogrencinin 2. Kisa Sinav Notu: ";
		cin >> kisaSinav2;
		cout << i + 1 << ". Ogrencinin 1. Odev Notu: ";
		cin >> odev1;
		cout << i + 1 << ". Ogrencinin 2. Odev Notu: ";
		cin >> odev2;
		cout << i + 1 << ". Ogrencinin Vize Notu: ";
		cin >> vize;
		cout << i + 1 << ". Ogrencinin Final Notu: ";
		cin >> final;
		cout << endl;

		yilIciNot = kisaSinav1 * 0.07 + kisaSinav2 * 0.07 + odev1 * 0.10 + odev2 * 0.10 + proje * 0.16 + vize * 0.55;
		basariNotu = yilIciNot * 0.55 + final * 0.45;

		if (basariNotu < enDusukBasariNotu2)
		{
			enDusukBasariNotu2 = basariNotu;
		}
	}
	cout << "GIRILEN EN DUSUK BASARI NOTU : " << enDusukBasariNotu2 << endl;
}
void ortalama2() // kullanýcýnýn girdiði notlardan baþarý notlarýnýn ortalamasýný bulduran fonksiyon
{
	float kisaSinav1;
	float kisaSinav2;
	float odev1;
	float odev2;
	float proje{};
	float vize;
	float final;
	float yilIciNot;
	float basariNotu;
	float toplam = 0;
	float ortalama = 0;
	int n;

	cout << "Kac ogrenci gireceksiniz?";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". Ogrencinin 1. Kisa Sinav Notu: ";
		cin >> kisaSinav1;
		cout << i + 1 << ". Ogrencinin 2. Kisa Sinav Notu: ";
		cin >> kisaSinav2;
		cout << i + 1 << ". Ogrencinin 1. Odev Notu: ";
		cin >> odev1;
		cout << i + 1 << ". Ogrencinin 2. Odev Notu: ";
		cin >> odev2;
		cout << i + 1 << ". Ogrencinin Vize Notu: ";
		cin >> vize;
		cout << i + 1 << ". Ogrencinin Final Notu: ";
		cin >> final;
		cout << endl;

		yilIciNot = kisaSinav1 * 0.07 + kisaSinav2 * 0.07 + odev1 * 0.10 + odev2 * 0.10 + proje * 0.16 + vize * 0.55;
		basariNotu = yilIciNot * 0.55 + final * 0.45;

		toplam = toplam + basariNotu;
		ortalama = toplam / n;
	}
	cout << "GIRILEN NOTLARIN ORTALAMASI : " << ortalama << endl;
}
void standartSapma2() // kullanýcýnýn girdiði notlardan baþarý notlarýnýn standart sapmasýný hesaplayan fonksiyon
{
	float kisaSinav1;
	float kisaSinav2;
	float odev1;
	float odev2;
	float proje{};
	float vize;
	float final;
	float yilIciNot;
	float basariNotu;
	float toplam = 0;
	float ortalama = 0;
	int n;
	float standartSapma;

	cout << "Kac ogrenci gireceksiniz?";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". Ogrencinin 1. Kisa Sinav Notu: ";
		cin >> kisaSinav1;
		cout << i + 1 << ". Ogrencinin 2. Kisa Sinav Notu: ";
		cin >> kisaSinav2;
		cout << i + 1 << ". Ogrencinin 1. Odev Notu: ";
		cin >> odev1;
		cout << i + 1 << ". Ogrencinin 2. Odev Notu: ";
		cin >> odev2;
		cout << i + 1 << ". Ogrencinin Vize Notu: ";
		cin >> vize;
		cout << i + 1 << ". Ogrencinin Final Notu: ";
		cin >> final;
		cout << endl;

		yilIciNot = kisaSinav1 * 0.07 + kisaSinav2 * 0.07 + odev1 * 0.10 + odev2 * 0.10 + proje * 0.16 + vize * 0.55;
		basariNotu = yilIciNot * 0.55 + final * 0.45;

		toplam = toplam + basariNotu;
		ortalama = toplam / n;
		standartSapma = sqrt((pow((ortalama - basariNotu), 2)) / 6);
	}
	cout << "BASARI NOTLARININ STANDART SAPMASI : " << standartSapma << endl;
}
void degerAraligi2()
{
	int n;
	string ogrAd;
	string ogrSoyad;
	int ogrNo;
	float kisaSinav1;
	float kisaSinav2;
	float odev1;
	float odev2;
	float proje{};
	float vize;
	float final;
	float yilIciNot;
	float basariNotu;
	float ustDeger3;
	float altDeger3;

	cout << "Alt degeri giriniz: ";
	cin >> altDeger3;
	cout << "Ust degeri giriniz: ";
	cin >> ustDeger3;
	cout << "Kac ogrenci gireceksiniz?";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". Ogrencinin adi: ";
		cin >> ogrAd;
		cout << i + 1 << ". Ogrencinin Soyadi: ";
		cin >> ogrSoyad;
		cout << i + 1 << ". Ogrencinin No'su: ";
		cin >> ogrNo;
		cout << i + 1 << ". Ogrencinin 1. Kisa Sinav Notu: ";
		cin >> kisaSinav1;
		cout << i + 1 << ". Ogrencinin 2. Kisa Sinav Notu: ";
		cin >> kisaSinav2;
		cout << i + 1 << ". Ogrencinin 1. Odev Notu: ";
		cin >> odev1;
		cout << i + 1 << ". Ogrencinin 2. Odev Notu: ";
		cin >> odev2;
		cout << i + 1 << ". Ogrencinin Vize Notu: ";
		cin >> vize;
		cout << i + 1 << ". Ogrencinin Final Notu: ";
		cin >> final;

		yilIciNot = kisaSinav1 * 0.07 + kisaSinav2 * 0.07 + odev1 * 0.10 + odev2 * 0.10 + proje * 0.16 + vize * 0.55;
		basariNotu = yilIciNot * 0.55 + final * 0.45;

		cout << i + 1 << ". Ogrencinin BASARI NOTU : " << basariNotu << endl;
		cout << endl;

		if (basariNotu > altDeger3 && basariNotu < ustDeger3)
		{
			cout << "ISIM :" << ogrAd << "  " << "SOYISIM :" << ogrSoyad << "  " << "NO :" << ogrNo << "  " << "BASARI NOTU:" << basariNotu;
		}
	}
}
void degerinAlti2()
{
	int n;
	string ogrAd;
	string ogrSoyad;
	int ogrNo;
	float kisaSinav1;
	float kisaSinav2;
	float odev1;
	float odev2;
	float proje{};
	float vize;
	float final;
	float yilIciNot;
	float basariNotu;
	float ustDeger4;

	cout << "Ust degeri giriniz: ";
	cin >> ustDeger4;
	cout << "Kac ogrenci gireceksiniz?";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". Ogrencinin adi: ";
		cin >> ogrAd;
		cout << i + 1 << ". Ogrencinin Soyadi: ";
		cin >> ogrSoyad;
		cout << i + 1 << ". Ogrencinin No'su: ";
		cin >> ogrNo;
		cout << i + 1 << ". Ogrencinin 1. Kisa Sinav Notu: ";
		cin >> kisaSinav1;
		cout << i + 1 << ". Ogrencinin 2. Kisa Sinav Notu: ";
		cin >> kisaSinav2;
		cout << i + 1 << ". Ogrencinin 1. Odev Notu: ";
		cin >> odev1;
		cout << i + 1 << ". Ogrencinin 2. Odev Notu: ";
		cin >> odev2;
		cout << i + 1 << ". Ogrencinin Vize Notu: ";
		cin >> vize;
		cout << i + 1 << ". Ogrencinin Final Notu: ";
		cin >> final;

		yilIciNot = kisaSinav1 * 0.07 + kisaSinav2 * 0.07 + odev1 * 0.10 + odev2 * 0.10 + proje * 0.16 + vize * 0.55;
		basariNotu = yilIciNot * 0.55 + final * 0.45;

		cout << i + 1 << ". Ogrencinin BASARI NOTU : " << basariNotu << endl;
		cout << endl;

		if (basariNotu < ustDeger4)
		{
			cout << "ISIM :" << ogrAd << "  " << "SOYISIM :" << ogrSoyad << "  " << "NO :" << ogrNo << "  " << "BASARI NOTU: " << basariNotu;
		}
	}
}
void degerinUstu2()
{
	int n;
	string ogrAd;
	string ogrSoyad;
	int ogrNo;
	float kisaSinav1;
	float kisaSinav2;
	float odev1;
	float odev2;
	float proje{};
	float vize;
	float final;
	float yilIciNot;
	float basariNotu;
	float altDeger4;

	cout << "Alt degeri giriniz: ";
	cin >> altDeger4;
	cout << "Kac ogrenci gireceksiniz?";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". Ogrencinin adi: ";
		cin >> ogrAd;
		cout << i + 1 << ". Ogrencinin Soyadi: ";
		cin >> ogrSoyad;
		cout << i + 1 << ". Ogrencinin No'su: ";
		cin >> ogrNo;
		cout << i + 1 << ". Ogrencinin 1. Kisa Sinav Notu: ";
		cin >> kisaSinav1;
		cout << i + 1 << ". Ogrencinin 2. Kisa Sinav Notu: ";
		cin >> kisaSinav2;
		cout << i + 1 << ". Ogrencinin 1. Odev Notu: ";
		cin >> odev1;
		cout << i + 1 << ". Ogrencinin 2. Odev Notu: ";
		cin >> odev2;
		cout << i + 1 << ". Ogrencinin Vize Notu: ";
		cin >> vize;
		cout << i + 1 << ". Ogrencinin Final Notu: ";
		cin >> final;

		yilIciNot = kisaSinav1 * 0.07 + kisaSinav2 * 0.07 + odev1 * 0.10 + odev2 * 0.10 + proje * 0.16 + vize * 0.55;
		basariNotu = yilIciNot * 0.55 + final * 0.45;

		cout << i + 1 << ". Ogrencinin BASARI NOTU : " << basariNotu << endl;
		cout << endl;

		if (basariNotu > altDeger4)
		{
			cout << "ISIM :" << ogrAd << "  " << "SOYISIM :" << ogrSoyad << "  " << "NO :" << ogrNo << "  " << "BASARI NOTU: " << basariNotu;
		}
	}
}

int main()
{
	int secim1;
	int secim2;
	int secim3;
	int n;

	cout << "Ogrencilerin rastgele girilmesini istiyorsaniz 1'e basin." << endl;
	cout << "Ogrencileri kendiniz girmek istiyorsaniz 2'ye basin." << endl;
	cin >> secim1;
	cout << endl;
	switch (secim1)
	{
	case 1:

		cout << "Sinif listesini yazdirmak icin 1'e basiniz." << endl;
		cout << "Sinifin en yuksek notunu yazdirmak icin 2'ye basiniz." << endl;
		cout << "Sinifin en dusuk notunu yazdirmak icin 3'e basiniz." << endl;
		cout << "Sinifin ortalamasini hesaplamak icin 4'e basiniz." << endl;
		cout << "Sinifin standart sapmasini hesaplamak icin 5'e basiniz." << endl;
		cout << "Basari notu belirli bir araliktaki ogrencileri yazdirmak icin 6'ya basiniz." << endl;
		cout << "Basari notu belirli bir degerin altindaki ogrencileri yazdirmak icin 7'ye basiniz." << endl;
		cout << "Basari notu belirli bir degerin ustundeki ogrencileri yazdirmak icin 8'e basiniz. ";

		cin >> secim2;

		if (secim2 == 1)
		{
			sinifListesi();
		}
		else if (secim2 == 2)
		{
			enYuksekFonk();
		}
		else if (secim2 == 3)
		{
			enDusukFonk();
		}
		else if (secim2 == 4)
		{
			sinifOrtalamasi();
		}
		else if (secim2 == 5)
		{
			standartSapma();
		}
		else if (secim2 == 6)
		{
			degerAraligi();
		}
		else if (secim2 == 7)
		{
			degerinAlti();
		}
		else if (secim2 == 8)
		{
			degerinUstu();
		}
		break;

	case 2:

		cout << "Sinif listesini girmek icin 1'e basiniz." << endl;
		cout << "Sinifin en yuksek notunu yazdirmak icin 2'ye basiniz." << endl;
		cout << "Sinifin en dusuk notunu yazdirmak icin 3'e basiniz." << endl;
		cout << "Sinifin ortalamasini hesaplamak icin 4'e basiniz." << endl;
		cout << "Sinifin standart sapmasini hesaplamak icin 5'e basiniz." << endl;
		cout << "Basari notu belirli bir araliktaki ogrencileri yazdirmak icin 6'ya basiniz." << endl;
		cout << "Basari notu belirli bir degerin altindaki ogrencileri yazdirmak icin 7'ye basiniz." << endl;
		cout << "Basari notu belirli bir degerin ustundeki ogrencileri yazdirmak icin 8'e basiniz. ";
		cin >> secim3;

		if (secim3 == 1)
		{
			sinifListesi2();
		}
		else if (secim3 == 2)
		{
			enYuksek2();
		}
		else if (secim3 == 3)
		{
			enDusuk2();
		}
		else if (secim3 == 4)
		{
			ortalama2();
		}
		else if (secim3 == 5)
		{
			standartSapma2();
		}
		else if (secim3 == 6)
		{
			degerAraligi2();
		}
		else if (secim3 == 7)
		{
			degerinAlti2();
		}
		else if (secim3 == 8)
		{
			degerinUstu2();
		}
	}
	return 0;
}