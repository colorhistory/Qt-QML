#include <QtCore>
#include <QtGui>
#include <QtWidgets>

#include "FindDialog.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    FindDialog w;
    w.show();

    return a.exec();
}
