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

#include "main-loop.hpp"
#include "display.hpp"

namespace elysium {
namespace server {

void MainLoop::DispatchMessage() {
  wiztk::async::EventLoop::DispatchMessage();

  wl_event_loop_dispatch(display_->wl_event_loop_, 0);
  wl_display_flush_clients(display_->wl_display_);
}

}
}