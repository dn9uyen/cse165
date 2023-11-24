QT_ARCH = arm64
QT_BUILDABI = arm64-little_endian-lp64
QT_LIBCPP_ABI_TAG = 
QT.global.enabled_features = shared rpath framework signaling_nan thread future concurrent dbus shared shared rpath reduce_exports
QT.global.disabled_features = static cross_compile pkg-config debug_and_release separate_debug_info appstore-compliant simulator_and_device force_asserts c++20 c++2a c++2b c++2b reduce_relocations wasm-simd128 wasm-exceptions zstd openssl-linked opensslv11 opensslv30
QT.global.disabled_features += release build_all
QT_CONFIG += shared no-pkg-config rpath qt_framework reduce_exports release
CONFIG += release  shared qt_framework plugin_manifest
QT_VERSION = 6.6.0
QT_MAJOR_VERSION = 6
QT_MINOR_VERSION = 6
QT_PATCH_VERSION = 0

QT_APPLE_CLANG_MAJOR_VERSION = 14
QT_APPLE_CLANG_MINOR_VERSION = 0
QT_APPLE_CLANG_PATCH_VERSION = 0
QT_MAC_SDK_VERSION = 13.1
QMAKE_MACOSX_DEPLOYMENT_TARGET = 11.0
QT_ARCHS = $$QT_ARCH
QT_EDITION = Open Source