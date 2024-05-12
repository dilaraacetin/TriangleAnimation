/***************************************************************************************************************************************************************************
**
**                                                           ÖĞRENCİ ADI: Dilara Çetin
**                                                           ÖĞRENCİ NUMARASI: G221210039
**                                                           DERS GRUBU:A Grubu
****************************************************************************************************************************************************************************/

#include<iostream>
#include<iomanip>


const int UcgenSayisi = 20; //Dizideki üçgen sayısı

struct Ucgen // Struct üçgen yapısı
{
    int Yukseklik;
    char Karakter;
};
Ucgen Ucgenler[UcgenSayisi]; //Üçgenlerin tutlacağı dizi

using namespace std;

int main()
{

    char Secenek; //Kullanıcıdan aldığımız karakterler

    setlocale(LC_ALL, "Turkish");

    for (int i = 0; i < UcgenSayisi; i++) { //Diziyi boş hale getirir
        Ucgenler[i].Yukseklik = 0;
        Ucgenler[i].Karakter = ' ';
    }
    if (Ucgenler[0].Yukseklik == 0) { //Dizinin boş olup olmadığını kontrol edip buna göre dizi boş ifadesini yazdırır
        cout << setw(36) << "****************" << endl;
        cout << setw(22) << "**" << setw(10) << "Dizi boş" << setw(4) << "**" << endl;
    }



    int sayac1 = 0; // d tuşu için sayaç
    int sayac2 = 0; // s tuşu için sayaç
    int sayac3 = 0; // w tulu için sayaç

    cin >> Secenek;

    while (Secenek != 'q' && Secenek != 'Q') { // Kullanıcı q değerini girmediği sürece devam eder

        system("cls");

        if (Secenek == 'd' || Secenek == 'D') { // Kullanıcı d seçmesi durumu

            if (sayac1 + sayac2 + sayac3 != sayac1) { // Kullanıcının seçtiği yere üçgen eklemesi durumu

                if (sayac1 + sayac2 + sayac3 < 0) {

                    for (int i = UcgenSayisi - 1; i > 2 * sayac1 + sayac2 + sayac3 - 1; i--) { //Kullanıcının seçtiği bölmenin üstündeki üçgenlerin verilerinin aktarılması
                        if (Ucgenler[i].Yukseklik != 0) {
                            Ucgenler[i + 1].Yukseklik = Ucgenler[i].Yukseklik;
                            Ucgenler[i + 1].Karakter = Ucgenler[i].Karakter;
                        }
                    }

                    Ucgenler[2 * sayac1 + sayac2 + sayac3].Yukseklik = 0; // Seçilen üçgenin yüksekliğine sıfır değeri atanması

                    for (int i = UcgenSayisi; i > 2 * sayac1 + sayac2 + sayac3; i--) { // Seçilen üçgenin üstündeki üçgenlerin bilgisinin yazdırılması
                        if (Ucgenler[i].Yukseklik != 0) {
                            cout << setw(36) << "****************" << endl;
                            cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                        }
                    }
                    int randomYukseklik = rand() % 8 + 3;  //Seçilen bölmeye random değerlerle yeni bir üçgen atanması
                    char randomKarakter[] = { '$', '-', '+', 'x' };
                    char randomKrktr = randomKarakter[rand() % 3];
                    if (Ucgenler[2 * sayac1 + sayac2 + sayac3].Yukseklik == 0) {
                        Ucgenler[2 * sayac1 + sayac2 + sayac3].Yukseklik = randomYukseklik;
                        Ucgenler[2 * sayac1 + sayac2 + sayac3].Karakter = randomKrktr;
                    }
                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "-----> **" << setw(6) << Ucgenler[2 * sayac1 + sayac2 + sayac3].Yukseklik << setw(3) << Ucgenler[2 * sayac1 + sayac2 + sayac3].Karakter << setw(5) << "**" << endl;

                    for (int i = 2 * sayac1 + sayac2 + sayac3 - 1; i > -1; i--) { //Seçilen üçgenin altındaki üçgenlerin bilgisini yazdırma işlemleri
                        if (Ucgenler[i].Yukseklik != 0) {
                            cout << setw(36) << "****************" << endl;
                            cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                        }
                    }
                    int Yksklk = Ucgenler[2 * sayac1 + sayac2 + sayac3].Yukseklik; //Seçilen üçgenin şekil olarak yazdırılması
                    char Krktr = Ucgenler[2 * sayac1 + sayac2 + sayac3].Karakter;

                    for (int Genislik = 1; Genislik <= Yksklk; Genislik++) {
                        for (int Boşluk = 0; Boşluk < Yksklk - Genislik; Boşluk++) {
                            cout << " ";
                        }
                        if (Genislik == 1 || Genislik == Yksklk) {
                            for (int charCount = 1; charCount <= 2 * Genislik - 1; charCount++) {
                                cout << Krktr;
                            }
                        }
                        else {
                            cout << Krktr;
                            for (int Boşluk = 0; Boşluk < 2 * Genislik - 3; Boşluk++) {
                                cout << " ";
                            }
                            cout << Krktr;
                        }
                        cout << endl;
                    }
                }

                else if (sayac1 + sayac2 + sayac3 > sayac1) {
                    for (int i = UcgenSayisi - 1; i > sayac2 + sayac3 - 1; i--) { //Kullanıcının seçtiği bölmenin üstündeki üçgenlerin verilerinin aktarılması
                        if (Ucgenler[i].Yukseklik != 0) {
                            Ucgenler[i + 1].Yukseklik = Ucgenler[i].Yukseklik;
                            Ucgenler[i + 1].Karakter = Ucgenler[i].Karakter;
                        }
                    }
                    Ucgenler[sayac2 + sayac3].Yukseklik = 0; // Seçilen üçgenin yüksekliğine sıfır değeri atanması

                    for (int i = UcgenSayisi; i > sayac2 + sayac3; i--) { // Seçilen üçgenin üstündeki üçgenlerin bilgisinin yazdırılması
                        if (Ucgenler[i].Yukseklik != 0) {
                            cout << setw(36) << "****************" << endl;
                            cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                        }
                    }
                    int randomYukseklik = rand() % 8 + 3;  //Seçilen bölmeye random değerlerle yeni bir üçgen atanması
                    char randomKarakter[] = { '$', '-', '+', 'x' };
                    char randomKrktr = randomKarakter[rand() % 3];
                    if (Ucgenler[sayac2 + sayac3].Yukseklik == 0) {
                        Ucgenler[sayac2 + sayac3].Yukseklik = randomYukseklik;
                        Ucgenler[sayac2 + sayac3].Karakter = randomKrktr;
                    }
                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "-----> **" << setw(6) << Ucgenler[sayac2 + sayac3].Yukseklik << setw(3) << Ucgenler[sayac2 + sayac3].Karakter << setw(5) << "**" << endl;

                    for (int i = sayac2 + sayac3 - 1; i > -1; i--) { //Seçilen üçgenin altındaki üçgenlerin bilgisini yazdırma işlemleri
                        if (Ucgenler[i].Yukseklik != 0) {
                            cout << setw(36) << "****************" << endl;
                            cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                        }
                    }
                    int Yksklk = Ucgenler[sayac2 + sayac3].Yukseklik; //Seçilen üçgenin şekil olarak yazdırılması
                    char Krktr = Ucgenler[sayac2 + sayac3].Karakter;

                    for (int Genislik = 1; Genislik <= Yksklk; Genislik++) {
                        for (int Boşluk = 0; Boşluk < Yksklk - Genislik; Boşluk++) {
                            cout << " ";
                        }
                        if (Genislik == 1 || Genislik == Yksklk) {
                            for (int charCount = 1; charCount <= 2 * Genislik - 1; charCount++) {
                                cout << Krktr;
                            }
                        }
                        else {
                            cout << Krktr;
                            for (int Boşluk = 0; Boşluk < 2 * Genislik - 3; Boşluk++) {
                                cout << " ";
                            }
                            cout << Krktr;
                        }
                        cout << endl;
                    }
                }
                else {
                    for (int i = UcgenSayisi - 1; i > sayac1 + sayac2 + sayac3 - 1; i--) { //Kullanıcının seçtiği bölmenin üstündeki üçgenlerin verilerinin aktarılması
                        if (Ucgenler[i].Yukseklik != 0) {
                            Ucgenler[i + 1].Yukseklik = Ucgenler[i].Yukseklik;
                            Ucgenler[i + 1].Karakter = Ucgenler[i].Karakter;
                        }
                    }
                    Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik = 0; // Seçilen üçgenin yüksekliğine sıfır değeri atanması

                    for (int i = UcgenSayisi; i > sayac1 + sayac2 + sayac3; i--) { // Seçilen üçgenin üstündeki üçgenlerin bilgisinin yazdırılması
                        if (Ucgenler[i].Yukseklik != 0) {
                            cout << setw(36) << "****************" << endl;
                            cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                        }
                    }
                    int randomYukseklik = rand() % 8 + 3;  //Seçilen bölmeye random değerlerle yeni bir üçgen atanması
                    char randomKarakter[] = { '$', '-', '+', 'x' };
                    char randomKrktr = randomKarakter[rand() % 3];
                    if (Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik == 0) {
                        Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik = randomYukseklik;
                        Ucgenler[sayac1 + sayac2 + sayac3].Karakter = randomKrktr;
                    }
                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "-----> **" << setw(6) << Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik << setw(3) << Ucgenler[sayac1 + sayac2 + sayac3].Karakter << setw(5) << "**" << endl;

                    for (int i = sayac1 + sayac2 + sayac3 - 1; i > -1; i--) { //Seçilen üçgenin altındaki üçgenlerin bilgisini yazdırma işlemleri
                        if (Ucgenler[i].Yukseklik != 0) {
                            cout << setw(36) << "****************" << endl;
                            cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                        }
                    }
                    int Yksklk = Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik; //Seçilen üçgenin şekil olarak yazdırılması
                    char Krktr = Ucgenler[sayac1 + sayac2 + sayac3].Karakter;

                    for (int Genislik = 1; Genislik <= Yksklk; Genislik++) {
                        for (int Boşluk = 0; Boşluk < Yksklk - Genislik; Boşluk++) {
                            cout << " ";
                        }
                        if (Genislik == 1 || Genislik == Yksklk) {
                            for (int charCount = 1; charCount <= 2 * Genislik - 1; charCount++) {
                                cout << Krktr;
                            }
                        }
                        else {
                            cout << Krktr;
                            for (int Boşluk = 0; Boşluk < 2 * Genislik - 3; Boşluk++) {
                                cout << " ";
                            }
                            cout << Krktr;
                        }
                        cout << endl;
                    }
                }
            }

            else { // Eklenecek üçgenin satır başında olması durumu

                int randomYukseklik = rand() % 8 + 3;  //Diziye yeni bir üçgen ekleme işlemleri
                char randomKarakter[] = { '$', '-', '+', 'x' };
                char randomKrktr = randomKarakter[rand() % 3];
                if (Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik == 0) {
                    Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik = randomYukseklik;
                    Ucgenler[sayac1 + sayac2 + sayac3].Karakter = randomKrktr;
                }

                cout << setw(36) << "****************" << endl;
                cout << setw(22) << "-----> **" << setw(6) << Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik << setw(3) << Ucgenler[sayac1 + sayac2 + sayac3].Karakter << setw(5) << "**" << endl;

                for (int i = sayac1 + sayac2 + sayac3 - 1; i > -1; i--) { //Dizideki üçgenlerin bilgisini yazdırma işlemleri
                    if (Ucgenler[i].Yukseklik != 0) {
                        cout << setw(36) << "****************" << endl;
                        cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                    }
                }

                int Yksklk = Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik; //Dizideki üçgenleri şekil olarak yazdırma işlemleri
                char Krktr = Ucgenler[sayac1 + sayac2 + sayac3].Karakter;

                for (int Genislik = 1; Genislik <= Yksklk; Genislik++) {
                    for (int Boşluk = 0; Boşluk < Yksklk - Genislik; Boşluk++) {
                        cout << " ";
                    }
                    if (Genislik == 1 || Genislik == Yksklk) {
                        for (int charCount = 1; charCount <= 2 * Genislik - 1; charCount++) {
                            cout << Krktr;
                        }
                    }
                    else {
                        cout << Krktr;
                        for (int Boşluk = 0; Boşluk < 2 * Genislik - 3; Boşluk++) {
                            cout << " ";
                        }
                        cout << Krktr;
                    }
                    cout << endl;

                }
            }
            sayac1++;
        }

        else if (Secenek == 's' || Secenek == 'S') { //Kullanıcının s seçmesi durumu

            sayac2--;

            if (sayac1 + sayac2 + sayac3 < 0) { //Sayaçların toplamının 0 dan küçük olması durumu

                for (int i = UcgenSayisi; i > 2 * sayac1 + sayac2 + sayac3; i--) { // Seçilen üçgenin üstündeki üçgenlerin bilgisinin yazdırılması
                    if (Ucgenler[i].Yukseklik != 0) {
                        cout << setw(36) << "****************" << endl;
                        cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                    }
                }
                if (Ucgenler[2 * sayac1 + sayac2 + sayac3].Yukseklik != 0) { // Seçilen üçgenin bilgilerinin yazdırılması
                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "-----> **" << setw(6) << Ucgenler[2 * sayac1 + sayac2 + sayac3].Yukseklik << setw(3) << Ucgenler[2 * sayac1 + sayac2 + sayac3].Karakter << setw(5) << "**" << endl;
                }
                for (int i = 2 * sayac1 + sayac2 + sayac3 - 1; i > -1; i--) { // Seçilen üçgenin altındaki üçgenlerin bilgisinin yazdırılması

                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;

                }
                int Yksklk = Ucgenler[2 * sayac1 + sayac2 + sayac3].Yukseklik; //Dizideki üçgenleri şekil olarak yazdırma işlemleri
                char Krktr = Ucgenler[2 * sayac1 + sayac2 + sayac3].Karakter;

                for (int Genislik = 1; Genislik <= Yksklk; Genislik++) {
                    for (int Boşluk = 0; Boşluk < Yksklk - Genislik; Boşluk++) {
                        cout << " ";
                    }
                    if (Genislik == 1 || Genislik == Yksklk) {
                        for (int krktrSayisi = 1; krktrSayisi <= 2 * Genislik - 1; krktrSayisi++) {
                            cout << Krktr;
                        }
                    }
                    else {
                        cout << Krktr;
                        for (int Boşluk = 0; Boşluk < 2 * Genislik - 3; Boşluk++) {
                            cout << " ";
                        }
                        cout << Krktr;
                    }
                    cout << endl;
                }
            }
            else if (sayac1 + sayac2 + sayac3 > sayac1) { // Sayaçların toplamının dizideki üçgen sayısından fazla olma durumu

                for (int i = UcgenSayisi; i > sayac2 + sayac3; i--) { // Seçilen üçgenin üstündeki üçgenlerin bilgisinin yazdırılması
                    if (Ucgenler[i].Yukseklik != 0) {
                        cout << setw(36) << "****************" << endl;
                        cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                    }
                }

                if (Ucgenler[sayac2 + sayac3].Yukseklik != 0) { // Seçilen üçgenin bilgilerinin yazdırılması
                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "-----> **" << setw(6) << Ucgenler[sayac2 + sayac3].Yukseklik << setw(3) << Ucgenler[sayac2 + sayac3].Karakter << setw(5) << "**" << endl;
                }
                for (int i = sayac2 + sayac3 - 1; i > -1; i--) { // Seçilen üçgenin altındaki üçgenlerin bilgisinin yazdırılması

                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;

                }
                int Yksklk = Ucgenler[sayac2 + sayac3].Yukseklik; //Dizideki üçgenleri şekil olarak yazdırma işlemleri
                char Krktr = Ucgenler[sayac2 + sayac3].Karakter;

                for (int Genislik = 1; Genislik <= Yksklk; Genislik++) {
                    for (int Boşluk = 0; Boşluk < Yksklk - Genislik; Boşluk++) {
                        cout << " ";
                    }
                    if (Genislik == 1 || Genislik == Yksklk) {
                        for (int krktrSayisi = 1; krktrSayisi <= 2 * Genislik - 1; krktrSayisi++) {
                            cout << Krktr;
                        }
                    }
                    else {
                        cout << Krktr;
                        for (int Boşluk = 0; Boşluk < 2 * Genislik - 3; Boşluk++) {
                            cout << " ";
                        }
                        cout << Krktr;
                    }
                    cout << endl;
                }
            }
            else { // Sayaçların toplaının 0 ile dizideki üçgen sayısı arasında olması durumu

                for (int i = UcgenSayisi; i > sayac1 + sayac2 + sayac3 - 1; i--) { // Seçilen üçgenin üstündeki üçgenlerin bilgisinin yazdırılması
                    if (Ucgenler[i].Yukseklik != 0) {
                        cout << setw(36) << "****************" << endl;
                        cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                    }
                }
                if (Ucgenler[sayac1 + sayac2 + sayac3 - 1].Yukseklik != 0) { // Seçilen üçgenin bilgilerinin yazdırılması
                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "-----> **" << setw(6) << Ucgenler[sayac1 + sayac2 + sayac3 - 1].Yukseklik << setw(3) << Ucgenler[sayac1 + sayac2 + sayac3 - 1].Karakter << setw(5) << "**" << endl;
                }
                for (int i = sayac1 + sayac2 + sayac3 - 2; i > -1; i--) { // Seçilen üçgenin altındaki üçgenlerin bilgisinin yazdırılması

                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;

                }
                int Yksklk = Ucgenler[sayac1 + sayac2 + sayac3 - 1].Yukseklik; //Dizideki üçgenleri şekil olarak yazdırma işlemleri
                char Krktr = Ucgenler[sayac1 + sayac2 + sayac3 - 1].Karakter;

                for (int Genislik = 1; Genislik <= Yksklk; Genislik++) {
                    for (int Boşluk = 0; Boşluk < Yksklk - Genislik; Boşluk++) {
                        cout << " ";
                    }
                    if (Genislik == 1 || Genislik == Yksklk) {
                        for (int charCount = 1; charCount <= 2 * Genislik - 1; charCount++) {
                            cout << Krktr;
                        }
                    }
                    else {
                        cout << Krktr;
                        for (int Boşluk = 0; Boşluk < 2 * Genislik - 3; Boşluk++) {
                            cout << " ";
                        }
                        cout << Krktr;
                    }
                    cout << endl;
                }
            }

        }
        else if (Secenek == 'w' || Secenek == 'W') { // Kullanıcının w seçmesi durumu

            sayac3++;

            if (sayac1 + sayac2 + sayac3 > sayac1) { // Sayaçların toplamının dizideki üçgen sayısından fazla olması durumu

                for (int i = UcgenSayisi; i > sayac2 + sayac3; i--) { // Seçilen üçgenin üstündeki üçgenlerin bilgisinin yazdırılması
                    if (Ucgenler[i].Yukseklik != 0) {
                        cout << setw(36) << "****************" << endl;
                        cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                    }
                }

                if (Ucgenler[sayac2 + sayac3].Yukseklik != 0) { // Seçilen üçgenin bilgisinin yazdırılması
                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "-----> **" << setw(6) << Ucgenler[sayac2 + sayac3].Yukseklik << setw(3) << Ucgenler[sayac2 + sayac3].Karakter << setw(5) << "**" << endl;
                }

                for (int i = sayac2 + sayac3 - 1; i > -1; i--) { // Seçilen üçgenin altındaki üçgenlerin bilgisinin yazdırılması

                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;

                }

                int Yksklk = Ucgenler[sayac2 + sayac3].Yukseklik; //Dizideki üçgenleri şekil olarak yazdırma işlemleri
                char Krktr = Ucgenler[sayac2 + sayac3].Karakter;

                for (int Genislik = 1; Genislik <= Yksklk; Genislik++) {
                    for (int Boşluk = 0; Boşluk < Yksklk - Genislik; Boşluk++) {
                        cout << " ";
                    }
                    if (Genislik == 1 || Genislik == Yksklk) {
                        for (int charCount = 1; charCount <= 2 * Genislik - 1; charCount++) {
                            cout << Krktr;
                        }
                    }
                    else {
                        cout << Krktr;
                        for (int Boşluk = 0; Boşluk < 2 * Genislik - 3; Boşluk++) {
                            cout << " ";
                        }
                        cout << Krktr;
                    }
                    cout << endl;
                }
            }
            else if (sayac1 + sayac2 + sayac3 < 0) { // Sayaçların toplamının 0 dan küçük olması durumu

                for (int i = UcgenSayisi; i > 2 * sayac1 + sayac2 + sayac3; i--) { // Seçilen üçgenin üstündeki üçgenlerin bilgisinin yazdırılması
                    if (Ucgenler[i].Yukseklik != 0) {
                        cout << setw(36) << "****************" << endl;
                        cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                    }
                }
                if (Ucgenler[2 * sayac1 + sayac2 + sayac3].Yukseklik != 0) { // Seçilen üçgenin bilgisinin yazdırılması
                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "-----> **" << setw(6) << Ucgenler[2 * sayac1 + sayac2 + sayac3].Yukseklik << setw(3) << Ucgenler[2 * sayac1 + sayac2 + sayac3].Karakter << setw(5) << "**" << endl;
                }
                for (int i = 2 * sayac1 + sayac2 + sayac3 - 1; i > -1; i--) { // Seçilen üçgenin altındaki üçgenlerin bilgisinin yazdırılması

                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;

                }

                int Yksklk = Ucgenler[2 * sayac1 + sayac2 + sayac3].Yukseklik; //Dizideki üçgenleri şekil olarak yazdırma işlemleri
                char Krktr = Ucgenler[2 * sayac1 + sayac2 + sayac3].Karakter;
                for (int Genislik = 1; Genislik <= Yksklk; Genislik++) {
                    for (int Boşluk = 0; Boşluk < Yksklk - Genislik; Boşluk++) {
                        cout << " ";
                    }
                    if (Genislik == 1 || Genislik == Yksklk) {
                        for (int charCount = 1; charCount <= 2 * Genislik - 1; charCount++) {
                            cout << Krktr;
                        }
                    }
                    else {
                        cout << Krktr;
                        for (int Boşluk = 0; Boşluk < 2 * Genislik - 3; Boşluk++) {
                            cout << " ";
                        }
                        cout << Krktr;
                    }
                    cout << endl;
                }
            }
            else { // Sayaçların toplaının 0 ile dizideki üçgen sayısı arasında olması durumu

                for (int i = UcgenSayisi; i > sayac1 + sayac2 + sayac3; i--) { // Seçilen üçgenin üstündeki üçgenlerin bilgisinin yazdırılması
                    if (Ucgenler[i].Yukseklik != 0) {
                        cout << setw(36) << "****************" << endl;
                        cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;
                    }
                }
                if (Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik != 0) { // Seçilen üçgenin bilgisinin yazdırılması
                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "-----> **" << setw(6) << Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik << setw(3) << Ucgenler[sayac1 + sayac2 + sayac3].Karakter << setw(5) << "**" << endl;
                }
                for (int i = sayac1 + sayac2 + sayac3 - 1; i > -1; i--) { // Seçilen üçgenin altındaki üçgenlerin bilgisinin yazdırılması

                    cout << setw(36) << "****************" << endl;
                    cout << setw(22) << "**" << setw(6) << Ucgenler[i].Yukseklik << setw(3) << Ucgenler[i].Karakter << setw(5) << "**" << endl;

                }
                int Yksklk = Ucgenler[sayac1 + sayac2 + sayac3].Yukseklik; //Dizideki üçgenleri şekil olarak yazdırma işlemleri
                char Krktr = Ucgenler[sayac1 + sayac2 + sayac3].Karakter;

                for (int Genislik = 1; Genislik <= Yksklk; Genislik++) {
                    for (int Boşluk = 0; Boşluk < Yksklk - Genislik; Boşluk++) {
                        cout << " ";
                    }
                    if (Genislik == 1 || Genislik == Yksklk) {
                        for (int charCount = 1; charCount <= 2 * Genislik - 1; charCount++) {
                            cout << Krktr;
                        }
                    }
                    else {
                        cout << Krktr;
                        for (int Boşluk = 0; Boşluk < 2 * Genislik - 3; Boşluk++) {
                            cout << " ";
                        }
                        cout << Krktr;
                    }
                    cout << endl;
                }
            }
        }
        cin >> Secenek;
    }
}
