#pragma once

#include "Myelix/Core/Logging/Logger.hpp"
#include "Myelix/Security/SecurityEvent.hpp"
#include "Myelix/Security/SecurityLevel.hpp"

#include <optional>
#include <string>

namespace Myelix::Security
{

    struct SecurityRecord
    {
        SecurityEvent event;
        SecurityLevel level;
        std::string message;
    };

    class SecurityManager final
    {
    public:
        explicit SecurityManager(Myelix::Core::Logging::Logger& logger);
        ~SecurityManager() = default;

        SecurityManager(const SecurityManager&) = delete;
        SecurityManager& operator=(const SecurityManager&) = delete;

        SecurityManager(SecurityManager&&) = delete;
        SecurityManager& operator=(SecurityManager&&) = delete;

        void Report(SecurityEvent event, SecurityLevel level, std::string message);

        [[nodiscard]]
        bool HasEvent() const noexcept;

        [[nodiscard]]
        const std::optional<SecurityRecord>& LastEvent() const noexcept;

        void Clear() noexcept;

    private:
        std::optional<SecurityRecord> m_lastEvent;
        Myelix::Core::Logging::Logger& m_logger;
    };

} // namespace Myelix::Security
