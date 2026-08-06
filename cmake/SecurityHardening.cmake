include_guard(GLOBAL)

function(myelix_enable_security TARGET)

    if(MSVC)

        target_compile_options(${TARGET} PRIVATE

            # Buffer Security Check
            /GS

            # SDL checks
            /sdl

            # Control Flow Guard
            /guard:cf

            # Strict C++
            /permissive-

            # Enable __cplusplus correctly
            /Zc:__cplusplus

            # Strict conformance
            /Zc:preprocessor
            /Zc:inline
            /Zc:wchar_t

            # Spectre mitigation (if installed)
            /Qspectre

            # Warnings
            /W4

            # Treat warnings as errors (optional)
            # /WX
        )

        target_link_options(${TARGET} PRIVATE

            # Control Flow Guard
            /guard:cf

            # ASLR
            /DYNAMICBASE

            # DEP
            /NXCOMPAT

            # High entropy ASLR
            /HIGHENTROPYVA

            # CET Shadow Stack (VS2022)
            /CETCOMPAT
        )

    elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")

        target_compile_options(${TARGET} PRIVATE

            -Wall
            -Wextra
            -Wpedantic

            -fstack-protector-strong
            -fstack-clash-protection

            -D_FORTIFY_SOURCE=3

            -fcf-protection=full
        )

        target_link_options(${TARGET} PRIVATE

            -Wl,-z,relro
            -Wl,-z,now
            -Wl,-z,noexecstack
        )

    endif()

endfunction()
