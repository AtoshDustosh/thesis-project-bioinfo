#ifndef GRBVOPERATION_H_INCLUDED
#define GRBVOPERATION_H_INCLUDED

#pragma once

#include <htslib/hts.h>
#include <htslib/sam.h>
#include <htslib/vcf.h>

#include <inttypes.h>


#include "grbvOptions.h"



/**
 * @brief select reads with MAPQ lower than MAPQ_threshold from previously set sam file and then output them into the previously set output file
 */
void selectBadReads(Options *opts);

#endif