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
        server_sources
        abstract-global.cpp
        abstract-global.hpp
        display.cpp
        display.hpp
        main-loop.cpp
        main-loop.hpp
        compositor.cpp
        compositor.hpp
        window-manager.cpp
        window-manager.hpp
        xdg-surface.cpp
        xdg-surface.hpp
        xdg-shell.cpp
        xdg-shell.hpp
        shell.cpp
        shell.hpp
        seat.cpp
        seat.hpp
)

add_library(elysium-server ${server_sources})

target_link_libraries(
        elysium-server
        PRIVATE xdg-shell-unstable-v6
        PRIVATE wiztk-base
        PRIVATE wiztk-async
)
