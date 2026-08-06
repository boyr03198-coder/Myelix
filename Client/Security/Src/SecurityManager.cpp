#include "Myelix/Security/SecurityManager.hpp"

#include <utility>

namespace Myelix::Security
{

    SecurityManager::SecurityManager(Myelix::Core::Logging::Logger& logger)
        : m_logger(logger)
    {
    }

    void SecurityManager::Report(SecurityEvent event, SecurityLevel level, std::string message)
    {
        m_logger.Log(Myelix::Core::Logging::LogLevel::Info, "Security", message);

        m_lastEvent = SecurityRecord{event, level, std::move(message)};
    }

    bool SecurityManager::HasEvent() const noexcept
    {
        return m_lastEvent.has_value();
    }

    const std::optional<SecurityRecord>& SecurityManager::LastEvent() const noexcept
    {
        return m_lastEvent;
    }

    void SecurityManager::Clear() noexcept
    {
        m_lastEvent.reset();
    }

} // namespace Myelix::Security
