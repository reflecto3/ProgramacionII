<<<<<<< HEAD
# Makefile v3.0.0 2022-Dec-25 Jeisson Hidalgo-Cespedes ECCI-UCR CC-BY 4.0

# Compiler and tool flags
CC=gcc
XC=g++
JC=javac
DEFS=
CSTD=-std=c17
XSTD=-std=c++17
FLAG=
FLAGS=$(strip -Wall -Wextra $(FLAG) $(DEFS))
FLAGC=$(FLAGS) $(CSTD)
FLAGX=$(FLAGS) $(XSTD)
LIBS=
DIFF=icdiff --no-headers
LINTF=-build/header_guard,-build/include_subdir,-runtime/int
LINTC=$(LINTF),-readability/casting
LINTX=$(LINTF),-build/c++11,-runtime/references
ARGS=

# Directories
RSC=assets
BIN=bin
BUILD=build
DOC=doc
SRC=src
TESTS=tests
=======
# Makefile v3.5.0 2023-Oct-23 Jeisson Hidalgo-Cespedes ECCI-UCR CC-BY 4.0

# VAR=value  ## Overrides a variable, e.g CC=mpicc DEFS=-DGUI. See helpvars
CC=gcc#= C compiler
XC=g++#= C++ compiler
JC=javac
DEFS=#= Preprocessor symbols, e.g: DEFS=-DVERBOSE
CSTD=-std=c17#= Force compliance to a C standard, e.g: c11|gnu11|c17|c2x
XSTD=-std=c++17#= Force compliance to a C++ standard, e.g: c++11|gnu++11|c++17|c++2x
FLAG=#= Compiler flags for both C and C++
FLAGS=$(strip -Wall -Wextra $(FLAG) $(DEFS))
FLAGC=$(strip $(FLAGS) $(CSTD))
FLAGX=$(strip $(FLAGS) $(XSTD))
FLAGJ=$(strip $(FLAG))
LIBS=#= Libraries to be linked, e.g: LIBS=-lm
LINTF=-build/header_guard,-build/include_subdir,-runtime/int
LINTC=$(LINTF),-readability/casting
LINTX=$(LINTF),-build/c++11,-runtime/references
ARGS=#= Execution arguments, e.g: 'ARGS=100 "a text"'
ARGSJR=-ea
GITUSER=$(shell getent passwd "$USER" | cut -d: -f5 | cut -d, -f1)#= Your full name e.g: "Ana Soto"
GITEMAIL=
GITTIME=10800#= Store git password in memory for this amount of seconds (default 3h)
HOST=$(subst .local,,$(shell hostname))

# Directories
RSC=assets#= Dir for assets: images, sounds... to be included with executable
BIN=bin#= Dir where executable files are generated
BUILD=build#= Dir for object files (.o|.class)
DOC=doc#= Dir where documentation output will be generated
SRC=src#= Dir containing source code to compile, e.g: DIR=experiment
TESTS=tests#= Dir where test cases are stored, e.g: TESTS=large
>>>>>>> 0a1eb9e (version del desktop de la carpeta)

# If src/ dir does not exist, use current directory .
ifeq "$(wildcard $(SRC) )" ""
	SRC=.
endif

# Files
DIRS=$(shell find -L $(SRC) -type d)
ASSETS=$(wildcard $(RSC)/)
APPNAME=$(shell basename $(shell pwd))
HEADERC=$(wildcard $(DIRS:%=%/*.h))
HEADERX=$(wildcard $(DIRS:%=%/*.hpp))
SOURCEC=$(wildcard $(DIRS:%=%/*.c))
SOURCEX=$(wildcard $(DIRS:%=%/*.cpp))
SOURCEJ=$(wildcard $(DIRS:%=%/*.java))
SOURCEP=$(wildcard $(DIRS:%=%/*.py))
INPUTFC=$(strip $(HEADERC) $(SOURCEC))
INPUTFX=$(strip $(HEADERX) $(SOURCEX))
INPUTCX=$(strip $(INPUTFC) $(INPUTFX))
OBJECTC=$(SOURCEC:$(SRC)/%.c=$(BUILD)/%.o)
OBJECTX=$(SOURCEX:$(SRC)/%.cpp=$(BUILD)/%.o)
OBJECTJ=$(SOURCEJ:$(SRC)/%.java=$(BUILD)/%.class)
OBJECTS=$(strip $(OBJECTC) $(OBJECTX))
TESTINP=$(wildcard $(TESTS)/input*.txt)
INCLUDE=$(DIRS:%=-I%)
DEPENDS=$(OBJECTS:%.o=%.d)
REMOVES=$(BIN)/ $(BUILD)/ $(DOC)/
<<<<<<< HEAD
IGNORES=$(REMOVES) *.pyc .vscode
=======
IGNORES=$(REMOVES) *.pyc .DS_Store .vscode
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
EXEFILE=$(BIN)/$(APPNAME)
MAINCLS=$(shell grep -lE 'static\s+void\s+main\b' $(SRC)/*.java | xargs basename -s .java)
MAKFILE:=$(lastword $(MAKEFILE_LIST))
MAKSITE=http://jeisson.work
LD=$(if $(SOURCEX),$(XC),$(CC))
ifneq ($(OBJECTS),)
	TARGETS+=$(EXEFILE)
	TESTOUT+=$(TESTINP:$(TESTS)/input%.txt=exe/output%.txt)
	OUTPUTX+=$(TESTINP:$(TESTS)/input%.txt=cppout/output%.txt)
	EXEARGS+=$(strip $(EXEFILE) $(ARGS))
	DOCTARG+=cppdoc
endif
ifneq ($(OBJECTJ),)
	TARGETS+=$(EXEFILE).jar
	TESTOUT+=$(TESTINP:$(TESTS)/input%.txt=jar/output%.txt)
	OUTPUTJ+=$(TESTINP:$(TESTS)/input%.txt=javaout/output%.txt)
<<<<<<< HEAD
	JARARGS=$(strip java -jar $(EXEFILE).jar $(ARGS))
=======
	JARARGS+=$(strip java $(ARGSJR) -jar $(EXEFILE).jar $(ARGS))
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
	DOCTARG+=javadoc
endif
ifneq ($(SOURCEP),)
	TESTOUT+=$(TESTINP:$(TESTS)/input%.txt=py3/output%.txt)
	OUTPUTP+=$(TESTINP:$(TESTS)/input%.txt=pyout/output%.txt)
	PY3ARGS=$(strip python3 $(SOURCEP) $(ARGS))
	DOCTARG+=pydoc
endif

# Parameterized targets
ifneq ($(tc),)
TSTINP=$(shell seq -f $(TESTS)/input%03g.txt $(tc))
TSTOUT=$(shell seq -f $(TESTS)/output%03g.txt $(tc))
default: tc
else  # tc
ifneq ($(project),)
PROJECT=.gitignore readme.adoc_
<<<<<<< HEAD
PROJECT+=$(if $(findstring c,$(project)),src/solution.c_)
PROJECT+=$(if $(findstring cpp,$(project)),src/solution.cpp_)
PROJECT+=$(if $(findstring py,$(project)),src/solution.py_)
PROJECT+=$(if $(findstring java,$(project)),src/Solution.java_ src/package-info.java_)
PROJECT+=$(if $(findstring design,$(project)),design/readme.adoc_ design/solution.pseudo_)
=======
PROJECT+=$(if $(filter c,$(project)),src/solution.c_)
PROJECT+=$(if $(filter cpp,$(project)),src/solution.cpp_)
PROJECT+=$(if $(filter py,$(project)),src/solution.py_)
PROJECT+=$(if $(filter java,$(project)),src/Solution.java_ src/package-info.java_)
PROJECT+=$(if $(filter design,$(project)),design/readme.adoc_ design/solution.pseudo_)
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
default: project
else  # project
default: debug
endif
endif

# Targets
<<<<<<< HEAD
all: debug test lint doc
debug: FLAG += -g
debug: $(TARGETS)
release: FLAGS += -O3 -DNDEBUG
release: $(TARGETS)
asan: FLAGS += -fsanitize=address -fno-omit-frame-pointer
asan: debug
msan: FLAGS += -fsanitize=memory
msan: CC = clang
msan: XC = clang++
msan: debug
tsan: FLAGS += -fsanitize=thread
tsan: debug
ubsan: FLAGS += -fsanitize=undefined
ubsan: debug
=======
.PHONY: all asan debug helgrind memcheck msan release tsan ubsan
.PHONY: clean gitconfig help instdeps lint project run tc test update version
all: debug test lint doc  ## Run targets: test lint doc
debug: FLAGS += -g  ## Build an executable for debugging [default]
release: FLAGS += -O3 -DNDEBUG  ## Build an optimized executable
debug release: $(TARGETS)
asan: FLAGS += -fsanitize=address -fno-omit-frame-pointer  ## Build for detecting memory leaks and invalid accesses
msan: FLAGS += -fsanitize=memory  ## Build for detecting uninitialized memory usage
msan: CC = clang
msan: XC = clang++
tsan: FLAGS += -fsanitize=thread  ## Build for detecting thread errors, e.g race conditions
ubsan: FLAGS += -fsanitize=undefined  ## Build for detecting undefined behavior
asan msan tsan ubsan: debug
>>>>>>> 0a1eb9e (version del desktop de la carpeta)

-include *.mk $(DEPENDS)
.SECONDEXPANSION:

# C/C++ Linker call
$(EXEFILE): $(OBJECTS) | $$(@D)/.
<<<<<<< HEAD
	$(LD) $(FLAGS) $(INCLUDE) $^ -o $@ $(LIBS)
=======
	$(LD) $(strip $(FLAGS)) $(INCLUDE) $^ -o $@ $(LIBS)
>>>>>>> 0a1eb9e (version del desktop de la carpeta)

# Compile C source file
$(BUILD)/%.o: $(SRC)/%.c | $$(@D)/.
	$(CC) -c $(FLAGC) $(INCLUDE) -MMD $< -o $@

# Compile C++ source file
$(BUILD)/%.o: $(SRC)/%.cpp | $$(@D)/.
	$(XC) -c $(FLAGX) $(INCLUDE) -MMD $< -o $@

# Java Linker call. TODO(jhc): fallible main class detection
%.jar: $(OBJECTJ) | $$(@D)/.	
	jar cfe $@ $(MAINCLS) -C $(BUILD) .
ifneq ($(ASSETS),)
	jar uf $@ -C $(ASSETS) .
endif

# Compile Java source file
.PRECIOUS: $(BUILD)/%.class
$(BUILD)/%.class: $(SRC)/%.java | $$(@D)/.
<<<<<<< HEAD
	$(strip $(JC) -classpath $(SRC) $(FLAG)) $< -d $(BUILD)
=======
	$(strip $(JC) -classpath $(SRC) $(FLAGJ)) $< -d $(BUILD)
>>>>>>> 0a1eb9e (version del desktop de la carpeta)

# Create a subdirectory if not exists
.PRECIOUS: %/.
%/.:
	mkdir -p $(dir $@)

<<<<<<< HEAD
# Test cases
.PHONY: test doc lint run memcheck helgrind clean instdeps update tc project
test: SHELL:=/bin/bash
test: $(TARGETS) $(TESTOUT)

=======
# test:  ## Run executable against test cases in folder tests/
test: SHELL:=/bin/bash
test: $(TARGETS) $(TESTOUT)

DIFF=icdiff --no-headers
ifeq (, $(shell which $(firstword $(DIFF))))
	DIFF=diff
endif # icdiff not installed, use diff

>>>>>>> 0a1eb9e (version del desktop de la carpeta)
# TODO(any): Remove redundancy
exe/output%.txt: $(TESTS)/input%.txt $(TESTS)/output%.txt
	-$(DIFF) $(word 2,$^) <($(EXEARGS) < $<) ||:

jar/output%.txt: $(TESTS)/input%.txt $(TESTS)/output%.txt
	-$(DIFF) $(word 2,$^) <($(JARARGS) < $<) ||:

py3/output%.txt: $(TESTS)/input%.txt $(TESTS)/output%.txt
	-$(DIFF) $(word 2,$^) <($(PY3ARGS) < $<) ||:

<<<<<<< HEAD
# Test case output files
=======
# <L>out  ## Generate test case output using language L: cpp|java|py
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
cppout: $(TARGETS) $(OUTPUTX)
cppout/output%.txt: $(TESTS)/input%.txt $(TESTS)/output%.txt
	$(EXEARGS) < $< > $(word 2,$^)

javaout: $(TARGETS) $(OUTPUTJ)
javaout/output%.txt: $(TESTS)/input%.txt $(TESTS)/output%.txt
	$(JARARGS) < $< > $(word 2,$^)

pyout: $(TARGETS) $(OUTPUTP)
pyout/output%.txt: $(TESTS)/input%.txt $(TESTS)/output%.txt
	$(PY3ARGS) < $< > $(word 2,$^)

<<<<<<< HEAD
# Generate empty test cases
=======
# tc=N  ## Generates N empty test cases in tests/
.PRECIOUS: $(TESTS)/%.txt
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
tc: $(TSTINP) $(TSTOUT)
$(TESTS)/%.txt: | $$(@D)/.
	touch $@

<<<<<<< HEAD
# Generate empty project
=======
# project=L  ## Create files for languages L: c|cpp|java|py|design
DOWN=wget -qO -
ifeq (, $(shell which $(firstword $(DOWN))))
	DOWN=curl -s
endif # wget not installed, try cURL

>>>>>>> 0a1eb9e (version del desktop de la carpeta)
project: $(PROJECT)
	@$(MAKE) tc=1

%_: | $$(@D)/.
<<<<<<< HEAD
	curl -s $(MAKSITE)/misc/project/$* > $*

# Documentation
doc: $(DOCTARG)
cppdoc: Doxyfile $(INPUTCX)
	doxygen -q
=======
	@test -f $* || ($(DOWN) $(MAKSITE)/misc/project/$* > $* && echo $*)

.PHONY: doc  ## Generate documentation from sources
doc: $(DOCTARG)
cppdoc: Doxyfile $(INPUTCX)
	doxygen
>>>>>>> 0a1eb9e (version del desktop de la carpeta)

javadoc: $(SOURCEJ) | $(DOC)/java/.
	javadoc -quiet $(SOURCEJ) -d $(DOC)/java

pydoc: $(SOURCEP) | $(DOC)/python/.
	pydoc -w $(SOURCEP)
	mv *.html $(DOC)/python

Doxyfile:
<<<<<<< HEAD
	-doxygen -g -s
=======
	-doxygen -g -s > /dev/null
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
	sed -i.bak -E 's/(OUTPUT_DIRECTORY *)=/\1= $(DOC)/' $@
	sed -i.bak -E 's/(INPUT *)=/\1= $(SRC)/' $@
	sed -i.bak -E 's/(RECURSIVE *)= NO/\1= YES/' $@
	sed -i.bak -E 's/(EXTRACT_ALL *)= NO/\1= YES/' $@
<<<<<<< HEAD
	rm -f $@.bak

# Code style
lint:
=======
	sed -i.bak -E 's/(QUIET *)= NO/\1= YES/' $@
	rm -f $@.bak

lint:  ## Check code style conformance using Cpplint
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
ifneq ($(INPUTFC),)
	-cpplint --filter=$(LINTC) $(INPUTFC)
endif
ifneq ($(INPUTFX),)
	-cpplint --filter=$(LINTX) $(INPUTFX)
endif
ifneq ($(SOURCEJ),)
	-checkstyle -c /google_checks.xml $(SOURCEJ)
	-checkstyle -c /sun_checks.xml $(SOURCEJ)
endif
ifneq ($(SOURCEP),)
	-pylint -sn $(SOURCEP)
endif

<<<<<<< HEAD
run: $(TARGETS)
=======
run: $(TARGETS)  ## Run executable using ARGS value as arguments
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
ifneq ($(EXEARGS),)
	$(EXEARGS)
endif
ifneq ($(JARARGS),)
	$(JARARGS)
endif
ifneq ($(PY3ARGS),)
	$(PY3ARGS)
endif

<<<<<<< HEAD
memcheck: $(EXEFILE)
	valgrind --tool=memcheck $(EXEARGS)

helgrind: $(EXEFILE)
	valgrind --quiet --tool=helgrind $(EXEARGS)

.gitignore:
	echo $(IGNORES) | tr " " "\n" > .gitignore

clean:
=======
memcheck: $(EXEFILE)  ## Run executable for detecting memory errors with Valgrind
	valgrind -q -s --sigill-diagnostics=yes --leak-check=full $(EXEARGS)

helgrind: $(EXEFILE)  ## Run executable for detecting thread errors with Valgrind
	valgrind -q -s --sigill-diagnostics=yes --tool=helgrind $(EXEARGS)

.gitignore:  ## Generate a .gitignore file
	echo $(IGNORES) | tr " " "\n" > .gitignore

gitconfig:  ## Configure name/email. Cache password in memory for some time
	git config --global user.name "$(GITUSER)"
	git config --global user.email $(GITEMAIL)
	git config credential.helper "cache --timeout=$(GITTIME)"
	ssh-keygen -t ed25519 -C "$(HOST)" && cat ~/.ssh/id_ed25519.pub

#.NOTPARALLEL: clean
clean:  ## Remove generated directories and files
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
	rm -rf $(REMOVES)
ifneq ($(SOURCEP),)
	find $(SRC) -name '*.pyc' -exec rm -f {} \;
endif

<<<<<<< HEAD
# Install dependencies (Debian)
instdeps:
	sudo apt install build-essential clang valgrind icdiff doxygen graphviz \
	python3-pip python3-gpg openjdk-17-jdk checkstyle && sudo pip3 install cpplint

update:
	curl -s $(MAKSITE)/Makefile > $(MAKFILE)

help:
	@echo "Usage make [-jN] [VAR=value] [target]"
	@echo "  -jN        Compile N files simultaneously [N=1]"
	@echo "  VAR=value  Overrides a variable, e.g CC=mpicc DEFS=-DGUI. See below"
	@echo "  all        Run targets: test lint doc"
	@echo "  asan       Build for detecting memory leaks and invalid accesses"
	@echo "  clean      Remove generated directories and files"
	@echo "  debug      Build an executable for debugging [default]"
	@echo "  doc        Generate documentation from sources"
	@echo "  .gitignore Generate a .gitignore file"
	@echo "  helgrind   Run executable for detecting thread errors with Valgrind"
	@echo "  instdeps   Install needed packages on Debian-based distributions"
	@echo "  lint       Check code style conformance using Cpplint"
	@echo "  memcheck   Run executable for detecting memory errors with Valgrind"
	@echo "  msan       Build for detecting uninitialized memory usage"
	@echo "  <L>out     Generate test case output using language L: cpp|java|py"
	@echo "  project=L  Create files for languages L: c|cpp|java|py|design"
	@echo "  release    Build an optimized executable"
	@echo "  run        Run executable using ARGS value as arguments"
	@echo "  test       Run executable against test cases in folder tests/"
	@echo "  tc=N       Generates N empty test cases in tests/"
	@echo "  tsan       Build for detecting thread errors, e.g race conditions"
	@echo "  ubsan      Build for detecting undefined behavior"
	@echo "  update     Update this Makefile to latest version"
	@echo "Variables:"
	@echo "  CC: C compiler. XC: C++ compiler. C|XSTD: Force a C/C++ standard"
	@echo "  DEFS: preprocessor symbols. FLAG: compiler flags"
	@echo "  LIBS: libraries to be linked"
	@echo "  ARGS: execution arguments"
	@echo "  Input directories: SRC, TESTS. Output directories: BIN, BUILD, DOC"
=======
# Install dependencies for Debian or RedHat based distros (pacman pending)
DEPS=clang valgrind doxygen pipx python3-gpg checkstyle
INSTDEPS=sudo apt install build-essential openjdk-17-jdk
PIP=pipx
ifeq (, $(shell which apt))
	INSTDEPS=sudo dnf groupinstall 'Development Tools' && sudo dnf install java-17-openjdk
endif # not an apt-based distribution, use dnf

instdeps:  ## Install needed packages on Debian/RedHat-based distributions
	$(INSTDEPS) $(DEPS) && $(PIP) ensurepath && $(PIP) install icdiff && $(PIP) install cpplint

update:  ## Update this Makefile to latest version"
	$(DOWN) $(MAKSITE)/Makefile > $(MAKFILE)

version:  ## Show this Makefile version
	@head -1 $(MAKFILE)

help:  ## Shows this help
	@echo "Usage make [-jN] [VAR=value] [targets]"
	@echo "  -jN        Compile N files simultaneously [N=1]"
	@grep -E '^\S.*##' $(MAKFILE) | perl -pe 's/^(?:\.PHONY: |# )?([\.\w=<>]+):?.*  ## (.+)/  \1	\2/' | expand -t13 | sort

helpvars:  ## List common variables to override
	@grep -E '^\S.*#=' $(MAKFILE) | perl -pe 's/^(\w+).*#= (.+)/  \1	\2/' | expand -t13 | sort
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
