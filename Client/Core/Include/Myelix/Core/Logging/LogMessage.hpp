#pragma once

#include "Myelix/Core/Logging/LogLevel.hpp"

#include <string>

namespace Myelix::Core::Logging
{

    struct LogMessage
    {
        LogLevel level;
        std::string category;
        std::string message;
    };

} // namespace Myelix::Core::Logging
