include ../../../../src/Makefile.incl
# Makefile for directory ./org/apache/xml
#
# This makefile depends on the following environment variables
# already being defined:
#
#   JAVAC   Java compiler (with options)
#   RM      Host delete file command (with options)
#
# In addition, the CLASSPATH environment variable must
# include the absolute path of the base source directory.

TARGETS=

all: dirs compile

dirs:
	${MAKE} -C serialize

compile: ${TARGETS}

.SUFFIXES:

.SUFFIXES: .class .java

.java.class:
	${JAVAC} $<

	touch ../../../../src/classfiles_updated

clean:
	${MAKE} -C serialize clean

