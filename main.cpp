#include <QApplication>
#include <QPushButton>
#include "./ui_calculator.h"
#include "logic_calculator.h"
int main(int argc, char* argv[])
{
        QApplication a(argc, argv);
        Calculator window(nullptr);
        Ui::MainWindow calculator;
        calculator.setupUi(&window);
        window.resize(480,540);
        window.lineEdit = calculator.lineEdit;
        window.show();
        return QApplication::exec();
}
