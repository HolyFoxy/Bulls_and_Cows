#include "bulls_and_cows.h"
#include <ctime>
#include <random>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bulls_and_Cows w;
    w.show();
    return a.exec();
}
