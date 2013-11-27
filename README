GestureDetector
===============

Make OpenCV work on your Xcode:
1. Start a new XCode Command Line Tool project.
2. Rght click on the project, and click “Add files to..”
3. When Finder pops up, hit “/” to bring up the navigation panel.
4. Type in /usr/local/lib
5. Add in all the .dylib files that you need. To prevent linker errors, I recommend you
   initially add ALL the files ending in “…2.4.0.dylib”. Now, you should have a bunch
   of .dylib files in your project. Feel free to move them to a separate group within your 
   project.
6. Click on the project file and go to “Build Settings”.
7. Search for “Header Search Paths”, and change the path to "/usr/local/include".
8. Search for "Library Search Paths", and change the path to "/usr/local/lib”.
9. [For Xcode 5] Search for “C++ Standard Library”, and change to “libstdc++ (GNU C++
   standard library”.
