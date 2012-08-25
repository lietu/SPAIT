# The .cpp files for the project
SOURCES += main.cpp \
    spait.cpp \
    dialog.cpp

HEADERS += \
    spait.h \
    dialog.h

RESOURCES = spait.qrc

OTHER_FILES += \
    icon/sound.svg

# Deploy the sound files
soundFiles.sources = sound/sound.wav
soundFiles.path = sound/
DEPLOYMENT += soundFiles
