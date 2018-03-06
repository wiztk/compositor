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
#include "window-manager.hpp"

namespace elysium {
namespace server {

WindowManager *WindowManager::kInstance = nullptr;

WindowManager::WindowManager(int argc, char **argv) {
  if (nullptr != kInstance)
    throw std::runtime_error("Error! There should be only one window manager instance!");

  kInstance = this;
}

WindowManager::~WindowManager() {

}

int WindowManager::Run() {
  return 0;
}

}
}