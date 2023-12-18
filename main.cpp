#include "pomodoro.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pomodoro w;
    w.show();
    return a.exec();
}
