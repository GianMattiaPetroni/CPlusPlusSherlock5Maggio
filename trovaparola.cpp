#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string riga;
    string parola;
    string paragrafo = "";
    int numeroRigaParolaTrovata = 0;
    string accomulatore;
    string righemancanti;

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
            if (numeroRigaParolaTrovata % 7 != 0)
            {
                accomulatore = accomulatore + riga + "\n";
            }
            else
            {
                accomulatore = "";
            }

            numeroRigaParolaTrovata++;
            bool flag = false;                      // SE TROVO LA PAROLA IMPOSTO A TRUE
            for (int i = 0; i < riga.length(); i++) // for tutta riga
            {

                for (int j = 0; j < parola.length(); j++) // for tutta parola
                {

                    if (riga[i] == parola[j]) // se le lettere sono uguali
                    {
                        if (j == parola.length() - 1) // se le lettere sono uguali E sono all'ultima lettera della parola
                        {
                            flag = true; // PAROLA TROVATA
                            cout << "LA PAROLA E' STATA TROVATA E QUESTA E' LA STROFA" << endl;
                            cout << accomulatore;

                            while (getline(fileInput, riga))
                            {
                                if (riga == "")
                                {
                                    break;
                                }
                            }
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
        fileInput.close();
    }
}