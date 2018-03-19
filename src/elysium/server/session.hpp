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

#ifndef ELYSIUM_SERVER_SESSION_HPP_
#define ELYSIUM_SERVER_SESSION_HPP_

#include "main-loop.hpp"

namespace elysium {
namespace server {

class Display;

/**
 * @ingroup elysium_server
 * @brief A session represents a singleton wayland server instance.
 */
class Session {

 public:

  /**
   * @brief Disable the defautl constructor
   */
  Session() = delete;

 public:

  /**
   * @brief Get the instance of a session.
   */
  static Session *GetInstance();

  /**
   * @brief Constructor to create a Session and register it as the singleton
   * instance.
   */
  Session(int argc, char *argv[]);

  /**
   * @brief Destructor.
   */
  ~Session();

  int Run();

  /**
   * @brief Get the server-side display object.
   */
  Display *GetDisplay() const {
    return display_;
  }

  const std::string &runtime_dir() const {
    return runtime_dir_;
  }

 private:

  static std::string GetRuntimeDir();

  Display *display_ = nullptr;

  MainLoop *main_loop_ = nullptr;

  std::string runtime_dir_;

  static Session *kInstance;

};

}  // namespace server
}  // namespace elysium

#endif // ELYSIUM_SERVER_SESSION_HPP_
