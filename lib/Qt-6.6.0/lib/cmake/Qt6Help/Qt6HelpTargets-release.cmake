#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Help" for configuration "Release"
set_property(TARGET Qt6::Help APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::Help PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/QtHelp.framework/Versions/A/QtHelp"
  IMPORTED_SONAME_RELEASE "@rpath/QtHelp.framework/Versions/A/QtHelp"
  )

list(APPEND _cmake_import_check_targets Qt6::Help )
list(APPEND _cmake_import_check_files_for_Qt6::Help "${_IMPORT_PREFIX}/lib/QtHelp.framework/Versions/A/QtHelp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
