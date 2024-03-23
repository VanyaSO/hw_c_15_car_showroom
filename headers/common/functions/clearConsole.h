#ifndef CLEARCONSOLE
#define CLEARCONSOLE
// добволяет отступы чтобы было более читаемо(у меня нету функции которая чистит консоль)
void clearConsole() {
    for (int i = 0; i < 25; ++i) {
        cout << endl;
    }
}
#endif
