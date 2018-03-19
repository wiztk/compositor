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

#ifndef ELYSIUM_SERVER_MAIN_LOOP_HPP_
#define ELYSIUM_SERVER_MAIN_LOOP_HPP_

#include "wiztk/async/event-loop.hpp"

#include <wayland-server.h>

namespace elysium {
namespace server {

class Display;

class MainLoop : public wiztk::async::EventLoop {

 public:

  static MainLoop *Initialize(Display *display);

  ~MainLoop() final;

 protected:

  explicit MainLoop(Display *display)
      : display_(display), display_event_(this) {}

  void DispatchMessage() final;

 private:

  class DisplayEvent : public wiztk::async::AbstractEvent {

   public:

    explicit DisplayEvent(MainLoop *mainloop)
        : main_loop(mainloop) {}

    ~DisplayEvent() final = default;

   protected:

    void Run(uint32_t events) final;

   private:
    MainLoop *main_loop = nullptr;
  };

  Display *display_ = nullptr;

  struct wl_event_loop *wl_event_loop_ = nullptr;

  int fd_ = -1;

  DisplayEvent display_event_;

};

}
}

#endif // ELYSIUM_SERVER_MAIN_LOOP_HPP_
