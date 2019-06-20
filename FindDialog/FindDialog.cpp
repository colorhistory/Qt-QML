/**
 ** This file is part of the Qt-QML project.
 ** Copyright 2019 xiaohaijin <xiaohaidotpro@outlook.com>.
 **
 **/

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

#include "FindDialog.hpp"

FindDialog::FindDialog(QWidget *parent) : QDialog(parent) {
    label = new QLabel("Find &What");
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    connect(lineEdit, &QLineEdit::textChanged, this, &FindDialog::enableFindButton);
    connect(findButton, &QPushButton::clicked, this, &FindDialog::findClicked);
    connect(closeButton, &QPushButton::clicked, this, &FindDialog::close);
}

FindDialog::~FindDialog() {
}
