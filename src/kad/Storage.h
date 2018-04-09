/**
 *
 * MIT License
 * 
 * Copyright (c) 2018 drvcoin
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * =============================================================================
 */

#pragma once

#include <map>
#include <vector>
#include "Key.h"
#include "Buffer.h"
#include "PlatformUtils.h"

namespace kad
{
  class Storage
  {
  public:

    static Storage * Persist();

    static Storage * Cache();

  public:

    void Initialize(bool load);

    bool Save(KeyPtr key, BufferPtr content, int64_t ttl = 0);

    void Update(KeyPtr key, int64_t ttl = 0);

    BufferPtr Load(KeyPtr key) const;

    void Invalidate();

    void GetExpiredKeys(std::vector<KeyPtr> & result);

  private:

    Storage(TSTRING folder);

  private:

    static TSTRING Mkdir(const TCHAR * name);

  private:

    static Storage * persist;

    static Storage * cache;

  private:

    TSTRING folder;

    std::map<KeyPtr, int64_t, KeyCompare> index;

    std::multimap<int64_t, KeyPtr> rindex;
  };
}