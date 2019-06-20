/**
 ** This file is part of the Qt-QML project.
 ** Copyright 2019 xiaohaijin <xiaohaidotpro@outlook.com>.
 **
 **/

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Enter Your Age");

    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(0, 80);
    slider->setRange(0, 80);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
    spinBox->setValue(35);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window->setLayout(layout);

    window->show();

    return app.exec();
}
