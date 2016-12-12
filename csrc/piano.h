#ifndef __PIANO_H
#define __PIANO_H

#if CABAL
#include "anemone_base.h"
#else
#include "../lib/anemone/csrc/anemone_base.h"
#endif

typedef struct piano_section32 {
    int32_t offset;
    int32_t length;
} piano_section32_t;

typedef struct piano {
    piano_section32_t *buckets;

    int32_t count;
    uint32_t *hashes;

    piano_section32_t *id_sections;
    uint8_t *id_data;

    piano_section32_t *time_sections;
    int64_t *time_data;
} piano_t;

error_t piano_lookup (
    piano_t *piano
  , const uint8_t *needle_id
  , size_t needle_id_size
  , int64_t *out_count
  , const int64_t **out_times
  );

#endif//__PIANO_H
