# luajs-interop
A bare-bones implementation of C Lua and Duktape JavaScript interoperability for future projects on the Nintendo Switch via libnx.

## Build Requirements
1. You must have devkitPro installed and configured for targeting the Nintendo Switch with the Libnx library. You can learn more about this toolchain and download it [here](https://devkitpro.org/wiki/Getting_Started).
2. Double check that your environment variables include both the path, usually `DEVKITPRO=/opt/devkitpro`, and if you're on Windows, that your Path has an entry for `<devkitPro's install directory>\msys2\usr\bin;...`. The installation process should take care of this for you, but these entries are the first place to check when you get messages similar to `X is not recognized as an internal or external command, operable program or batch file.`
3. Verify that `make` works by heading into `$DEVKITPRO/examples/switch/fs/sdmc` and running `make` in this directory. Every example that has a `Makefile` can be built to generate Nintendo Switch binaries, denoted with the `.nro` extension.

If you can build these projects by running make in a project's directory, you are able to clone this repository and build luajs-interop. This project is very early in its life, so set no expectations for what's to come. Feel free to learn from and base projects off of this demo by cloning this repository, just be sure to acknowledge the hard work of those who brought us Lua and Duktape and give credit where it's due. I don't need any credit, this project is a personal accomplishment of my own as it's the first C project of mine to ever compile with multiple includes!

## Project Structure
```
luajs-interop
\_ inc/
   \_ lua/
   \_ duktape/
   \_ global.h
\_ romfs/
   \_ init.lua, init.js, ...
\_ src/
   \_ headers/
      \_ iohelper.h, ...
   \_ main.c, iohelper.c, ...
\__ Build.bat
\__ Makefile
 ```

If you are having trouble understanding the project's structure, hopefully this quick explanation will help you out a `0b1`. Everything under `src/` is home-grown. This is where all the relevance of `luajs-interop` lives, in terms of the C language. The `inc/` directory is where I will eventually drop more open-source projects. The `global.h` header file is there to reduce the need for boiler-plate code, however, it's also responsible for including headers relative to its path on disk. Contents in the `romfs/` are required, as the program in its current state reads files from `romfs:/`, however, files can also be accessed relative to the binary's path without the `romfs:/` prefix.

Don't worry about `Build.bat` as it's just slightly more convenient at times than opening up a terminal (or command line) to run `make`. I recommend taking a peek at the `Makefile` to see how compilation was achieved by having both source and header files in two different locations.
