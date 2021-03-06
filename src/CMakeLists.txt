# Copyright 2017 - 2018 The WizTK Authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(
        all_sources
        main.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(elysium/server)

add_executable(elysium ${all_sources})

target_link_libraries(
        elysium
        PUBLIC ${WAYLAND_SERVER_LIBRARIES}
        PUBLIC pthread
        PRIVATE elysium-server
        PRIVATE wiztk-base
        PRIVATE wiztk-async
)
