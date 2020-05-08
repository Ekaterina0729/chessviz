#include "chess.h"
#include <iostream>

using namespace std;

void proverka(string xod, int m[][2])
{
    int errorCheck = 1;
    while (errorCheck) {
        cout << endl << "Vvedite xod: ";
        cin >> xod;
        switch (xod[0]) {
        case 'a':
            m[0][0] = 1;
            break;
        case 'b':
            m[0][0] = 2;
            break;
        case 'c':
            m[0][0] = 3;
            break;
        case 'd':
            m[0][0] = 4;
            break;
        case 'e':
            m[0][0] = 5;
            break;
        case 'f':
            m[0][0] = 6;
            break;
        case 'g':
            m[0][0] = 7;
            break;
        case 'h':
            m[0][0] = 8;
            break;
        default:
            cout << "Error";
            errorCheck = 0;
        }

        if (errorCheck == 1)
            switch (xod[1]) {
            case '1':
                m[0][1] = 7;
                break;
            case '2':
                m[0][1] = 6;
                break;
            case '3':
                m[0][1] = 5;
                break;
            case '4':
                m[0][1] = 4;
                break;
            case '5':
                m[0][1] = 3;
                break;
            case '6':
                m[0][1] = 2;
                break;
            case '7':
                m[0][1] = 1;
                break;
            case '8':
                m[0][1] = 0;
                break;
            default:
                cout << "Error";
                errorCheck = 0;
            }

        if (errorCheck == 1)
            if (xod[2] != '-') {
                cout << "Error";
                errorCheck = 0;
            }

        if (errorCheck == 1)
            switch (xod[3]) {
            case 'a':
                m[1][0] = 1;
                break;
            case 'b':
                m[1][0] = 2;
                break;
            case 'c':
                m[1][0] = 3;
                break;
            case 'd':
                m[1][0] = 4;
                break;
            case 'e':
                m[1][0] = 5;
                break;
            case 'f':
                m[1][0] = 6;
                break;
            case 'g':
                m[1][0] = 7;
                break;
            case 'h':
                m[1][0] = 8;
                break;
            default:
                cout << "Error";
                errorCheck = 0;
            }

        if (errorCheck == 1)
            switch (xod[4]) {
            case '1':
                m[1][1] = 7;
                break;
            case '2':
                m[1][1] = 6;
                break;
            case '3':
                m[1][1] = 5;
                break;
            case '4':
                m[1][1] = 4;
                break;
            case '5':
                m[1][1] = 3;
                break;
            case '6':
                m[1][1] = 2;
                break;
            case '7':
                m[1][1] = 1;
                break;
            case '8':
                m[1][1] = 0;
                break;
            default:
                cout << "Error";
                errorCheck = 0;
            }
        errorCheck = 0;
    }
}
