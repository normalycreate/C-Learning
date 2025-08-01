#include <iostream>
#include <functional>
using namespace std;

int main() {
    function<int(int)> rumusFaktorial = [&](int n) -> int {
        if (n == 0 || n == 1) return 1;
        else if (n > 20) {
            cout << "Error! Angkanya Kegedean -_-" << endl;
            return 0;
        }
        else return n * rumusFaktorial(n - 1);
    };
    int masukanAngka;
    cout << "Masukan angka : ";
    cin >> masukanAngka;
    if(masukanAngka > 20 || masukanAngka < 0) {
        cout << "Angka ga valid!, masukan lagi!";
    } else {
        cout << "Hasil dari faktorial adalah : " << rumusFaktorial(masukanAngka);
    }
}