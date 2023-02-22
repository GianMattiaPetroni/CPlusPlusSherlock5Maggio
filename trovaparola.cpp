#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    // trovare le righe contenenti la parola data
    // int trova(string parola)

    ifstream fileInput("maggio.txt"); 
    if (fileInput.is_open())
    {
        cout << "il file è stato aperto correttamente" << endl;
    }
    else
    {
        cout << "il file non è stato aperto correttamente" << endl;
    }

    int i = 1;
    string riga;
    string parola = "";
    int numeroRigaParolaTrovata = 0;
    cout << "inserisci una parola da trovare" << endl;
    cin >> parola;
    while (parola != "EXIT")
    {
        while (getline(fileInput, riga))
        {
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
        }
    } while (getline(fileInput, riga))
    {
        if (i % 7 == 0)
        {
            cout << endl;
        }
        else if (riga == "")
        {
            cout << endl;
        }
        else if (i < 10)
        {
            cout << i << "   - " << riga << endl;
        }
        else if (i < 100)
        {
            cout << i << "  - " << riga << endl;
        }
        else
        {
            cout << i << " - " << riga << endl;
        }
        i++;
    }  if()
    fileInput.close();
    // fileOutput.close();
}