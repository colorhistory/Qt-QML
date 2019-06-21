#ifndef GOTOCELLDIALOG_HPP
#define GOTOCELLDIALOG_HPP

#include <QDialog>

namespace Ui {
    class GotoCellDialog;
}

class GotoCellDialog : public QDialog {
    Q_OBJECT

  public:
    explicit GotoCellDialog(QWidget *parent = 0);
    ~GotoCellDialog();

  protected:
    void changeEvent(QEvent *e);

  private slots:
    void on_lineEdit_textChanged(const QString &arg1);

  private:
    Ui::GotoCellDialog *ui;
};

#endif  // GOTOCELLDIALOG_HPP
