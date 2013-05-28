jasmine
=======

A port of the Jasmine test framework to ANSI C

int main(void) {
  jasmine_t jasmine;
	jasmine_init(&jasmine);
  
  /* run each of the tests here */
	example_test(&jasmine);

	printf("\r\njasmine: %u passed, %u failed\r\n", jasmine.passed, jasmine.failed);
	return jasmine.failed;
}

void example_test(jasmine_t *jasmine) {
  example_t example;

	jasmine_describe(jasmine, "an example") {
		jasmine_before(jasmine) {
      /* this will get called once before each 'it' */
			example_new(&example);
		}

		jasmine_after(jasmine) {
      /* this will get called once after each 'it' */
      example_free(&example);
		}

		jasmine_it(jasmine, "should be able to pass") {
      /* this will get called first */
			jasmine_expect(jasmine, 1 == 1);
		}

		jasmine_it(jasmine, "should be able to fail") {
      /* this will get called second */
			jasmine_expect(jasmine, 0 == 1);
		}
	}
}
