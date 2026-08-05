#pragma once

#include <QMainWindow>

namespace Myelix::App
{

    class MainWindow final : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);
        ~MainWindow() override = default;
    };

} // namespace Myelix::App
