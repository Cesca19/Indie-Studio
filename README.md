# Indie Studio

Indie studio is a cross platform game development Engine for 3D developpement in C++.

## The bomberman

Bomberman is one of the most famous video games of all time. With over 70 franchises, ranging from the first version on MSX, ZX Spectrum and Sharp MZ-700 in 1983 to the latest versions on modern consoles, over 10 million units have been sold. Our gameplay reference is Neo Bomberman, released on the Neo Geo and MVS systems in 1997.

## Technology

Our Engine use the Enity-Component-System concept and the raylib, a very simple C library for 2D/3D graphics. 

## AUTHORS

* [Femi FACIA](https://github.com/femifacia)
* [Georges HOUMBADJI](https://github.com/GeorgesML)
* [Damia Tobossi](https://github.com/lareey)
* [Francesca ATTINDEHOU](https://github.com/Cesca19)

## HOW TO INSTALL

### REQUIREMENT

* You must have **cmake 3.17 at least** installed
* You must have a **compiler** installed (windows: **Visual Studio 15 2017**, unix: **g++**)
* You must have enabled **Raylib** installed on your windows system

## HOW TO COMPILE
* On Linux


      mkdir build && cd build && cmake ../ -G 'Unix Makefiles' && cmake –build . 


* On Windows

      mkdir build && cd build && cmake ../ && cmake –build .

## HOW TO EXECUTE

    cd build && ./bomberman
