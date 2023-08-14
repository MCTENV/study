
#include <pcrecpp.h>

#include <cstdio>
#include <cstdlib>

#include "config/TutorialConfig.h"
#ifdef USE_MYMATH
#include "MathFunctions/my_math.h"
#else
#include <cmath>
#endif

// ^匹配开始，?重复0-1次
const char FP_RE[] = "^[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?";

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stdout, "%s Version %d.%d\n", argv[0] + 2, Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR);
    fprintf(stdout, "Usage: %s number\n", argv[0]);
    return 1;
  }
  pcrecpp::RE fpre(FP_RE);
  if (fpre.FullMatch(argv[1])) {
    double inputValue = strtod(argv[1], &(argv[1]) + strlen(argv[1]));
#ifdef USE_MYMATH
    fprintf(stdout, "use my math\n");
    double outputValue = my_sqrt(inputValue);
#else
    fprintf(stdout, "use sys math\n");
    double outputValue = sqrt(inputValue);
#endif
    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
  } else {
    fprintf(stdout, "Usage: .*number");
  }

#ifdef MY_MACRO
  fprintf(stdout, "my macro is %d\n", MY_MACRO);
#endif
  return 0;
}
