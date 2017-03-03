# -*- coding: utf-8 -*-
# Copyright (C) 2017 MUJIN Inc.
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
include_directories(include)
link_directories(${MUJINCLIENT_LINK_DIRS})
add_subdirectory(src)

file(GLOB mujin_header_files ${CMAKE_CURRENT_SOURCE_DIR}/include/mujincontrollerclient/*.h ${CMAKE_CURRENT_SOURCE_DIR}/include/mujincontrollerclient/*.hpp)
install(FILES ${mujin_header_files} DESTINATION include/mujincontrollerclient)
