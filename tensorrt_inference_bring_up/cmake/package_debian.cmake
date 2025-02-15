# general cpack variables
set(CPACK_PACKAGE_CONTACT "Manh Ha Hoang <manhha1402@gmail.com>")

set(PROJECT_VERSION ${PROJECT_VERSION})
set(PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

# CPACK_PACKAGE_VERSION
set(EXTRA_PACKAGE_NAME "")

if(EXTRA_PACKAGE_NAME STREQUAL "")
  set(CPACK_PACKAGE_VERSION ${CPACK_PACKAGE_VERSION})
else()
  set(CPACK_PACKAGE_VERSION ${EXTRA_PACKAGE_NAME})
endif()

message(WARNING "CPACK_PACKAGE_VERSION: " ${CPACK_PACKAGE_VERSION})

# # add date stamp to CPACK_PACKAGE_VERSION
# string(TIMESTAMP STAMP "%Y%m%d+%H%M%S")
# set(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION}-0+${STAMP}")

# ##############################
# debian package specific stuff
# ##############################
set(CPACK_GENERATOR "DEB")

if(NOT CPACK_DEBIAN_PACKAGE_ARCHITECTURE)
  # if architecture is already set (e.g. to "all"), this is not needed
  # add ~distribution-codename (e.g. ~trusty or ~xenial) to end of package version
  # if lsb_release is available, take it from there or fall back to DISTRO_CODENAME env variable
  set(DISTRO_CODENAME $ENV{DISTRO_CODENAME})
  find_program(LSB_RELEASE_CMD lsb_release)
  mark_as_advanced(LSB_RELEASE_CMD)

  if(LSB_RELEASE_CMD)
    execute_process(COMMAND "${LSB_RELEASE_CMD}" --codename --short
      OUTPUT_VARIABLE DISTRO_CODENAME
      OUTPUT_STRIP_TRAILING_WHITESPACE)
  endif()

  # if(DISTRO_CODENAME)
  # set(CPACK_PACKAGE_VERSION ${CPACK_PACKAGE_VERSION}~${DISTRO_CODENAME})
  # else()
  # message(STATUS "Could not find lsb_release nor is DISTRO_CODENAME set.")
  # endif()
  find_program(DPKG_CMD dpkg)
  mark_as_advanced(DPKG_CMD)

  if(NOT DPKG_CMD)
    message(STATUS "Can not find dpkg in your path, default to i386.")
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE i386)
  else()
    execute_process(COMMAND "${DPKG_CMD}" --print-architecture
      OUTPUT_VARIABLE CPACK_DEBIAN_PACKAGE_ARCHITECTURE
      OUTPUT_STRIP_TRAILING_WHITESPACE)
  endif()
endif()

message(STATUS "CPACK_PACKAGE_VERSION: " ${CPACK_PACKAGE_VERSION})

# package name defaults to lower case of project name with _ replaced by -
if(NOT CPACK_PACKAGE_NAME)
  string(TOLOWER "${PROJECT_NAME}" PROJECT_NAME_LOWER)
  string(REPLACE "_" "-" CPACK_PACKAGE_NAME "${PROJECT_NAME_LOWER}")
endif()

message(STATUS "CPACK_PACKAGE_NAME: " ${CPACK_PACKAGE_NAME})

if(EXCLUSIVE_CUSTOMER)
  # use original name (without customer suffix) to declare the conflict
  set(CPACK_DEBIAN_PACKAGE_CONFLICTS ${CPACK_PACKAGE_NAME})
  set(CPACK_DEBIAN_PACKAGE_PROVIDES ${CPACK_PACKAGE_NAME})
  set(CPACK_DEBIAN_PACKAGE_REPLACES ${CPACK_PACKAGE_NAME})

  # use a name with the name of the customer suffixed to build the package
  string(TOLOWER "${EXCLUSIVE_CUSTOMER}" CUSTOMER_NAME_LOWER)
  string(REPLACE "_" "-" CUSTOMER_SUFFIX "${CUSTOMER_NAME_LOWER}")
  set(CPACK_PACKAGE_NAME "${CPACK_PACKAGE_NAME}-${CUSTOMER_SUFFIX}")
endif()

# set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}_${CPACK_PACKAGE_VERSION}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}")
# message(STATUS "CPACK_PACKAGE_FILE_NAME: " ${CPACK_PACKAGE_FILE_NAME})

# ########################################
# # things you might need to change ??? ##
# ########################################
# if this package doesn't provide any libs or binaries, add set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS OFF) in your main CMakeLists.txt
if(NOT DEFINED CPACK_DEBIAN_PACKAGE_SHLIBDEPS)
  set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
endif()

# ??? this defaults to PROJECT_LIBRARIES which should be defined in main CMakeLists.txt before including this file
# list of shared library this package provides (; separated, comment or empty list if there are none)
# IMPORTANT: also the lib needs to set SOVERSION via set_target_properties, e.g.:
if(PROJECT_LIBRARIES)
  set(sharedlibs ${PROJECT_LIBRARIES})
endif()

# if there are shared libs exported by this package:
# generate debian shlibs file and trigger ldconfig
if(sharedlibs)
  set(SHLIBS_FILE "${CMAKE_CURRENT_BINARY_DIR}/shlibs")
  set(TRIGGERS_FILE "${CMAKE_CURRENT_BINARY_DIR}/triggers")

  # Generate triggers file
  file(WRITE "${TRIGGERS_FILE}" "activate-noawait ldconfig\n")

  # Generate shlibs file
  # also the lib needs to set SOVERSION via set_target_properties:
  file(WRITE "${SHLIBS_FILE}" "")

  foreach(libname ${sharedlibs})
    get_target_property(so_abiversion ${libname} SOVERSION)

    if(NOT ${so_abiversion})
      set(so_abiversion ${abiversion})
      message(STATUS "SOVERSION of shared lib \"${libname}\" not set explicitly. Using <Major.Minor> of latest tag: ${so_abiversion}")
      set_target_properties(${libname} PROPERTIES SOVERSION ${so_abiversion})
    endif()

    file(APPEND "${SHLIBS_FILE}" "lib${libname} ${so_abiversion} ${CPACK_PACKAGE_NAME}\n")
  endforeach(libname)

  execute_process(COMMAND chmod 644 "${SHLIBS_FILE}" "${TRIGGERS_FILE}")
  set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${SHLIBS_FILE};${TRIGGERS_FILE}")
endif()

if(conffiles)
  set(CONFFILES_FILE "${CMAKE_CURRENT_BINARY_DIR}/conffiles")
  file(WRITE "${CONFFILES_FILE}" "")

  foreach(conffile ${conffiles})
    file(APPEND "${CONFFILES_FILE}" "${conffile}\n")
  endforeach(conffile)

  set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA};${CONFFILES_FILE}")
endif()

include(CPack)