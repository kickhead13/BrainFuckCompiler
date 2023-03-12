#include <iostream>
#include <string.h>
using namespace std;

int vect[256], poz =0, pozx=0, pozy=1;
char com[300];

void cit() {
    cin.getline(com, 300);
}
void program(){
    for(int i =0; i<strlen(com); i++) {
        if(com[i] == '+')
            vect[poz] += (vect[poz]<255 ? 1 : -255);
        else if(com[i] == '-')
            vect[poz] += (vect[poz] ? -1 : 255);
        else if(com[i] == '>')
            poz += (poz<255 ? 1 : -255);
        else if(com[i] == '<')
            poz += (poz ? -1 : 255);

        if(com[i] == '^')
            cout << poz;
        if(com[i] == '.')
            cout << char(vect[poz]);
        if(com[i] == '#')
            cout << vect[poz];
        if(com[i] == '$') //HAMAS OPERATOR: bombaredeaza tot vectoru de valori si il face complet 0
            for(int i =1; i<=255; i++)
                vect[i] = 0;
        if(com[i] == ',') {
            int temp;
            cin >> temp;
            vect[poz] = temp;
        }
        if(com[i] == '[') {
            pozx = i;
            if(!vect[poz])
                i = pozy;
            //cout << poz << endl;
        }
        else if(com[i] == ']') {
            pozy=i;
            i = pozx-1;
        }
    }
}
//+++++++++[->++++++++<].
int main() {
    for(int i =0; i<=255;i++)
        vect[i] = 0;
    cit();
    program();
}
