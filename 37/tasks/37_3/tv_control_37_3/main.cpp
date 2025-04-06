#include <QApplication>
#include "callermainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    CallerMainWindow w(nullptr);
    Ui::TVControlPanel caller;

    caller.setupUi(&w);
    w.result = caller.display;

    std::string ch = std::to_string(w.channel);
    std::string vol= std::to_string(w.volume);
    std::string res_str = "Channel: " + ch + " vol: " + vol;
    w.result->setText(QString::fromStdString(res_str));

    w.show();
    return a.exec();
}
