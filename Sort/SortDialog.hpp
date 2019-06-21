#ifndef SORTDIALOG_HPP
#define SORTDIALOG_HPP

#include <QDialog>

namespace Ui {
    class SortDialog;
}

class SortDialog : public QDialog {
    Q_OBJECT

  public:
    explicit SortDialog(QWidget *parent = 0);
    ~SortDialog();

    void setColumnRange(QChar first, QChar last);

  protected:
    void changeEvent(QEvent *e);

  private:
    Ui::SortDialog *ui;
};

#endif  // SORTDIALOG_HPP
