CC = g++
CFLAGS = -g

all: smoketest regressiontest negativetest utf8reader

smoketest:
	cd test_drivers/smoke_test &&  $(MAKE) $@

regressiontest:
	cd test_drivers/regression_tests &&  $(MAKE) $@

negativetest:
	cd test_drivers/negative &&  $(MAKE) $@

utf8reader:
	cd test_drivers/utf8reader &&  $(MAKE) $@
