# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_saifa_pack_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED saifa_pack_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(saifa_pack_FOUND FALSE)
  elseif(NOT saifa_pack_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(saifa_pack_FOUND FALSE)
  endif()
  return()
endif()
set(_saifa_pack_CONFIG_INCLUDED TRUE)

# output package information
if(NOT saifa_pack_FIND_QUIETLY)
  message(STATUS "Found saifa_pack: 0.0.0 (${saifa_pack_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'saifa_pack' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${saifa_pack_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(saifa_pack_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${saifa_pack_DIR}/${_extra}")
endforeach()
