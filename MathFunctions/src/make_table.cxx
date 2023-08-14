#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char const *argv[]) {
  int i;
  double result;

  if (argc < 2) {
    return 1;
  }
  std::string project_path = PROJECT_PATH;

  FILE *fout = fopen(argv[1], "w");
  auto flog = fopen(project_path.append("/logs/make_table.log").c_str(), "a");
  if (fout == NULL || flog == NULL) {
    std::cerr << "no such directory! " << argv[1] << std::endl;
    std::cerr << "or no such directory! " << project_path << std::endl;
    return 2;
  }

  printf("%s\n", argv[1]);
  fprintf(flog, "%s\n", argv[1]);

  fprintf(fout, "double sqrtTable[] = {\n");
  fprintf(flog, "double sqrtTable[] = {\n");
  for (i = 0; i < 10; ++i) {
    result = sqrt(static_cast<double>(i));
    fprintf(fout, "%g, \n", result);
    fprintf(flog, "%g, \n", result);
  }

  fprintf(fout, "0};\n");
  fprintf(flog, "0};\n");
  fclose(fout);
  fclose(flog);
  return 0;
}
