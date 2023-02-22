#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    string riga;
    string parola = "";
    int numeroRigaParolaTrovata = 0;
    int a = 1;
    while (parola != "EXIT")
    {
        cout << "inserisci una parola da trovare" << endl;
        cin >> parola;
        ifstream fileInput("maggio.txt");
        if (fileInput.is_open())
        {
            cout << "il file è stato aperto correttamente" << endl;
        }
        else
        {
            cout << "il file non è stato aperto correttamente" << endl;
        }

        while (getline(fileInput, riga))
        {
            if (a % 7 == 0)
            {
                cout << endl;
            }
            else if (riga == "")
            {
                cout << endl;
            }
            else if (a < 10)
            {
                cout << a << "   - " << riga << endl;
            }
            else if (a < 100)
            {
                cout << a << "  - " << riga << endl;
            }
            else
            {
                cout << a << " - " << riga << endl;
            }
            a++;
            // cout << "RIGA: " << riga << endl;
            numeroRigaParolaTrovata++;
            bool flag = false;                      // SE TROVO LA PAROLA IMPOSTO A TRUE
            for (int i = 0; i < riga.length(); i++) // for tutta riga
            {
                // cout << "i: " << i << endl;
                for (int j = 0; j < parola.length(); j++) // for tutta parola
                {
                    // cout << "j: " << j << endl;
                    // cout << "riga[i]: " << riga[i] <<" == "<< "parola[j]:" << parola[j] << endl;
                    if (riga[i] == parola[j]) // se le lettere sono uguali
                    {
                        if (j == parola.length() - 1) // se le lettere sono uguali E sono all'ultima lettera della parola
                        {
                            flag = true; // PAROLA TROVATA
                            cout << "TROVATA" << endl;
                        }
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if (flag == true)
            {
                cout << "PAROLA TROVATA IN RIGA: " << numeroRigaParolaTrovata << endl;
            }
            else
            {
                cout << "PAROLA NON TROVATA" << endl;
            }
        }
    }

    fileInput.close();
}