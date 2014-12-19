# jasmine

A port of the Jasmine test framework to ANSI C.
This test framework is intended to be a minimalistic, bare-bones framework.
In fact, the framework only consists of a single header file that contains a few macros.
A simple example for how to use the framework is below.

~~~ c
#include "jasmine.h"

int main(void) {
  describe("a test") {
    
    /* optional: called before each 'it' */
    before {
      i = 0;
    }

    /* optional: called after each 'it' */
    after {
      i++;
    }

    it("should be able to pass") {
      expect(i == 0);
    }

    it("should be able to fail") {
      expect(i == 1);
    }

    it("should be able to ignore") {

    }
  }

	return 0;
}
~~~

Running the example will output each test with a pass, fail, or ignore.

```
a test
 [+] should be able to pass
 [-] should be able to fail, expected: i == 1
 [ ] should be able to ignore
```
