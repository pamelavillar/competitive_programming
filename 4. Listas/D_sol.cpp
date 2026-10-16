#include <iostream>
#include <list>

using namespace std;

struct Student {
    int a;
    int b;
    int c;
};

int main() {

    int n;
    int caseNum = 1;

    while (cin >> n && n) {

        list<Student> students;

        for (int i = 0; i < n; i++) {
            Student s;
            cin >> s.a >> s.b >> s.c;
            students.push_back(s);
        }

        int answer = -1;

        for (int time = 0; time < 1000; time++) {

            // Contar estudiantes despiertos
            int awake = 0;

            for (const Student& s : students) {
                if (s.c <= s.a) {
                    awake++;
                }
            }

            // ¿Todos están despiertos?
            if (awake == n) {
                answer = time;
                break;
            }

            int sleeping = n - awake;

            // Actualizar estado de todos
            for (Student& s : students) {

                // Terminó su ciclo
                if (s.c == s.a + s.b) {
                    s.c = 1;
                }

                // Está en el último minuto despierto
                // y no hay mayoría de estudiantes dormidos
                else if (s.c == s.a && sleeping <= awake) {
                    s.c = 1;
                }

                else {
                    s.c++;
                }
            }
        }

        cout << "Case " << caseNum++ << ": " << answer << '\n';
    }

    return 0;
}