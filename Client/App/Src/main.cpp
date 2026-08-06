#include "Myelix/App/Application.hpp"
#include "Myelix/Core/Logging/Logger.hpp"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);

    Myelix::Core::Logging::Logger logger;

    logger.Log(Myelix::Core::Logging::LogLevel::Info, "Application",
               "========================================");

    logger.Log(Myelix::Core::Logging::LogLevel::Info, "Application", "Starting Myelix");

    Myelix::App::Application myelix(application);

    const int result = myelix.Run();

    logger.Log(Myelix::Core::Logging::LogLevel::Info, "Application", "Application exited.");

    return result;
}
