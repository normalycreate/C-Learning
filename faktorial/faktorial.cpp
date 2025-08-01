#include <iostream>
#include <functional>
using namespace std;

int main() {
    function<int(int)> rumusFaktorial = [&](int n) -> int {
        if (n == 0 || n == 1) return 1;
        else return n * rumusFaktorial(n - 1);
    };
    int masukanAngka;
    cout << "Masukan angka : ";
    cin >> masukanAngka;
    int hasil = rumusFaktorial(masukanAngka);
    if(hasil < 0 || masukanAngka > 20 || masukanAngka < 0) {
        cout << "Angka ga valid!, masukan lagi!";
    } else {
        cout << "Hasil dari faktorial adalah : " << rumusFaktorial(masukanAngka);
    }
}
