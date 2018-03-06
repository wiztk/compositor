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

#ifndef ELYSIUM_SHELL_HPP
#define ELYSIUM_SHELL_HPP

#include "abstract-global.hpp"

namespace elysium {
namespace server {

class Shell : public AbstractGlobal {

 public:

  Shell() = default;

  ~Shell() final = default;

 protected:

  struct wl_global *OnSetup(struct wl_display *display) final;

 private:

  static void Bind(struct wl_client *client, void *data, uint32_t version, uint32_t id);

  static struct wl_shell_interface kInstance;

  static void GetShellSurface(struct wl_client *client,
                              struct wl_resource *resource,
                              uint32_t id,
                              struct wl_resource *surface);
};

}
}

#endif //ELYSIUM_SHELL_HPP
