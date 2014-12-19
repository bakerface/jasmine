/*
 * Copyright (c) 2014 Christopher M. Baker
 *
 */

#ifndef JASMINE_H
#define JASMINE_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
  S_BEFORE,
  S_AFTER,
  S_IT,
  S_DONE,
  G_IGNORE,
  G_PASS,
  G_FAIL
};

struct {
  const char *r;
  unsigned s, g, c, l, a;
} _;

#define describe(x) \
for (_.s = S_BEFORE, _.a = _.c = _.l = 0, puts(x); _.s != S_DONE; \
  _.s = (_.a == 0 && _.s == S_BEFORE && ++_.a ? S_IT : _.s), \
  _.s = (_.a == 0 && _.s == S_AFTER && _.c == _.l ? S_DONE : _.s), \
  _.s = (_.a == 0 && _.s == S_AFTER && _.c != _.l ? S_BEFORE : _.s), \
  _.s = (_.a == 0 && _.s == S_IT ? S_AFTER : _.s), \
  _.a = 0)

#define before \
for (; _.s == S_BEFORE && ++_.a; _.s = S_IT)

#define after \
for (; _.s == S_AFTER && ++_.a; _.s = (_.c == _.l ? S_DONE : S_BEFORE))

#define it(x) \
for (_.g = G_IGNORE, _.l = (_.l > __LINE__ ? _.l : __LINE__); \
  _.s == S_IT && _.c < __LINE__ && __LINE__ == (_.c = __LINE__) && ++_.a; \
  _.s = S_AFTER, \
  _.g == G_IGNORE ? puts("  [ ] " x) : 0, \
  _.g == G_PASS ? puts("  [+] " x) : 0, \
  _.g == G_FAIL ? printf("  [-] " x ", expected: %s\n", _.r) : 0)

#define expect(x) \
if (x) { \
  _.g = G_PASS; \
} \
else { \
  _.g = G_FAIL; \
  _.r = #x; \
  continue; \
}

#ifdef __cplusplus
}
#endif

#endif /* JASMINE_H */

