#include "Myelix/App/MainWindow.hpp"

#include <QSize>

namespace Myelix::App
{

    MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent)
    {
        setWindowTitle(QStringLiteral("Myelix"));

        resize(QSize(1280, 800));

        setMinimumSize(QSize(1024, 720));
    }

} // namespace Myelix::App
