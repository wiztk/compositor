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

#include "session.hpp"

namespace elysium {
namespace server {

MainLoop *MainLoop::Initialize(Display *display) {
  MainLoop *main_loop = nullptr;
  try {
    main_loop = static_cast<MainLoop *>(Create([&]() -> wiztk::async::EventLoop * {
      return new MainLoop(display);
    }));
  } catch (const std::runtime_error &err) {
    throw err;
  }

  main_loop->wl_event_loop_ = wl_display_get_event_loop(display->wl_display_);
  main_loop->fd_ = wl_event_loop_get_fd(main_loop->wl_event_loop_);

//  main_loop->WatchFileDescriptor(main_loop->fd_,
//                                 &main_loop->display_event_,
//                                 EPOLLIN | EPOLLOUT | EPOLLERR | EPOLLHUP);

  return main_loop;
}

MainLoop::~MainLoop() {
  wl_event_loop_destroy(wl_event_loop_);
}

void MainLoop::DispatchMessage() {
  wiztk::async::EventLoop::DispatchMessage();

  wl_event_loop_dispatch(wl_event_loop_, 0);
  wl_display_flush_clients(display_->wl_display_);
}

// ----

void MainLoop::DisplayEvent::Run(uint32_t events) {
  printf("%s\n", __FUNCTION__);

}

}
}
