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

#include <stdexcept>

#include "session.hpp"

#include "display.hpp"

namespace elysium {
namespace server {

Session *Session::kInstance = nullptr;

Session *Session::GetInstance() {
  return kInstance;
}

Session::Session(int argc, char **argv) {
  if (nullptr != kInstance)
    throw std::runtime_error("Error! There should be only one window manager instance!");

  kInstance = this;

  display_ = new Display;
}

Session::~Session() {
  delete display_;
}

int Session::Run() {
  while (true) {
    wl_event_loop_dispatch (display_->wl_event_loop_, 0);
//    backend_dispatch_nonblocking ();
    wl_display_flush_clients (display_->wl_display_);
//    if (redraw_needed) {
//      draw ();
//      redraw_needed = 0;
//    }
//    else {
//      backend_wait_for_events (wayland_fd);
//    }
  }

  return 0;
}

}
}
