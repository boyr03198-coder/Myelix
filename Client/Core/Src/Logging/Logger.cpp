#include "Myelix/Core/Logging/Logger.hpp"

#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QTextStream>

#ifdef _WIN32
#include <Windows.h>
#endif

namespace
{

    QString ToString(Myelix::Core::Logging::LogLevel level)
    {
        using namespace Myelix::Core::Logging;

        switch (level)
        {
            case LogLevel::Trace:
                return "Trace";

            case LogLevel::Debug:
                return "Debug";

            case LogLevel::Info:
                return "Info";

            case LogLevel::Warning:
                return "Warning";

            case LogLevel::Error:
                return "Error";

            case LogLevel::Critical:
                return "Critical";
        }

        return "Unknown";
    }

    QString LogFilePath()
    {
        QDir directory(QCoreApplication::applicationDirPath());

        directory.mkpath("Logs");

        return directory.filePath("Logs/Myelix.log");
    }

} // anonymous namespace

namespace Myelix::Core::Logging
{

    void Logger::Log(LogLevel level, std::string category, std::string message)
    {
        m_lastMessage = {level, category, message};

        QFile file(LogFilePath());

        if (file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream stream(&file);

            stream << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") << " ["
                   << ToString(level) << "] " << QString::fromStdString(category) << ": "
                   << QString::fromStdString(message) << Qt::endl;
        }

#ifdef _WIN32
        const QString output = QString("%1 [%2] %3: %4\n")
                                   .arg(QDateTime::currentDateTime().toString("HH:mm:ss"))
                                   .arg(ToString(level))
                                   .arg(QString::fromStdString(category))
                                   .arg(QString::fromStdString(message));

        OutputDebugStringW(reinterpret_cast<LPCWSTR>(output.utf16()));
#endif
    }

    const LogMessage& Logger::LastMessage() const noexcept
    {
        return m_lastMessage;
    }

} // namespace Myelix::Core::Logging
