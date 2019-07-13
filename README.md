# DevilutionM

## Synopsis
This is an ported version of Devilution(see link below) to Android. 



## important notes:
It doesn't 100% work yet but free free to ask any question and if I know, it will answer it . I have spent a lot of time on this and pretty well know the code flow. Some important things to note for this is that android by default has unsigned chars makes things weird.


## Requirements
- JDK and JRE 8
- Android SDK and NDK (with Android Build-tools 28.0.3 and Android Platform API 28, though these are configurable)
- ANDROID_HOME and ANDROID_NDK_HOME environment variables set (I did this in /etc/environment)
- diablodat.mpq from your Diablo game (GoG version should be fine.)
- prealpha.mpq from the publicly available resource [Diablo Prealpha](https://diablo-evolution.net/files/prereleasedemo.7z) 
- Download the SDL dependancies 

 Download the dependencies (SDL2 and SDL2_image SDL2_mixer) as above or manually like below. Then open the ./android folder as an existing project in Android Studio.
 
## Downloading NDK manually
I found that NDK 12B was the last version of NDK to support GCC. This is what so far works for compiling DevilutionX. 

- [Windows 32-bit](https://dl.google.com/android/repository/android-ndk-r12b-windows-x86.zip) 
- [Windows 64-bit](https://dl.google.com/android/repository/android-ndk-r12b-windows-x86_64.zip)
- [Mac OS X 64-bit](https://dl.google.com/android/repository/android-ndk-r12b-darwin-x86_64.zip)
- [Linux 64-bit](https://dl.google.com/android/repository/android-ndk-r12b-linux-x86_64.zip)


## Downloading dependencies manually

Download the latest source release from SDL and SDL_image websites:

https://www.libsdl.org/download-2.0.php
https://www.libsdl.org/projects/SDL_image/

Unzip it, put the SDL2-x.x.x and SDL2_image-x.x.x folders in `external/SDL2` and rename them to SDL2 and SDL2_image so your project folder looks like this:
```
+ android
+ external
| + SDL2
| | + Android.mk
| | | SDL2
| | | SDL2_image
```

## Compiling the sample program (command line)

You can download the dependencies (SDL2 SDL2_mixer and SDL2_image), compile your program and then install it on a connected device with the following commands:
```
./get_dependencies
cd android
./gradlew assembleDebug
./gradlew installDebug
```
On YOUR ANDROID DEVICE do the following:
- Make a folder Diablo in /sdcard/
- Rename DIABDAT.MPQ from the [DIABLO PREALPHA](https://diablo-evolution.net/files/prereleasedemo.7z)(LOWERCASE) prealpha.mpq
- Copy prealpha.mpq to /sdcard/Diablo/
- Copy the Diabdat.mpq from your GOG CD or Diablo Disk to /sdcard/Diablo/

## similar projects
This is an old version of Devilution which compiles using the GCC compiler. 
[Devilution - The Main Project](https://github.com/diasurgical/devilution) 
[AnDroidDiablo - Project Using Old Code](https://github.com/ApertureSecurity/AnDroidablo)
[DevilutionX   - More Modern Project](https://github.com/diasurgical/devilutionX)


## Compiling the sample program (Android Studio)
- Install Android Studio
- install the Android SDK in a directory E.G /home/YOURUSER/Sdk/
- Download the last version of the NDK supporting GCC here 
- Install the NDK package and unzip it in the /home/YOURUSER/sdk/
- Make and Edit the local.properties file in your /PROJECT/android/ and add the following lines.

```
sdk.dir = /home/YOURUSER/Android/Sdk/
ndk.dir = /home/YOURUSER/Android/Sdk/android-ndk-r12b/
```
Then... compile and install 
```
cd android
./gradlew assembleDebug
./gradlew installDebug
```

There, it's done!

## Thanks



Most of the code here is inspired by these repositories:
This helo world android template.
https://github.com/pvallet/hello-sdl2-android/tree/master/android
https://github.com/stephen47/android-sdl2-gradle-template (Android + gradle)
https://github.com/suikki/simpleSDL/ (Android + CMake)
The example libSDL2 program which draws the square on screen was found at https://stackoverflow.com/questions/21890627/drawing-a-rectangle-with-sdl2/21903973#21903973.

The Google NDK example projects were very helpful: https://github.com/googlesamples/android-ndk
# AnDroidablo
