#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::SpatialAudio" for configuration "Release"
set_property(TARGET Qt6::SpatialAudio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::SpatialAudio PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/QtSpatialAudio.framework/Versions/A/QtSpatialAudio"
  IMPORTED_SONAME_RELEASE "@rpath/QtSpatialAudio.framework/Versions/A/QtSpatialAudio"
  )

list(APPEND _cmake_import_check_targets Qt6::SpatialAudio )
list(APPEND _cmake_import_check_files_for_Qt6::SpatialAudio "${_IMPORT_PREFIX}/lib/QtSpatialAudio.framework/Versions/A/QtSpatialAudio" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
