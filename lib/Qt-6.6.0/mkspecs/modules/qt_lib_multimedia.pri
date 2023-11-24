QT.multimedia.VERSION = 6.6.0
QT.multimedia.name = QtMultimedia
QT.multimedia.module = QtMultimedia
QT.multimedia.libs = $$QT_MODULE_LIB_BASE
QT.multimedia.ldflags = 
QT.multimedia.includes = $$QT_MODULE_LIB_BASE/QtMultimedia.framework/Headers
QT.multimedia.frameworks = $$QT_MODULE_LIB_BASE
QT.multimedia.bins = $$QT_MODULE_BIN_BASE
QT.multimedia.plugin_types = multimedia
QT.multimedia.depends =  core gui network
QT.multimedia.uses = 
QT.multimedia.module_config = v2 lib_bundle
QT.multimedia.DEFINES = QT_MULTIMEDIA_LIB
QT.multimedia.enabled_features = avfoundation coreaudio videotoolbox
QT.multimedia.disabled_features = alsa evr mmrenderer pulseaudio
QT_CONFIG += avfoundation coreaudio videotoolbox
QT_MODULES += multimedia

