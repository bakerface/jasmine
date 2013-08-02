jasmine
=======

A port of the Jasmine test framework to ANSI C.
This test framework is intended to be a minimalistic, bare-bones framework.
In fact, the framework only consists of a single header file that contains a few macros.
A simple example for how to use the framework is below.

~~~~ c
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
			jasmine_expect(jasmine, example_pass(&example));
		}

		jasmine_it(jasmine, "should be able to fail") {
			/* this will get called second */
			jasmine_expect(jasmine, example_fail(&example));
		}
		
		jasmine_it(jasmine, "should be able to ignore") {
			/* this will get called third */
			/* there is no expect in here so the test is ignored */
		}
	}
}

int main(void) {
	jasmine_t jasmine;
	jasmine_init(&jasmine);
  
  	/* run each of the tests here */
	example_test(&jasmine);

	printf("jasmine: %u passed, %u failed, %u ignored, %u expects\r\n",
        	jasmine.passed, jasmine.failed, jasmine.ignored, jasmine.expects);

	return jasmine.failed;
}
~~~~

Running the example will output each test with a pass or fail as well as total test statistics.

<pre>
an example
 ✓ should be able to pass
 ✗ should be able to fail: expected example_fail(&example)
 ! should be able to ignore

jasmine: 1 passed, 1 failed, 1 ignored, 2 expects
</pre>
