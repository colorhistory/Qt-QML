#include <QApplication>

#include "GotoCellDialog.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GotoCellDialog w;
    w.show();

    return a.exec();
}
