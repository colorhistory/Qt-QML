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

    QHBoxLayout *topleftLayout = new QHBoxLayout;
    topleftLayout->addWidget(label);
    topleftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topleftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

FindDialog::~FindDialog() {
}

void FindDialog::findClicked() {
    QString text = lineEdit->text();

    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseInsensitive : Qt::CaseInsensitive;

    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

void FindDialog::enableFindButton(const QString &text) {
    findButton->setEnabled(!text.isEmpty());
}
