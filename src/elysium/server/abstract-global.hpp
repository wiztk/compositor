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

#ifndef ELYSIUM_SERVER_ABSTRACT_GLOBAL_HPP_
#define ELYSIUM_SERVER_ABSTRACT_GLOBAL_HPP_

#include <memory>

#include <wayland-server.h>

namespace elysium {
namespace server {

class Display;

/**
 * @ingroup elysium_server
 * @brief Abstract class represents a server-side global object.
 */
class AbstractGlobal {

 public:

  template<typename T>
  static std::unique_ptr<T> Create(Display *display);

  AbstractGlobal() = default;

  virtual ~AbstractGlobal();

  void Setup(Display *display);

  void Destroy();

 protected:

  virtual struct wl_global *OnSetup(struct wl_display *display) = 0;

 private:

  struct wl_global *wl_global_ = nullptr;

};

template<typename T>
std::unique_ptr<T> AbstractGlobal::Create(Display *display) {
  auto ptr = std::make_unique<T>();
  ptr->Setup(display);
  return ptr;
}

} // namespace server
} // namespace elysium

#endif // ELYSIUM_SERVER_ABSTRACT_GLOBAL_HPP_
