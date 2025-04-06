#include <QApplication>
#include <QPushButton>
#include "callermainwindow.h"
#include "./ui_caller.h"


int main(int argc, char *argv[]) {
    QApplication a(argc,argv);
    CallerMainWindow window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);
    window.resize(300,200);

    window.result = caller.lcdNumber;
    window.num_1 = caller.number_1;
    window.num_2 = caller.number_2;

    window.show();

    return a.exec();
}
