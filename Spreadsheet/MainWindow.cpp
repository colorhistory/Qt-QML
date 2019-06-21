#include <QtCore>
#include <QtGui>
#include <QtWidgets>

#include "FindDialog.hpp"
#include "GotoCellDialog.hpp"
#include "MainWindow.hpp"
#include "SortDialog.hpp"
#include "spreadsheet.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);

    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();

    findDialog = nullptr;

    setWindowIcon(QIcon(":images/icon.png"));
    setCurrentFile("");
}

MainWindow::~MainWindow() {
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (okToContinue()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::newFile() {
    if (okToContinue()) {
        spreadsheet->clear();
        setCurrentFile("");
    }
}

void MainWindow::open() {
    if (okToContinue()) {
        QString fileName =
            QFileDialog::getOpenFileName(this, tr("Open Spreadsheet"), "./", tr("Spreadsheet files (*.sp)"));
        if (!fileName.isEmpty()) {
            loadFile(fileName);
        }
    }
}

bool MainWindow::save() {
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
    return false;
}

bool MainWindow::saveAs() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Spreadsheet"), "./", tr("Spreadsheet files (*.sp)"));
    if (fileName.isEmpty()) {
        return false;
    }
    return saveFile(fileName);
}

void MainWindow::find() {
    if (!findDialog) {
        findDialog = new FindDialog(this);
        connect(findDialog, &FindDialog::findNext, spreadsheet, &Spreadsheet::findNext);
        connect(findDialog, &FindDialog::findPrevious, spreadsheet, &Spreadsheet::findNext);
    }

    findDialog->show();
    findDialog->raise();
    findDialog->activateWindow();
}
