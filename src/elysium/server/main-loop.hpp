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

namespace elysium {
namespace server {

class Display;

class MainLoop : public wiztk::async::EventLoop {

 public:

  MainLoop(Display *display)
      : display_(display) {}

  ~MainLoop() final = default;

 protected:

  void DispatchMessage() override;

 private:

  Display *display_ = nullptr;

};

}
}

#endif // ELYSIUM_SERVER_MAIN_LOOP_HPP_
