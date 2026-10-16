
//E - Nesting a Bunch of Brackets

// HOW TO SOLVE
//LEE CON GETLINE NO CIN

// LA COMBINACION '(*' SOLO SE PONE EL * EN EL STACK
// Y CUANDO HAY '*)' SE PREGUNTA SI EN EL TOP DEL STACK ESTA '*' SI NO, ERROR
// PERO SI SI, SE QUITA EL * DEL STACK   
// ESO QUIERE DECIR QUE EN ESAS COMBINACIONES NUNCA SE GUARDA O EVALUA EL )
// DESPUES SE EVALUA CON NORMALIDAD LOS BRACKETS DE ABERTURA Y CIERRE
// LOS DE ABERTURA SE COLOCAN AL STACK
// Y DE CIERRE , PRIMERO EVALUA QUE EL STACK NO ESTE VACIO, SEGUNDO QUE EL TOP COINCIDA CON SU BRACKET DE ABERTURA
// POR ULTIMO SE VERIFICA QUE EEL STACK ESTE VACIO, SI NO LO ESTA ES ERROR, Y EL INDICE DE ERROR ES LA ULTIMA POSICION QUE SE QUEDO
// EL INDICE DE ERROR NO AVANZA A LA MISMA VELOCIDAD QUE EL i QUE RECORRE LA EXPRESION, AVANZA UNO POR UNO

#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
    string s;

    while (getline(cin, s)) {
        stack<char> st;
        int pos = 0;
        int error = 0;
        int i = 0;

        while (i < (int)s.size()) {
            char c = s[i];
            pos++;

            if (c == '(' && i + 1 < (int)s.size() && s[i + 1] == '*') {
                st.push('*');
                i += 2;
                continue;
            }

            if (c == '*' && i + 1 < (int)s.size() && s[i + 1] == ')') {
                if (st.empty() || st.top() != '*') {
                    error = pos;
                    break;
                }
                st.pop();
                i += 2;
                continue;
            }

            if (c == '(' || c == '[' || c == '{' || c == '<') {
                st.push(c);
            }
            else if (c == ')' || c == ']' || c == '}' || c == '>') {
                if (st.empty()) {
                    error = pos;
                    break;
                }

                char top = st.top();

                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{') ||
                    (c == '>' && top != '<')) {
                    error = pos;
                    break;
                }

                st.pop();
            }

            i++;
        }

        if (error == 0 && !st.empty()) {
            error = pos + 1;
        }

        if (error == 0) {
            cout << "YES\n";
        } else {
            cout << "NO " << error << '\n';
        }
    }

    return 0;
}