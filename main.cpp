#include <iostream>
#include <fstream>
using namespace std;
int AFN(string ** mat, int n, string cuv, int sta){
    cout << endl << "Intru in functia AFN";
    int k = 0;

    while(!cuv.empty()){
        cout << endl << cuv << "  i = " << sta << " k = " << k;


        if(k >= n)
            return 0;

        for(int j = 1; j <= n; j++){
            cout << "------ j = " << j << " k = " << k << endl;
            if(mat[sta][j].find(cuv[0]) != string::npos){
                if(AFN(mat, n, cuv.substr(1), j))
                    return 1;
            }

            k++;
        }
    }
    if(mat[sta][0].find('x') != string::npos)
        return 1;
    else return 0;

}

int main() {
    int m, n, i, j, a, b;
    string str, cuv;
    ifstream f("C:\\Users\\Micos\\Desktop\\Facultate\\Sem2\\LFA\\Tema 1 completa\\LaboratoruAFN\\graf.in");
//nr noduri si muchii
    f >> n >> m;
//acesta este cuvantul
    f >> cuv;

    cout << "Cuvantul: " << cuv  << endl << "Alfabetul: a,b" << endl
         << "Se va folosi z pentru starea initiala si x pentru cea/ cele finale."
         << endl << "Continutul fisierului .in: " << endl;
//se declara matricea de stringuri
    string ** mat;
    mat = new string*[n+1];

    int sta;
//aloc memoria acum pentru ca o a sar dintr-un i in altul si n-o sa apuce
//sa fie alocat
    for(i = 0; i < n+1 ; i++)
        mat[i] = new string[n+1];
    int ok = 1;
//se creaza matricea adiacenta, se si afiseaza continutul textului


    for(i = 0; i < m; i++){
        f >> a >> b >> str;
        mat[a][b] = str;
        cout << " " << a << " " <<  b << " " <<  str << endl;
        if(str.find('z')!= string::npos)
            sta = a;
    }


    cout << endl  << "Matricea de adiacenta: " << endl;
    cout << "  ";
    for(i = 0; i <= n ; i++){
        for(j = 0; j <= n; j++){
            cout << " ";
            if(i == 0){
                cout << j << " ";
            }else {
                if(j == 0)
                    cout << i << " ";
                if (mat[i][j].empty()) {
                    cout << "-";
                }
                cout << mat[i][j] << " ";
            }
        }
        cout << endl;
    }


    cout << endl;


    if(AFN(mat, n, cuv, sta))
        cout << endl << "MERGE AFN CUVANT";
    else
        cout <<"\nNU MERGE";

    cout << endl << cuv;


    delete[]* mat;
    return 0;
}
