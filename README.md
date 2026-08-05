# Myelix

> A premium native Windows AI Assistant built with Modern C++, Qt 6, and Clean Architecture.

---

## Vision

Myelix is a professional Windows AI assistant designed to provide:

- AI-powered productivity
- Secure automation
- Plugin extensibility
- Voice interaction
- Windows integration
- Enterprise-grade security

The project emphasizes maintainability, scalability, and security from day one.

---

## Technology Stack

| Component | Technology |
|-----------|------------|
| Language | C++20 |
| UI | Qt 6.11.1 (Widgets) |
| Build System | CMake |
| IDE | Visual Studio 2022 |
| Compiler | MSVC v143 |
| Database | PostgreSQL (Server) |
| Version Control | Git |

---

## Repository Structure

```text
Client/
Server/
Database/
Docs/
Installer/
Scripts/
Tests/
Build/
```

---

## Prerequisites

- Windows 10 Pro 22H2 or newer
- Visual Studio 2022 Community
- MSVC v143
- Qt 6.11.1 (MSVC 2022 x64)
- CMake 4.4.0
- Git
- Python 3.13+
- PostgreSQL 18+

---

## Configure

```powershell
cmake --preset vs2022-debug
```

## Build

```powershell
cmake --build --preset build-debug
```

---

## Development Workflow

Every feature follows this process:

1. Requirements
2. Architecture
3. Implementation
4. Build Verification
5. Testing
6. Review
7. Commit

---

## Roadmap

- Milestone 0 — Repository Foundation
- Phase 1 — Application Foundation
- Phase 2 — Navigation
- Phase 3 — Dashboard
- Phase 4 — Animations
- Phase 5 — Graphics

---

## License

See the `LICENSE` file.

---

## Security

See the `SECURITY.md` file.
