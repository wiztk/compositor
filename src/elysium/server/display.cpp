/*
 * Copyright 2017 - 2018 The WizTK Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cstdio>
#include "display.hpp"

#include "compositor.hpp"
#include "shell.hpp"
#include "xdg-shell.hpp"
#include "seat.hpp"

namespace elysium {
namespace server {

Display::Display() {
  wl_display_ = wl_display_create();
  wl_display_add_socket_auto(wl_display_);

  wl_event_loop_ = wl_display_get_event_loop(wl_display_);

  fd_ = wl_event_loop_get_fd(wl_event_loop_);

  compositor_ = Compositor::Create<Compositor>(this);
  shell_ = Shell::Create<Shell>(this);
  xdg_shell_ = XdgShell::Create<XdgShell>(this);
  seat_ = Seat::Create<Seat>(this);

  wl_display_init_shm(wl_display_);
}

Display::~Display() {
  seat_.reset();
  xdg_shell_.reset();
  shell_.reset();
  compositor_.reset();

  if (nullptr != wl_display_) {
    wl_event_loop_destroy(wl_event_loop_);
    wl_display_destroy(wl_display_);
  }
}

void Display::Destroy() {
  if (nullptr != wl_display_) {
    wl_display_destroy(wl_display_);
    wl_display_ = nullptr;
  }
}

}
}
