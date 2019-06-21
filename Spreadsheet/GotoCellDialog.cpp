#include "GotoCellDialog.hpp"
#include "ui_GotoCellDialog.h"

GotoCellDialog::GotoCellDialog(QWidget *parent) : QDialog(parent), ui(new Ui::GotoCellDialog) {
    ui->setupUi(this);

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));

    connect(ui->okButton, &QPushButton::clicked, this, &GotoCellDialog::accept);
    connect(ui->cancelButton, &QPushButton::clicked, this, &GotoCellDialog::reject);
}

GotoCellDialog::~GotoCellDialog() {
    delete ui;
}

void GotoCellDialog::changeEvent(QEvent *e) {
    QDialog::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void GotoCellDialog::on_lineEdit_textChanged(const QString &arg1) {
    Q_UNUSED(arg1);
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
