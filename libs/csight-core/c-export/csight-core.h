#pragma once

#include "bdsp.h"
#include "den.h"
#include "pk8.h"
#include "rng_tracker.h"
#include "swsh.h"
#include "trainer_info.h"
#include <switch.h>

#ifdef __cplusplus
namespace csight {
  extern "C" {
#endif
  typedef struct switch_reader switch_reader_t;

  void init();

#ifdef __cplusplus
  }
};
#endif
