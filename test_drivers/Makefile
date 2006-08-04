CC = g++
CFLAGS = -g

all: smoketest regressiontest negativetest utf8reader

smoketest:
	cd smoke_test &&  $(MAKE) $@

regressiontest:
	cd regression_tests &&  $(MAKE) $@

negativetest:
	cd negative &&  $(MAKE) $@

utf8reader:
	cd utf8reader &&  $(MAKE) $@
