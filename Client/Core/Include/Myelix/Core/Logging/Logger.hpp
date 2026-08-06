#pragma once

#include "Myelix/Core/Logging/LogMessage.hpp"

namespace Myelix::Core::Logging
{

    class Logger final
    {
    public:
        Logger() = default;
        ~Logger() = default;

        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        void Log(LogLevel level, std::string category, std::string message);

        [[nodiscard]]
        const LogMessage& LastMessage() const noexcept;

    private:
        LogMessage m_lastMessage;
    };

} // namespace Myelix::Core::Logging
