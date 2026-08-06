#pragma once

#include <memory>

class QApplication;

namespace Myelix::App
{

    class MainWindow;

    class Application final
    {
    public:
        explicit Application(QApplication& application);

        ~Application();

        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;

        Application(Application&&) = delete;
        Application& operator=(Application&&) = delete;

        int Run();

    private:
        QApplication& m_application;
        std::unique_ptr<MainWindow> m_mainWindow;
    };

} // namespace Myelix::App
