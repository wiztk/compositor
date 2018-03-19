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
#include <sys/stat.h>
#include <unistd.h>

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

  try {
    runtime_dir_ = GetRuntimeDir();
  } catch (const std::runtime_error &err) {
    throw err;
  }

  display_ = new Display;

  main_loop_ = MainLoop::Initialize(display_);
}

Session::~Session() {
  delete main_loop_;
  delete display_;
}

int Session::Run() {
//  main_loop_->Run();
  display_->Run();

  return 0;
}

std::string Session::GetRuntimeDir() {
  char *dir = getenv("XDG_RUNTIME_DIR");
  if (nullptr == dir)
    throw std::runtime_error("Fatal! Environment variable XDG_RUNTIME_DIR is not set!");

  struct stat s;

  if (stat(dir, &s) || (!S_ISDIR(s.st_mode))) {
    throw std::runtime_error("Fatal! XDG_RUNTIME_DIR is not a directory!");
  }

  if ((s.st_mode & 0777) != 0700 || s.st_uid != getuid()) {
    throw std::runtime_error("Fatal! No permission to use XDG_RUNTIME_DIR!");
  }

  return std::string(dir);
}

}  // namespace server
}  // namespace elysium
