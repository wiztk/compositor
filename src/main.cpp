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

/**
 * @file main.cpp
 * @brief The source file contains the main function.
 */

#include "elysium/server/session.hpp"

using namespace elysium;

/**
 * @brief The main function.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
  server::Session session(argc, argv);

  return session.Run();
}
