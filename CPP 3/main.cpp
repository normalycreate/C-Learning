#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
//Untuk bagian struktur data tumpukan
#include <stack>
#include <sstream>
#include <cctype>

using namespace std;

//Ini buat decoration
void pembatasKata() {
    int index; int targetString = 70;
    string equalDecoration = "=";
    for(index = 0; index < targetString; index++) {
        cout << equalDecoration;
    }
}

//fitur helper sebagai prioritas operator
int prioritasOperator(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

//fungsi helper untuk melakukan satu operasi
double letakanAngka(double operasi1, double operasi2, char op) {
    switch(op) {
        case '+': return operasi1 + operasi2;
        case '-': return operasi1 + operasi2;
        case '*': return operasi1 * operasi2;
        case '/': return operasi1 / operasi2;
        case 'x': return operasi1 * operasi2;
    }
    return 0;
}

int main() {
    string masukanAngka; 
    pembatasKata();
    cout << "\nSelamat datang di kalkulator CPP\n";
    cout << "Contoh penggunaan : 1 + 3\n";
    pembatasKata();
    cout << "\n";
    getline(cin, masukanAngka); // ini membaca seluruh baris  input remasuk spasi
    stack<double> angka; // tumpukan angka
    stack<char> operasiBertumpuk; // tumpukan operator

    stringstream ss(masukanAngka);

    //looping untuk ekspresi
    double aka;
    char op;
    
    while (ss >> aka) {
        angka.push(aka);
    // coba operator selanjutnya
        if (ss >> op) {
            while (!operasiBertumpuk.empty() && prioritasOperator(operasiBertumpuk.top()) >= 
            prioritasOperator(op)) {
                double val2 = angka.top(); angka.pop();
                double val1 = angka.top(); angka.pop();
                char op_to_apply = operasiBertumpuk.top(); operasiBertumpuk.pop();
            angka.push(letakanAngka(val1, val2, op_to_apply));
        }
        operasiBertumpuk.push(op);
    }
}
    while (!operasiBertumpuk.empty()) {
        double val2 = angka.top(); angka.pop();
        double val1 = angka.top(); angka.pop();
        char op_to_apply = operasiBertumpuk.top(); operasiBertumpuk.pop();

        angka.push(letakanAngka(val1,val2, op_to_apply));
    }

    pembatasKata();
    cout << "\n";
    cout << "Hasil dari " << masukanAngka << " itu " << angka.top() << endl;
    pembatasKata();
    
    return 0;
}
