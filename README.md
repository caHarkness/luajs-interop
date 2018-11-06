# luajs-interop
A bare-bones implementation of C Lua and Duktape JavaScript interoperability for future projects on the Nintendo Switch via libnx. You can run both Lua and JavaScript in tandem on your Nintendo Switch.

## Key Features
(What this project demonstrates for the beginner C programmer)

1. Segregated code base (Keeping relevant source code away from dependencies and includes)
2. Lambda "function literals" and anonymous function definitions
3. Basic execution stepping functionality for debugging
4. Reading entire files into memory with file streams
5. Interoperability between C Language, Lua, and JavaScript
6. Source code organization (Encouraging code-relevance and modular design)
7. In-depth commenting and code explanation

## Build Requirements

1. You must have devkitPro installed; download it [here](https://devkitpro.org/wiki/Getting_Started).
2. Environment variables include both the toolchain's root, usually `DEVKITPRO=/opt/devkitpro`, and if you're on Windows, an entry for `<devkitPro's install directory>\msys2\usr\bin;...`.
3. Verify that `make` works by heading into `$DEVKITPRO/examples/switch/fs/sdmc` and running `make` in this directory.
