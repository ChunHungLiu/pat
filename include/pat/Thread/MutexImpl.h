//===- MutexImpl.h --------------------------------------------------------===//
//
//                              The "pat" team 
//
// This file is distributed under the New BSD License.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef PAT_THREAD_MUTEX_IMPL_H
#define PAT_THREAD_MUTEX_IMPL_H
#include <pat/Config/Config.h>

//
//  W A R N I N G
//  -------------
//
// This file is not part of the pat API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//
//

//===----------------------------------------------------------------------===//
// MutexData
//===----------------------------------------------------------------------===//
#if defined(HAVE_PTHREAD)
#include <pthread.h>

namespace pat {

struct MutexData
{
  pthread_mutex_t mutex;
};

} /// namespace of pat
#endif

#endif
