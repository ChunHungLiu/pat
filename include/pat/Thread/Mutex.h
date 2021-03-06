//===- Mutex.h ------------------------------------------------------------===//
//
//                              The "pat" team 
//
// This file is distributed under the New BSD License.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef PAT_MUTEX_H
#define PAT_MUTEX_H
#include <pat/ADT/Uncopyable.h>

namespace pat {

class MutexData;
class WaitCondition;

/** \class Mutex
 *  \brief The Mutex class provides access serialization between threads.
 */
class Mutex : private Uncopyable
{
public:
  enum Status {
    Success,
    Busy,
    Invalid,
    UnknownError
  };

public:
  Mutex();

  ~Mutex();

  void lock() throw();

  void unlock() throw();

  Status tryLock() throw();

private:
  friend class WaitCondition;

  const MutexData* data() const { return m_pData; }
  MutexData*       data()       { return m_pData; }

private:
  mutable MutexData* m_pData;
};

/** \class ScopedLock
 *  \brief ScopedLock defines a scope as a mutual-execlusive region.
 */
class ScopedLock : private Uncopyable
{
public:
  ScopedLock(Mutex& pMutex) : m_Mutex(pMutex) { m_Mutex.lock(); }

  ~ScopedLock() { m_Mutex.unlock(); }

private:
  Mutex& m_Mutex;
};

} // namespace of pat

#endif
