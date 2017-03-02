# -*- coding: utf-8 -*-
# Copyright (C) 2012-2013 MUJIN Inc. <rosen.diankov@mujin.co.jp>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
include_directories(${CURL_INCLUDE_DIRS} ${LOG4CXX_INCLUDEDIR})
link_directories(${MUJINCLIENT_LINK_DIRS})

set(SOURCE_FILES controllerclientimpl.cpp  controllerclientimpl.h  logging.h  mujincontrollerclientmock.cpp)

add_library(libmujincontrollerclientmock SHARED ${SOURCE_FILES})
if( EXTRA_MSVC_DEPEND )
  message(STATUS "adding msvc_boost dependency")
  add_dependencies(libmujincontrollerclientmock ${EXTRA_MSVC_DEPEND})
endif()
set_target_properties(libmujincontrollerclientmock PROPERTIES COMPILE_FLAGS "${EXTRA_COMPILE_FLAGS} ${Boost_CFLAGS} -DMUJINCLIENT_DLL_EXPORTS -DMUJINCLIENT_DLL" LINK_FLAGS ""
  OUTPUT_NAME mujincontrollerclientmock${MUJINCLIENT_LIBRARY_SUFFIX}
  SOVERSION 0 # always have it 0 since we're including the soversion as part of the library name
  VERSION ${MUJINCLIENT_VERSION}
  CLEAN_DIRECT_OUTPUT 1
  )

target_link_libraries(libmujincontrollerclientmock ${LOG4CXX_LIBRARIES})
if( MSVC )
  install(TARGETS libmujincontrollerclientmock RUNTIME DESTINATION bin LIBRARY DESTINATION bin ARCHIVE DESTINATION lib${LIB_SUFFIX})
else()
  install(TARGETS libmujincontrollerclientmock DESTINATION lib${LIB_SUFFIX})
endif()

if( OPT_BUILD_STATIC )
  # visual studio needs static lib built
  if( MSVC )
    # static version needs to have different name
    set(LIBMUJINCONTROLLERCLIENTMOCK_NAME libmujincontrollerclientmock${MUJINCLIENT_LIBRARY_SUFFIX})
  else()
    set(LIBMUJINCONTROLLERCLIENTMOCK_NAME mujincontrollerclientmock${MUJINCLIENT_LIBRARY_SUFFIX})
  endif()

  add_library(libmujincontrollerclientmock_static STATIC ${SOURCE_FILES})
  set_target_properties(libmujincontrollerclientmock_static PROPERTIES OUTPUT_NAME ${LIBMUJINCONTROLLERCLIENTMOCK_NAME}
                                           SOVERSION 0 # always have it 0 since we're including the soversion as part of the library name
                                           VERSION ${MUJINCLIENT_VERSION}
                                           CLEAN_DIRECT_OUTPUT 1
                                           COMPILE_FLAGS "${EXTRA_COMPILE_FLAGS} ${Boost_CFLAGS} -DMUJINCLIENT_DLL_EXPORTS -DMUJINCLIENT_DLL"
                                           LINK_FLAGS "")
  
  target_link_libraries(libmujincontrollerclientmock_static ${LOG4CXX_LIBRARIES})
  install(TARGETS libmujincontrollerclientmock_static DESTINATION lib${LIB_SUFFIX})
endif()
