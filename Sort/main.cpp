/****************************************************************************
**
** Copyright (C) 2019 Xiaohai <xiaohaidotpro@outlook.com>.
** Contact: http://xiaohai.pro
**
** This file is part of Qt-QML
**
**
****************************************************************************/

#include "bits/stdc++.h"

#include <QApplication>

#include "SortDialog.hpp"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    SortDialog *dialog = new SortDialog;
    dialog->setColumnRange('A', 'Z');
    dialog->show();

    return app.exec();
}
