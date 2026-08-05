#include "Myelix/App/MainWindow.hpp"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);

    Myelix::App::MainWindow window;

    window.show();

    return application.exec();
}
