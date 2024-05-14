// B221200029 Yazel Yüce
// Veri yapıları proje ödevi 

#include <iostream>
#include <vector>

// Veri yapısını tanımla
struct Veri {
    double deger;
    char grup;
    int indeks;
};

// Basit bir hash fonksiyonu olarak verilen sayıyı 2 ile çarpar ve mod 7 alır
int hashFunction(double number) {
    return static_cast<int>(number * 2) % 7;
}

int main() {
    // Hash tablosunu temsil eden vektör
    std::vector<Veri> hashTablosu[2];

    // Verileri içeren vektör
    double veriler[] = {
        2.663700925, 3.6599162, 3.599446376, 3.636788689, 3.661623409, 3.636287252,
        3.127428778, 3.008174184, 3.009025742, 3.068927612, 3.090610708, 2.960946196,
        2.913283902, 3.034628457, 3.048053173, 2.98811284, 2.812244697, 2.50242712,
        2.933993164, 2.924795996, 2.389166084, 2.803457116
    };

    // Verileri gruplara yerleştirme
    for (double deger : veriler) {
        char grup;
        if (hashFunction(deger) >= 0 && hashFunction(deger) <= 1)
            grup = 'B';
        else
            grup = 'A';
        
        int indeks = (grup == 'A') ? 0 : 1;
        hashTablosu[indeks].push_back({deger, grup, indeks});
    }

    // Hash tablosunu yazdırma
    for (int i = 0; i < 2; ++i) {
        std::cout << "Grup " << static_cast<char>('A' + i) << ":" << std::endl;
        for (int j = 0; j < hashTablosu[i].size(); ++j) {
          
            std::cout << hashTablosu[i][j].deger << " -> " << hashTablosu[i][j].indeks << std::endl;
        }
    }

    return 0;
}