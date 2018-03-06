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

#include "abstract-global.hpp"
#include "display.hpp"

namespace elysium {
namespace server {

AbstractGlobal::~AbstractGlobal() {
  if (nullptr != wl_global_)
    wl_global_destroy(wl_global_);
}

void AbstractGlobal::Setup(Display *display) {
  Destroy();

  wl_global_ = OnSetup(display->wl_display_);
}

void AbstractGlobal::Destroy() {
  if (nullptr != wl_global_) {
    wl_global_destroy(wl_global_);
    wl_global_ = nullptr;
  }
}

}
}