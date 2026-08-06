#include "Myelix/App/Application.hpp"

#include "Myelix/App/MainWindow.hpp"

#include <QApplication>

namespace Myelix::App
{

    Application::Application(QApplication& application)
        : m_application(application),
          m_mainWindow(std::make_unique<MainWindow>())
    {
    }

    Application::~Application() = default;

    int Application::Run()
    {
        m_mainWindow->show();

        return m_application.exec();
    }

} // namespace Myelix::App
