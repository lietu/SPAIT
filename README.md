# About SPAIT

SPAIT is short for S/PDIF Anti-Idle Tool, and it simply prevents your digital sound equipment from going to "sleep mode" when they detect no sound playing. How does it accomplish this awesome feat? Simply by playing a constant sound at a very low volume.

It was created by Lietu (http://lietu.net), because his Logitech Z-5500 set connected to Asus Xonar Essence STX over fiber optic S/PDIF, keeps going to sleep mode whenever the sound from the computer stops and it takes a while for it to wake up again when sound does start playing causing notification sounds etc. to be completely lost. 


## Used technologies

SPAIT is written in C++ and uses Qt to play sound and to dock to the tray, it should also be 100% compatible with Windows, Mac OS X, and any freedesktop standards compatible Linux desktop environment. It was created with Qt Creator, so it is probably the easiest tool to build SPAIT with.

## Building SPAIT

### Windows

Building itself doesn't really need much in Qt Creator, it is pretty straight forward, but to get the executable to actually work outside of Qt Creator, you will need a bunch of libraries to go along with it.

To get the release build running, you need to copy the following libraries to the folder with the executable:
- libgcc_s_dw2-1.dll
- mingwm10.dll
- QtCore4.dll
- QtDeclarative4.dll
- QtGui4.dll
- QtNetwork4.dll
- QtScript4.dll
- QtSql4.dll
- QtSvg4.dll (not strictly necessary, but the icon is SVG and won't be visible without this)
- QtXmlPatterns4.dll

Most of them you can find under C:\QtSDK\QtCreator\bin, some under C:\QtSDK\mingw\bin. Also you need to copy the folder "sound" with the executable, as it seems Qt can't bundle sound files in the executables for some stupid reason.

# Licensing

## Source
Source code distributed with new BSD and MIT licenses, more information in the file LICENSE.

## Graphics and sound
The icon is based on an icon by Dmitry Baranovskiy (http://raphaeljs.com/icons/), which was distributed under the MIT license, the modified version will continue to carry the same license.
Super awesome noise file generated with Audacity by Lietu (http://lietu.net/), distributed with WTFPL v2 license (http://sam.zoy.org/wtfpl/). The license is also in the file LICENSE under the sound directory.
