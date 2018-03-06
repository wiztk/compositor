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

#ifndef ELYSIUM_SERVER_WINDOW_MANAGER_HPP_
#define ELYSIUM_SERVER_WINDOW_MANAGER_HPP_

namespace elysium {
namespace server {

class WindowManager {

 public:

  WindowManager() = delete;

 public:

  WindowManager(int argc, char *argv[]);

  ~WindowManager();

  int Run();

 private:

  static WindowManager *kInstance;

};

}
}

#endif // ELYSIUM_SERVER_WINDOW_MANAGER_HPP_
