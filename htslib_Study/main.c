#include <htslib/hts.h>
#include <htslib/sam.h>
#include <htslib/vcf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "C_revise.h"
#include "dataReader.h"
#include "infoPrinter.h"
#include "myMacros.h"

// $ gcc *.c *.h -o test -lhts
// $ ./test [*.sam]|[*.vcf]

/**
 * A test set function. You can choose whether to test some methods or not
 * by annotating lines ...
 */
void IntegratedTestSet() { CReviseTestSet(); }

int main(int argc, char **argv) {
  printf("argc: %d\n", argc);
  for (int i = 0; i < argc; i++) {
    printf("argv[%d]: %s\n", i, argv[i]);
  }

  // Some test on C basics and other advanced functions
  IntegratedTestSet();

  // formal usage of htslib is as follows
  htsFile *inputFile;
  /*
   * "opts" is a structure that contains multiple arguments that can be
   * set when running the program using console. For now it is not used,
   * but in the long term, I shall keep it here.
   */
  Options opts;
  opts.fn_ref = NULL;
  opts.flag = 0;
  opts.clevel = -1;
  opts.ignore_sam_err = 0;
  opts.nreads = 0;
  opts.extra_hdr_nuls = 0;
  opts.benchmark = 0;
  opts.nthreads = 0;  // shared pool
  opts.multi_reg = 0;
  opts.index = NULL;
  opts.min_shift = 0;

  // Print usage manual of this file
  if (argc == 1) {
    fprintf(stderr, "Usage: main <*.vcf/bcf>|<*.sam/bam>\n");
    return EXIT_FAILURE;
  }

  inputFile = hts_open(argv[1], "r");
  int ret = 0;
  switch (hts_get_format(inputFile)->category) {
    case sequence_data:
      printf("This is a sam format file. \n");
      ret = sam_scan_and_print(inputFile, &opts);
      printf("... scan completed\n");
      break;
    case variant_data: {
      printf("This is a vcf format file. \n");
      ret = vcf_scan_and_print(inputFile, &opts);
      printf("... scan completed\n");
      break;
    }
    default:
      fprintf(stderr,
              "Unsupported or unknown category of data in input file\n");
      return EXIT_FAILURE;
  }
  return 0;
}
